/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file data.c 
 * @brief This file is to be used to course 1 final assessment.
 *
 * @author David Alatorre
 * @date November 5, 2019
 *
 */


#include <math.h>
#include "data.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) {

    int length = 0;           /* the length of the ASCII value with the sign and null (end of string) value */
    uint8_t negativeNum = 0;  /* flag if is negative value */

    /* if is negative value */
    if(data < 0) {
    	data *= -1;
    	negativeNum = 1; 
	}

	/* while to convert the number base and then to ASCII */
	while(data != 0) {
		int32_t remainder = data % base;
		*(ptr + length) = (uint8_t) remainder + 48;  /* add 48 to convert to ASCII */
		length++;
		data /= base;
	}

    /* if is negative add the negative sign */
	if(negativeNum) {
		*(ptr + length) = (uint8_t) '-';
		length++;
	}

	/* add the null value end of the string */
	*(ptr + length) = (uint8_t) '\0';
	length++;

    /* return the length of the ASCII string */
	return length;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) {
	int i;
	uint8_t negativeNum = 0;  /* flag if is negative value */
	int32_t result = 0;       /* the value in integer */

	for(i = 0; i < digits; i++) {
		/* set the flag if is negative value */
		if(*(ptr + i) == '-') {
			negativeNum = 1;

	    /* if is not the null value */
	    /* convert to integer and change the base number */
		} else if(*(ptr + i) != '\0') {
			*(ptr + i) = (*(ptr + i) - 48); /* substract 48 to now the integer value */
			result += (*(ptr + i) * pow(base, i));
		}
	}

    /* if is negative change to negative sign */
	if(negativeNum) {
		result *= -1;
	}

	/* return the result value */
	return result;
}
