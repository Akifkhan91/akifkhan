#include <stdio.h>
void main(void)
{
	int i, rv;
	double arr1[8], arr2[8];
	double cum_sum = 0.0;
	
	printf("Enter 8 numbers\n");

	for(i = 0; i < 8; ++i)
		scanf("%lf",&arr1[i]);


	for(i = 0; i < 8; ++i)
		arr2[i] = cum_sum += arr1[i];

	for(i = 0; i < 8; ++i)
		printf("%10.2lf",arr1[i]);

	printf("\n");

	for(i = 0; i < 8; ++i)
		printf("%10.2lf",arr2[i]);

	printf("\n");
}