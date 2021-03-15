#include<stdint.h>
#include "data.h"

//Integer to ASCII convertion function
uint8_t my_itoa(int32_t data, uint8_t* ptr, uint32_t base) {
	
	int32_t swap;
	char check = 0;
	uint8_t i = 0,length;
	
	
	if(data < 0 && base == 10){
		check = 1;	
		data = -data;
	}
	
	while( data != 0) {
		*(ptr + i) = data%base;
		data = data/base;
		i++;
	}

	if( check == 1 ){ 
		*(ptr + i++) = '-';
	}
	length = i;
	i = 0;

    for ( i = 0; i < (length)/2; i++){
        swap = *(ptr + i );
        *(ptr + i ) = *( ptr + length - i - 1);
        *( ptr + length - i - 1) = swap;

    }
        return length;

}

int32_t my_atoi(uint8_t* ptr,uint8_t digits,uint32_t base) {

	int32_t data = 0;
	uint8_t i = digits-2;
	uint8_t swap = (uint8_t)base;
	base = 1;
	
	while( i > 0 ) {
		data += *(ptr + i )*( base ) ;
		base*= swap;
		i--;
	}
	
	if(swap == 10 && *(ptr + i) == '-')    
		data = -data;
	else
		data += *(ptr + i)*( base ); 
	
	return data;

}
