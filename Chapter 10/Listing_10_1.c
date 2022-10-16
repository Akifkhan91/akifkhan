#include <stdio.h>
#define MONTHS 12
void main(void)
{
	int days[MONTHS] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int index;

	for(index = 0; index < MONTHS; index++)
		printf("There are %2d days in the month %2d \n", days[index],  index + 1);
}