#include <stdio.h>
#include <time.h>
unsigned int rand1(void);
void srand1(unsigned int seed);
int main(void)
{
	int count;
	unsigned int seed;

	//printf("Enter a value for the seed(press q to quit)\n");
	//while(scanf("%u", &seed) == 1)
	//{
		//srand1(seed);
		srand1((unsigned int) time(0));

		for(count = 0; count < 5; count++)
			printf("%u\n", rand1());

		//printf("Enter a value for seed(press q to quit)\n");
	//}

	return 0;
}