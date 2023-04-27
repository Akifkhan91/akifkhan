#include <stdio.h>
void main(void)
{
	int low_limit, upper_limit;
	int i;
	int sum_square = 0;
	
	printf("Enter the lower and upper limit\n");
	printf("Enter upper limit <= lower limit to quit:\n");
	scanf("%d %d",&low_limit, &upper_limit);

	while(low_limit < upper_limit)
	{
		for(i = low_limit; i <= upper_limit; ++i)
			sum_square = i*i + sum_square; 

		printf("The sums of the squares from %d to %d is %d\n",low_limit, upper_limit, sum_square);
		sum_square = 0;
		printf("Enter the lower and upper limit\n");
		printf("Enter upper_limit limit <= lower limit to quit:\n");
		scanf("%d %d",&low_limit, &upper_limit);
	}
	printf("Done!\n");
}