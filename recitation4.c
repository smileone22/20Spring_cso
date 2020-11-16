#include "stdio.h"
#include <assert.h>
int is_little_endian(){
	unsigned int n = 1;
  	char *c = (char*) &n;
  	return (int)*c;
}

unsigned combine(unsigned x, unsigned y){
	unsigned mask = 0xFF;
	//make last byte 0 
	y = y>>8;
	y = y<<8;
	//make 0 except last  byte
	x=x & mask; 

	return x | y;


}


int main(void){
	//output for problem1 

	if (is_little_endian()==1){
		printf("This machine is little endian \n");
		}
		else{
		printf("This machine is big endian \n");

		}


	//output for problem 2 
	int result= 0x765432EF;
	int x = 0x89ABCDEF;
	int y = 0x76543210;
	printf("Input: \nX:%X, Y:%X\n", x, y);
	assert(combine(x, y)==result);
	printf("Result: %X\n", combine(x, y));

	return 0; 
}