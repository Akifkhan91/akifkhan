#include <stdio.h>
void main(void)
{
	int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int index;

	for(index = 0; index < sizeof(days)/sizeof(days[0]); index++)
		printf("There are %2d days in the month %2d \n", days[index],  index + 1);
}