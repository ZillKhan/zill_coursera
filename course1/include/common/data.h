/******************************************************************************
******************************************************************************/
/**
 * @file data.h
 * @brief Developling fucntion to convert integer to ascii and vice versa
 *
 *
 * @author Zill Ullah Khan
 * @date 03/10/2021
 *
 */

/**
 * @brief Fucntion converts integer to ascii
 *
 * The number you wish to convert is passed in as a signed 32-bit integer. 
 * Copy the converted character string to the uint8_t* pointer passed in as a parameter (ptr)
 * Function should return the length of the converted data (including a negative sign).
 *
 * @param Pointer to data
 * @param data Integer
 * @param Base value from 2 to 16	
 *
 * @return return an ASCII string length
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief Function converts ascii to integer
 *
 * The character string to convert is passed in as a uint8_t * pointer (ptr).
 * The converted 32-bit signed integer should be returned.
 *
 * @param Pointer to data 
 * @param Length of the String
 * @param Base value from 2 to 16
 *
 * @return integer value
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);