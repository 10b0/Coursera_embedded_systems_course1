#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Build system usign the GNU tools
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      PLATFORM=host or the default -> host machine (Linux Ubuntu)
#      PLATFORM=MSP432 -> ARM microcontroller, cpu=cortex-m4
#
# Platform Overrides:
#      make *.i PLATFORM=[MSP432|HOST]         -> cerated preprocessed file
#      make *.asm PLATFORM=[MSP432|HOST]       -> cerated assembly file and the dump file with assembly code
#      make *.o PLATFORM=[MSP432|HOST]         -> cerated objet file
#      make compile-all PLATFORM=[MSP432|HOST] -> cerated all the objet files
#      make build PLATFORM=[MSP432|HOST]       -> cerated final executable
#      make clean                              -> clean all the autogenerated files
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
TARGET = c1m2

# Architectures Specific Flags


# Compiler Flags and Defines
ifeq ($(PLATFORM), MSP432)
	CC = arm-none-eabi-gcc
	LINKER_FILE = ../msp432p401r.lds 
	CPU = cortex-m4
	SPECS = nosys.specs
	ARCH = thumb
	MARCH = armv7e-m
	FLOAT = hard
	MFPU = fpv4-sp-d16
	SOURCES = $(SOURCES_MSP432)

	CFLAGS = -mcpu=$(CPU) -m$(ARCH) -march=$(MARCH) -mfloat-abi=$(FLOAT) -mfpu=$(MFPU) --specs=$(SPECS)  -DMSP432 -Wall -Werror -g -O0 -std=c99
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
else
	# PLATFORM = HOST 
	#or if no platform is expecific use this as default
    CC = gcc
    SOURCES = $(SOURCES_HOST)

	CFLAGS = -DHOST -Wall -Werror -g -O0 -std=c99
	LDFLAGS = -Wl,-Map=$(TARGET).map
endif
#LD = 

CPPFLAGS := $(INCLUDES)
OBJS = $(SOURCES:.c=.o)

# Generate preprocessed file
%.i : %.c
	$(CC) -E $< $(CFLAGS) $(CPPFLAGS) -o $@


# Generate assembly file
# Using the -S command
%.asm : %.c
	$(CC) -S $< $(CFLAGS) $(CPPFLAGS) -o $@

# Using the objdump utility	
	$(CC) -c $< $(CFLAGS) $(LDFLAGS) $(CPPFLAGS)
	arm-none-eabi-objdump --disassemble $*.o > $*.dump

# Generate the object file
%.o : %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -o $@


# Generate all the objects files
.PHONY: compile-all
compile-all:
	$(CC) -c $(SOURCES) $(CFLAGS) $(LDFLAGS) $(CPPFLAGS)


# Generate final executable
.PHONY: build
build: all

.PHONY: all
all: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) $(CPPFLAGS) -o $@

# claen all the generated files
.PHONY: clean
clean:
	rm -f $(TARGET).out $(TARGET).map ./src/*.asm ./src/*.i ./src/*.o ./src/*.dump