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
 * @file stats.c 
 * @brief Calculate and print the statistics of the array
 *
 * Calculate and print in the terminal the maximum, minimum, mean and media
 * of the array values.
 *
 * @author David Alatorre
 * @date 9/10/2019
 *
 */



#include <stdio.h>
#include "platform.h"
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

int statistics() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */
	print_statistics(test, SIZE);
   return 0;
}

/* Add other Implementation File Code Here */
void print_statistics(unsigned char array[], unsigned int length) {
	
	print_array(array, length);
	sort_array(array, length);

	PRINTF("\n-----------------Statistics:-------------------\n");
	PRINTF(" - Median: %d\n", find_median(array, length));
	PRINTF(" - Mean: %d\n", find_mean(array, length));
	PRINTF(" - Maximum: %d\n", find_maximum(array, length));
	PRINTF(" - Minimum: %d\n", find_minimum(array, length));
	PRINTF("\n------------------------------------------------\n");
}

void print_array(unsigned char array[], unsigned int length) {
#ifdef VERBOSE
	PRINTF("\n-------------- Print Array -----------------\n");
	int i;
	int count = 0;
	for(i = 0; i < length; i++) {
		PRINTF("A[%d]: %d \t", i, array[i]);
		count++;
		if(count > 4) {
			PRINTF("\n");
			count = 0;
		}
	}
	PRINTF("\n\n");
#endif
}

int find_median(unsigned char array[], unsigned int length) {
	int medianIndex = length / 2;


	int i = 0;
	int auxIndex = 0;
	unsigned char auxValue;
    /* Sort the Array */
	for(i = 1; i < length; i++) {
		auxIndex = i;
		while(auxIndex > 0) {
			if(array[auxIndex] > array[auxIndex - 1]) {
				/*change the values*/
				auxValue = array[auxIndex - 1];
				array[auxIndex - 1] = array[auxIndex];
				array[auxIndex] = auxValue;
			}
			auxIndex--;
		}
	}	

	/* afther sort the number take the middle number */
	if(length % 2 != 0) {
		/*if is odd number take the middle number*/
		return array[medianIndex];
	} else {
		/*if is an even number, calculated the mean of the two middlemost numbers*/
		unsigned char meanArray[2];
		meanArray[0] = array[medianIndex - 1];
		meanArray[1] = array[medianIndex];
		return find_mean(meanArray, 2);
	}
}

int find_mean(unsigned char array[], unsigned int length) {
    int adding = 0;  /*acumulation of all the values*/
	int i = 0;

	/* add all rhe number */
	for(i = 0; i < length; i++) {
		adding += array[i];
	}
	/* divide by the total of numbers */
	return adding/length;
}

int find_maximum(unsigned char array[], unsigned int length) {

	int maxValue = array[0];
	int i;
	for(i = 1; i < length; i++) {
		/*if the value is greater */
		if(array[i] > array[i - 1]) {
			maxValue = array[i];
		}
	}
	return maxValue;	
}

int find_minimum(unsigned char array[], unsigned int length) {

	int minValue = array[0];
	int i;
	for(i = 1; i < length; i++) {
		/*if the value is less*/
		if(array[i] < array[i - 1]) {
			minValue = array[i];
		}
	}	
	return minValue;
}

void sort_array(unsigned char array[], unsigned int length) {
	int i = 0;
	int auxIndex = 0;
	unsigned char auxValue;

     /* Sort the Array */
	for(i = 1; i < length; i++) {
		auxIndex = i;
		while(auxIndex > 0) {
			if(array[auxIndex] > array[auxIndex - 1]) {
				/*changes the values*/
				auxValue = array[auxIndex - 1];
				array[auxIndex - 1] = array[auxIndex];
				array[auxIndex] = auxValue;
			}
			auxIndex--;
		}
	}	

	print_array(array, length);
}

