#include <stdio.h>
void main(void)
{
	int friends = 5;
	int week = 0;

	do
	{
		week++;
		friends -= 1;
		friends *= 2;
		printf("week = %5d No. of friends = %5d\n",week,friends); 
	}while(friends < 150);
}