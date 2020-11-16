#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rolldice();

int main()
{

	int temp;
	int newtemp;
	int win=0;
	int lose=0;
	int count=0;

	do {
		temp = rolldice();
		++count;     
		if (temp == 7) {
			++win;
		}
		else
		{
			newtemp = rolldice();
			++count; 
			while (newtemp != 7) {
				newtemp = rolldice();
				++count; 
				if (newtemp == temp) {
					win++;
				}
			}
			++lose;
		}	
	} while (count < 1000); 
	

	printf("Number of wins: %d\n", win);
	printf("Number of losses: %d\n", lose);
	return 0;
}

int rolldice() {
	int die1;
	int die2;
	srand(time(NULL));
	die1 = ((rand() % 6) + 1);
	die2 = ((rand() % 6) + 1);
	return (die1 + die2);
}
