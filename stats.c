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
 * @brief 	This file will contain function that can analyze an array of unsigned char data items
 * 		and report analytics on max,min, mean and meadium of the dataset.
 *
 * This code find the statistics analysis of the array that include sorting the array from largest 
 * to smallest. Moreover, the maximum, minimium, mean and median values of the array is also analyze
 * using this file.
 *
 * @author Zill Ullah Khan
 * @date 09-02-2021
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  int mean,max,min;
  float median

}

void print_stats(int min, int max, int mean, float median){
  
  
}

void print_array(unsigned char * ptr, int count){

}

void array_sort(unsigned char * ptr, int count){
	
}

float find_median (unsigned char ptr[],int count){

}

int find_mean(unsigned char * ptr, int count){

}

int find_max(unsigned char * ptr, int count){

}

int find_min(unsigned char * ptr, int count){

}

