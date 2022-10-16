#include <stdio.h>
void main(void)
{
	int low_limit, upper_limit;
	int status, i;

	printf("Enter the lower and upper limits\n");
	scanf("%d %d",&low_limit, &upper_limit);
	printf("Number\t Square\t Cube\n");

	for (i = low_limit; i <= upper_limit; ++i)
		printf("%- 5d\t %- 6d\t %- 4d\n",i ,i*i, i*i*i);

}
