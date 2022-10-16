#include <stdio.h>
#define SIZE 10
int sump(int * start, int * end);
void main(void)
{
	int marbles[SIZE] = {20,10,5,39,4,16,19,26,31,20};
	int sum;
	sum = sump(marbles, marbles + SIZE);
	printf("The total number of marbles is %d\n",sum);

}

int sump(int * start, int * end)
{
	int total = 0;
	while(start < end)
	{
		total += *start;
		start++;
	}
	return total;
}