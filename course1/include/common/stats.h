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
 * @brief This file contains the decleration of fucntions use in the stats.c
 *
 * @author Zill Ullah Khan
 * @date 09-02-2021
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief Printing each elements of the array
 *
 * This function iterates through all the array
 * elements and print the position and value
 
 * @param unsigned char arrray pointer
 * @param total array size
 */
void print_array(unsigned char * ptr, int count);

/**
 * @brief Sorting each elements of the array
 *
 * This function iterates through all the array
 * elements and sorts each elements from largest
 * to smallest 
 
 * @param unsigned char arrray pointer
 * @param total array size
 */
void array_sort(unsigned char * ptr, int count);

/**
 * @brief Printing statistics of the array
 *
 * This function just prints the statistics
 * calculated from max, min , mean and median
 * function.
 
 * @param integer maximum value of array
 * @param integer minimum value of array
 * @param integer mean value of array
 * @param integer median value of array
 */
void print_stats(int min, int max, int mean, float median);

/**
 * @brief Find the maximum value from the array
 *
 * This function iterates through all the array
 * and find the maximum value present in that array
 
 * @param unsigned char arrray pointer
 * @param total array size
 * @return maximum value integer
 */
 int find_max(unsigned char * ptr, int count);
 
 /**
 * @brief Find the minimum value from the array
 *
 * This function iterates through all the array
 * and find the minimum value present in that array
 
 * @param unsigned char arrray pointer
 * @param total array size
  * @return minimum value integer
 */
 int find_min(unsigned char * ptr, int count);
 
  /**
 * @brief Find the mean value from the array
 *
 * This function iterates through all the array
 * and find the mean value present in that array
 
 * @param unsigned char arrray pointer
 * @param total array size
  * @return mean value integer
 */
 int find_mean(unsigned char * ptr, int count);
 
   /**
 * @brief Find the median value from the array
 *
 * This function iterates through all the sorted array
 * and find the median value present in that array
 
 * @param unsigned char arrray array
 * @param total array size
  * @return median value float
 */
  float find_median(unsigned char ptr[], int count);

#endif /* __STATS_H__ */
