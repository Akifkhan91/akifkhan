#include <stdio.h>

void report_count(void);
void accumulate(int k);

int count = 0; // file scope, external linkage, static storage duration
int main(void)
{
	int value; // block scope, no linkage, auto storage duration
	register int i; // register variable, it "requests" the compiler to store 
					// variable in the computer register for faster access

	printf("Enter a positive integer(Enter 0 to quit)\n");
	while(scanf("%d", &value) == 1 && value > 0)
	{
		++count; // file scope varaible
		for(i = value; i >= 0; i--)
			accumulate(i);

		printf("Enter a positive integer(Enter 0 to quit)\n");
	}

	report_count();
	return 0;
}

void report_count(void)
{
	printf("Total executed of loops %d\n", count);
}