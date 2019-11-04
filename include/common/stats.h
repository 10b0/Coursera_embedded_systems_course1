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
 * @file stats.h 
 * @brief The header file from the stats.c file
 *
 * Here you can find the functions prototypes and their descriptions
 *
 * @author David Alatorre
 * @date 9/10/2019
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

int statistics();

/**
 * @brief Print the statistics in the terminal
 *
 * Print all the statistic of the array including
 * minimum, maximum, mean, and median.
 *
 * @param array The unsigned char array to print
 * @param length The length of the array
 */
void print_statistics(unsigned char array[], unsigned int length);

/**
 * @brief Print the array in the terminal
 *
 * Recive the array and print it in the terminal
 *
 * @param array The unsigned char array to print
 * @param length The length of the array
 */
void print_array(unsigned char array[], unsigned int length);

/**
 * @brief <Add Brief Description of Function Here>
 *
 * <Add Extended Description Here>
 *
 * @param array The unsigned char array to print
 * @param length The length of the array
 *
 * @return The median value
 */
int find_median(unsigned char array[], unsigned int length);

/**
 * @brief <Add Brief Description of Function Here>
 *
 * <Add Extended Description Here>
 *
 * @param array The unsigned char array to print
 * @param length The length of the array
 *
 * @return The mean value
 */
int find_mean(unsigned char array[], unsigned int length);


/**
 * @brief <Add Brief Description of Function Here>
 *
 * <Add Extended Description Here>
 *
 * @param array The unsigned char array to print
 * @param length The length of the array
 *
 * @return The maximum value
 */
int find_maximum(unsigned char array[], unsigned int lenght);

/**
 * @brief <Add Brief Description of Function Here>
 *
 * <Add Extended Description Here>
 *
 * @param array The unsigned char array to print
 * @param length The length of the array
 *
 * @return The minimum value
 */
int find_minimum(unsigned char array[], unsigned int length);


/**
 * @brief <Add Brief Description of Function Here>
 *
 * <Add Extended Description Here>
 *
 * @param array The unsigned char array to print
 * @param length The length of the array
 */
void sort_array(unsigned char array[], unsigned int length);


#endif /* __STATS_H__ */
