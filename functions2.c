#include "functions2.h"
#include <stdio.h>
#include <stdlib.h>



/* Heewon Kim
 */


long fun1 ( data a[], int size ){
  
  long num = 0;
  int x ;

  for(x=0; x<size ; x++){
    num = num+a[x].i;
}
  return num;
}

 
char* fun2 ( data a[], int size ){
 
  char *characs = malloc((size+1)*sizeof(char));
  int y=0;
  *(characs+size)='\0'; 
  

  for(y=0;y<size;y++){

    *(characs+y)=a[y].c;
  }

  return characs;

}