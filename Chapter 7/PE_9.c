#include <stdio.h>
#include <stdbool.h>
bool isPrime(int num);

void main(void)
{
	unsigned long int num;
	unsigned long int i, j;
	int k = 0;
	printf("Enter a number until which all prime numbers less than it have to be displayed\n");
	scanf("%lu",&num);

	bool Prime[num];
	for(i = 2; i <= num; i++)
		Prime[i-2] = true;

	for(i = 2; i <= num; i++)
	{
		if(Prime[i-2] == true)
		{
		Prime[i-2] = isPrime(i);
			if(Prime[i-2] == true)
			{
				for(j = 2; j*i <= num; j++)
				{
					if(Prime[j*i-2] == true)
						Prime[j*i-2] = false;
				}
			}
		}
	}

	printf("The prime numbers from 2 to %lu are\n",num);
	for(i = 2; i <= num; i++)
	{
		if(Prime[i-2] == true)
			printf("%d) %lu\n",++k,i);
	}
	printf("\n");
}

bool isPrime(int num)
{
	unsigned long int div;
	bool Prime;
	for(div = 2, Prime = true; div*div <= num; div++)
	{
		if(num % div == 0)
			Prime = false;
	}
	return Prime;
}