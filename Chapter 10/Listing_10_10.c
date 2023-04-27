#include <stdio.h>
#define SIZE 10
int sum(int [], int);
void main(void)
{
	int marbles[SIZE] = {20,10,5,39,4,16,19,26,31,20};
	printf("The sum of marbles is %d\n",sum(marbles, SIZE));
	printf("The size of marbles is %zd\n", sizeof(marbles));
}

int sum(int ar[], int n)
{
	int i, total = 0;
	for(i = 0; i < n; i++)
		total += ar[i];

	printf("The size of ar is %zd bytes\n", sizeof(ar));
	return total;
}