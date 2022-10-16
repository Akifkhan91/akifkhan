#include <stdio.h>
#define SIZE 5
void main(void)
{
	short int dates[SIZE];
	short * pti;
	int index;
	double bills[SIZE];
	double * ptf;

	pti = dates;
	ptf = bills;
	printf("%23s %15s\n","short", "double");
	for(index = 0; index < SIZE; index++)
		printf("pointers + %d: %10p %10p\n", index, pti + index, ptf + index);
	
}