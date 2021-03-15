/*****************************************************************************/
/**
 * @file course1.h 
 * @brief This file is to be used to course 1 final assessment.
 *
 * @author Zill Ullah Khan
 * @date 03/10/2021
 *
 */
#ifndef __COURSE1_H__
#define __COURSE1_H__

#include <stdint.h>


#define ERROR_OCCURE	(1)
#define NO_ERROR		(0)

#define MEM_SIZE  		(32)
#define MEM_SIZE1  		(8)
#define MOVE_LENGTH 	(16)
#define COUNT			(8)

int8_t test_data1();
int8_t test_data2();
int8_t test_memmove1();
int8_t test_memmove2();
int8_t test_memmove3();
int8_t test_memcopy();
int8_t test_memset();
int8_t test_reverse();
void course1(void);


#endif