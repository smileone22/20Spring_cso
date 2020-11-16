#include "stdio.h"
#include <assert.h>
int is_little_endian() {
	unsigned int n = 1;
	char* c = (char*)&n;
	return (int)*c;
}

unsigned problem2(unsigned x, unsigned y) {
	unsigned mask = 0xFF;
	//make last byte 0 
	y = y >> 8;
	y = y << 8;
	//make 0 except last  byte
	x = x & mask;

	return x | y;


}

unsigned replace_byte(unsigned x, int i, unsigned char b) {
	int totalbyte = sizeof(x);
	int y;
	unsigned mask = 0xFF;
	unsigned result = b;

	for (y = 0; y < i; y++) {
		//left shift 8 bits
		mask = mask << 8;
		result = result << 8;
	}

	x = x & (~mask);

	return result | x;
}


int main(void) {
	//output for problem1 
	printf("\n Problem 1\n");
	if (is_little_endian() == 1) {
		printf("This machine is little endian \n");
	}
	else {
		printf("This machine is big endian \n");

	}


	//output for problem 2 
	unsigned int result = 0x765432EF;
	unsigned int x = 0x89ABCDEF;
	unsigned int y = 0x76543210;
	assert(problem2(x, y) == result);
	printf("Problem 2 solved \n");




	//output for problem 3
	unsigned int result1 = 0x12AB5678;
	unsigned int result2 = 0x123456AB;
	//replace_byte(0x12345678, 2, 0xAB)  returns 0x12AB5678
	assert(replace_byte(0x12345678, 2, 0xAB) == result1);
	//replace_byte(0x12345678, 0, 0xAB)  returns 0x123456AB
	assert(replace_byte(0x12345678, 0, 0xAB) == result2);
	printf("Problem 3 solved \n");

	return 0;
}