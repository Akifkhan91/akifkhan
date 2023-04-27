#include <stdio.h>
#include <stdbool.h>
void main(void)
{
	unsigned long num;
	unsigned long div;
	bool isPrime;

	printf("Please enter an integer for analysis\n");
	printf("Enter q to quit.\n");

	while((scanf("%ld",&num)) == 1)
	{
		for(div = 2, isPrime = true; div*div <= num; div++)
		{
			if(num % div == 0)
			{
				if(div*div != num)
					printf("%ld and %ld divide %ld\n",div,num/div,num);

				else
					printf("%ld divides %ld\n",div, num);
				
				isPrime = false;
			}

		}
	if(isPrime)
		printf("The number %ld is prime\n",num);

	printf("Please enter an integer for analysis\n");
	printf("Enter q to quit.\n");	
	}
}