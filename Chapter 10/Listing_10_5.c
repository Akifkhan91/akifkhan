#include <stdio.h>
#define MONTHS 12
void main(void)
{
	int days[MONTHS] = {31, 28, [4] = 31, 30, 31, [1] = 29};
	int i;

	for(i = 0; i < MONTHS; i++)
		printf("There are %2d days in month %2d\n", days[i], i + 1);
}