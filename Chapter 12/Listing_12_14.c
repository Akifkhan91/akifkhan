#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	double * ptr;
	int max, number;
	int i = 0;

	printf("Enter the maximum number of type double values of the array\n");
	if(scanf("%d", &max) != 1 && max < 1)
	{
		printf("Wrong value entered!\n");
		exit(EXIT_FAILURE);
	} 

	ptr = (double *)malloc(max*sizeof(double));
	if(ptr == NULL)
	{
		printf("Memory allocation failed. Exiting.\n");
		exit(EXIT_FAILURE);
	}

	printf("Enter the values for the array\n");
	while(i < max && (scanf("%lf", &ptr[i]) == 1))
		i++;

	printf("Here are %d entries\n", number = i);
	for(i = 0; i < number; i++)
	{
		printf("%7.2lf", ptr[i]);
		if(i % 7 == 6)
			putchar('\n');
	}
	if(i % 7 != 0)
			putchar('\n');

	puts("Done");
	
	free(ptr);

	return 0;
}