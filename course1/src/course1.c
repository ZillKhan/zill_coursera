/*****************************************************************************/
/**
 * @file course1.c 
 * @brief This file is to be used to course 1 final assessment.
 *
 * @author Zill Ullah Khan
 * @date 03/10/2021
 *
 */
#include "course1.h" 
#include "platform.h" 

#include "stats.h"

#include "memory.h"   
#include "data.h"  
   
int8_t test_data1() {
  
  uint8_t * ptr;
  uint32_t digits;
  int32_t value;
  
  int32_t test = -2048;
    
  PRINTF("Function test_data1 running \n");
  ptr = (uint8_t*) reserve_words(10);

  digits = my_itoa(test,ptr,16);  
  PRINTF("Digits are = %d \n",digits);

  value = my_atoi(ptr,digits,16);
  
  #ifdef VERBOSE
  PRINTF("  Initial Value: %d\n",test);
  PRINTF("  Decimal Value: %d\n", value);
  #endif
  
  free_words((uint32_t*)ptr );

  if ( value != test )
  {
    return ERROR_OCCURE;
  }
  return NO_ERROR;
}

int8_t test_data2() {
  uint8_t * ptr;
  uint32_t digits;
  int32_t value;
  
  int32_t test = 123456;

  PRINTF("Function test_data2() running\n");
  ptr = (uint8_t*) reserve_words(10);


  digits = my_itoa( test, ptr, 10);
  PRINTF("Digits are = %d \n",digits);
  
  value = my_atoi( ptr, digits, 10);
  
  #ifdef VERBOSE
  PRINTF("  Initial Decimal number: %d\n", test);
  PRINTF("  Final Decimal number: %d\n", value);
  #endif
  
  free_words( (uint32_t*)ptr );

  if ( value != test )
  {
    return ERROR_OCCURE;
  }
  return NO_ERROR;
}

int8_t test_memmove1() {
  
  uint8_t * val;
  uint8_t * ptr1;
  uint8_t * ptr2;
  
  uint8_t i = 0;
  int8_t err = NO_ERROR;

  PRINTF("Function test_memmove1() Running \n");
  val = (uint8_t*) reserve_words( 10 );

  ptr1 = &val[0];
  ptr2 = &val[16];
  
  for( i = 0; i < MEM_SIZE; i++)
  {
    val[i] = i;
  }

  print_array(val, MEM_SIZE);
  
  my_memmove(ptr1, ptr2, MOVE_LENGTH);
  print_array(val, MEM_SIZE);

  for (i = 0; i < MOVE_LENGTH; i++)
  {
    if (val[i + MOVE_LENGTH] != i)
    {
      err = ERROR_OCCURE;
    }
  }

  free_words( (uint32_t*)val );
  return err;
}

int8_t test_memmove2() {
  uint8_t * val;
  uint8_t * ptr1;
  uint8_t * ptr2;
  
  uint8_t i = 0;
  int8_t err = NO_ERROR;

  PRINTF("Function test_memmove2() running \n");
  val = (uint8_t*) reserve_words(8);

  ptr1 = &val[0];
  ptr2 = &val[8];

  for( i = 0; i < MEM_SIZE1; i++) {
    val[i] = i;
  }

  print_array(val, MEM_SIZE1);
  
  my_memmove(ptr1, ptr2, MOVE_LENGTH);
  print_array(val, MEM_SIZE);

  for (i = 0; i < MOVE_LENGTH; i++)
  {
    if (val[i + MEM_SIZE1] != i)
    { 
      err = ERROR_OCCURE;
    }
  }

  free_words( (uint32_t*)val );
  return err;
}

int8_t test_memmove3() {
  uint8_t * val;
  uint8_t * ptr1;
  uint8_t * ptr2;
  
  uint8_t i = 0;
  int8_t err = NO_ERROR;

  PRINTF("Function test_memove3() running \n");
  val = (uint8_t*)reserve_words(8);

  ptr1 = &val[8];
  ptr2 = &val[0];

  for( i = 0; i < MEM_SIZE; i++)
  {
    val[i] = i;
  }

  print_array(val, MEM_SIZE);
  
  my_memmove(ptr1, ptr2, MOVE_LENGTH);
  print_array(val, MEM_SIZE);

  for (i = 0; i < MOVE_LENGTH; i++)
  {
    if (val[i] != (i + 8))
    {
      err = ERROR_OCCURE;
    }
  }

  free_words( (uint32_t*)val );
  return err;

}

int8_t test_memcopy() {
  uint8_t * val;
  uint8_t * ptr1;
  uint8_t * ptr2;
  
  uint8_t i = 0;
  int8_t err = NO_ERROR;

  PRINTF("Function test_memcopy() running\n");
  val = (uint8_t*) reserve_words(MEM_SIZE1);

  ptr1 = &val[0];
  ptr2 = &val[16];

  for( i = 0; i < MEM_SIZE; i++) {
    val[i] = i;
  }

  print_array(val, MEM_SIZE);
  
  my_memcopy(ptr1, ptr2, MOVE_LENGTH);
  print_array(val, MEM_SIZE);

  for (i = 0; i < MOVE_LENGTH; i++)
  {
    if (val[i+16] != i)
    {
      err = ERROR_OCCURE;
    }
  }

  free_words( (uint32_t*)val );
  return err;
}

int8_t test_memset() 
{
  uint8_t * val;
  uint8_t * ptr1;
  uint8_t * ptr2;
  
  uint8_t i = 0;
  int8_t err = NO_ERROR;

  PRINTF("Function test_memset() running\n");
  val = (uint8_t*)reserve_words(MEM_SIZE1);

  ptr1 = &val[0];
  ptr2 = &val[16];

  for( i = 0; i < MEM_SIZE; i++) 
  {
    val[i] = i;
  }

  print_array(val, MEM_SIZE);
  my_memset(ptr1, MEM_SIZE, 0xFF);
  print_array(val, MEM_SIZE);
  my_memzero(ptr2, MOVE_LENGTH);
  print_array(val, MEM_SIZE);
  
  /* Validate val & Zero Functionality */
  for (i = 0; i < MOVE_LENGTH; i++)
  {
    if (val[i] != 0xFF)
    {
      err = ERROR_OCCURE;
    }
    if (val[16 + i] != 0)
    {
      err = ERROR_OCCURE;
    }
  }
  
  free_words( (uint32_t*)val );
  return err;
}

int8_t test_reverse()
{
  uint8_t i = 0;
  int8_t err = NO_ERROR;
  uint8_t * test;
  
  uint8_t val[MEM_SIZE] = {0x5F, 0x22, 0x27, 0x33, 0x45, 0x34, 0x27, 0x62, 0x82, 0x36, 0x20, 0x66, 0xF6, 0x30, 0x50, 0xDD,
                           0x76, 0x71, 0x72, 0x88, 0x12, 0xD4, 0xF0, 0x80, 0xA0, 0x42, 0xC7, 0xB0, 0x2D, 0x96, 0x6C, 0x45 };

  PRINTF("Function test_reverse() running\n");
  test = (uint8_t*)reserve_words(MEM_SIZE1);

  my_memcopy(val, test, MEM_SIZE);

  print_array(val, MEM_SIZE);
  my_reverse(val, MEM_SIZE);
  print_array(val, MEM_SIZE);

  for (i = 0; i < MEM_SIZE; i++)
  {
    if (val[i] != test[MEM_SIZE - i - 1])
    {
      err = ERROR_OCCURE;
    }
  }

  free_words( (uint32_t*)test );
  return err;
}

void course1(void) 
{
  PRINTF("--------------------------------\n");
  PRINTF("ALL Function Test Started:\n");
  PRINTF("--------------------------------\n");

  test_data1();
  test_data2();
  test_memmove1();
  test_memmove2();
  test_memmove3();
  test_memcopy();
  test_memset();
  test_reverse();

}