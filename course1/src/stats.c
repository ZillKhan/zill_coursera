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
#include "platform.h"

#define SIZE (40)

/*
void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};
  

  int mean,max,min;
  float median;
  
  printf("The unsorted Array is \n"); 
  printf("==================== \n");
  print_array(test,SIZE); 
  printf("======================\n");

  array_sort(test,SIZE);
  printf("The sorted Array from Largest to Smaller is \n"); 
  printf("==================== \n");
  print_array(test,SIZE); 
  printf("======================\n");
  
  max = find_max(test,SIZE);
  min = find_min(test,SIZE);
  mean = find_mean(test,SIZE);
  median = find_median(test,SIZE);
  print_stats(min,max,mean,median);
  
}
*/

void print_stats(int min, int max, int mean, float median){
  
  printf("The Array statistics are \n"); 
  printf("==================== \n");
  printf("--> Min value is : %i \n",min);
  printf("==================== \n");
  printf("--> Max value is : %i \n",max);
  printf("==================== \n");
  printf("--> Mean value is : %i \n",mean);
  printf("==================== \n");
  printf("--> Median value is : %f \n",median);
  printf("==================== \n");  
  
}

void print_array(unsigned char * ptr, int count){
	int i = 0;
	#if !defined (VERBOSE) && defined (HOST)
	#undef PRINTF
	#define PRINTF(...)
	#endif
	while (i < count){
		PRINTF("Array %ith Element is %i \n",i+1,ptr[i]);
		i++;
	}
	#if defined (VERBOS) && defined (HOST)
	#undef PRINTF
	#define PRINTF(...) printf(__VA_ARGS__)
	#endif

}

void array_sort(unsigned char * ptr, int count){
	int i, j, swap = 0;

	for (i=0 ; i<count; i++){

		for(j=0 ; j<count-1 ; j++){
			if(ptr[j] < ptr[j+1]){

					swap = ptr[j];
					ptr[j] = ptr[j+1];
					ptr[j+1] = swap;
			}
		}
	}

	
}

float find_median (unsigned char ptr[],int count){
	float med;

	if(count%2 == 0){
		med = (ptr[(count-1)/2]+ptr[count/2])/2;
	}
	else{
		med = ptr[count/2];
	}
	return med;
}

int find_mean(unsigned char * ptr, int count){
	int i = 0;
	int sum = 0;
	while(i<count){
		sum += ptr[i];
		i++;
	}
	return (sum/count);
}

int find_max(unsigned char * ptr, int count){
	int i = 0;
	int max;
	while (i < count){
	
		if (i == 0){
			max = ptr[i];
		}
		if (ptr[i] > max){
			max = ptr[i];
		}
		i++;
	}
	return max;
}

int find_min(unsigned char * ptr, int count){
	int i = 0;
	int min;
	while (i < count){
		if (i == 0){
			min = ptr[i];
		}
		if (ptr[i] < min){
			min = ptr[i];
		}
		i++;
	}
	return min;
}

