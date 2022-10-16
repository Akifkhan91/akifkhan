#include <stdio.h>
#define COVERAGE 350
void main(void)
{
	int sq_feet;
	int cans;
	printf("Enter the square feet to be painted.\n");
	printf("Press q to quit.\n");

	while(scanf("%d", &sq_feet) == 1)
	{
		cans = sq_feet/COVERAGE;
		cans += ((sq_feet % COVERAGE == 0) ? 0 : 1);
		printf("%d %s are required\n",cans, cans == 1 ? "can" : "cans");
		printf("Enter the square feet to be painted.\n");
		printf("Press q to quit.\n"); 
	}
}