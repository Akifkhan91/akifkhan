#include <stdio.h>
void main(void)
{
	float quarts;
	float water_molecules=3.0e-23;
	printf("Enter the number of quarts of water \n");
	scanf("%f",&quarts);
	printf("The total number of water molecules is = %e\n",water_molecules*quarts*950.0); /*Exponentiol
	notation has specifier %c, %f will show 0.0000 so we use exponential notation */
}