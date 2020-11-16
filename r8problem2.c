#include <stdio.h>

long test(long x, long y, long z){
    if (x>y){
        return 2*y;
    }
    if(z>y){
        return 3*z;
    }
    return 12*x;
}
int main(){
	long test1=test(5,3,2);
	printf("%s\n",test1 );
}