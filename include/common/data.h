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
 * @file data.h
 * @brief Convert integer to ASCII and their base and vice versa 
 *
 * This header file provides an abstraction of Convert integer 
 * to ASCII and their base and vice versa function calls. 
 *
 * @author David Alatorre
 * @date November 5 2019
 *
 */

#ifndef __DATA_H__
#define __DATA_H__

#define BASE_16 (16)
#define BASE_10 (10)
#define BASE_8  (8)
#define BASE_2  (2)

/**
 * @brief Convert integer to ASCII and their base 
 *
 * Given a number and convert to ASCII whit the pointer, and convert the base number
 *
 * @param data - The number to comvert
 * @param ptr - Pointer to the number converted to ASCII
 * @param base - base to convert the number
 *
 * @return The length of the ASCII number including null end of the string.
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief Convert ASCII number to integer
 *
 * Given a pointer of ASCII numbers and convert integer, and change the base number
 *
 * @param ptr - pointer to the ASCII number to convert
 * @param digits - the length of the ASCII number including the null end of the string
 * @param base - base to convert the number
 *
 * @return The number converted to integer and their base.
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif