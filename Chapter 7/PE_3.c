#include <stdio.h>
#include <math.h>
int main(void)
{
	int num;
	int even_int = 0;
	int odd_int = 0;
	int rv;
	float sum_even = 0.0f;
	float sum_odd = 0.0f;

	printf("Enter some integers\n");
	printf("Press 0 to exit.\n");

	while(scanf("%d",&num) == 1)
	{
		if(num)
		{
			if(num % 2 == 0)
			{
				even_int++;
				sum_even += num;
			}
			else
			{
				odd_int++;
				sum_odd += num;
			}
		}
	}

	printf("Odd Int\t Avg. Odd Int\t Even Int\t Avg. Even Int\n");
	printf("%4d\t %6.2f\t %12d\t %20.2f\n",odd_int, sum_odd/odd_int, even_int, sum_even/even_int);
	return 0;
}
