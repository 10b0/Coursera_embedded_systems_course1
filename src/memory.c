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
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include <stdint.h>
#include <stdlib.h>
#include "memory.h"

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}


/* ------------------------------------------------------ */
/* Start the functions for the course 1 (last assessment) */
/* ------------------------------------------------------ */

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length) {
	/* new pointer and copy the original to make for not lose the values when overlap */
	uint8_t * aux = (uint8_t*) reserve_words(length);
	my_memcopy(src, aux, length);

	int i;
	for(i = 0; i < length; i++) {
		*dst = *(aux + i); /* copy the value to the destination pointer */
		dst++;
	}
	free_words((uint32_t*) aux); /* free the new pointer */
	return dst;
}

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length) {
	int i;
	for(i = 0; i < length; i++) {
		*(dst + i) = *(src + i);  /* copy the value to the destination pointer */
	}
	return dst;
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value) {
	int i;
	for(i = 0; i < length; i++) {
		*src = value;  /* set to the new value */
		src++;
	}
	return src;
}

uint8_t * my_memzero(uint8_t * src, size_t length) {
	int i;
	for(i = 0; i < length; i++) {
		*src = 0; /* set to 0 */
		src++;
	}	
	return src;
}

uint8_t * my_reverse(uint8_t * src, size_t length) {
	/* new pointer and copy the original to make que changes */
	uint8_t * aux = (uint8_t*) reserve_words(length);
    my_memcopy(src, aux, length);

	int i;
	for(i = length - 1; i >= 0; i--) {
		*src = *(aux + i);
		src++;
	}
    free_words((uint32_t*) aux);  /* free the new pointer */
	return src;
}

uint32_t * reserve_words(size_t length) {
	uint32_t * ptr = malloc(sizeof(uint32_t) * length);
	return ptr;
}

void free_words(uint32_t * src) {
	if(src) {
		free(src);
	}
}

