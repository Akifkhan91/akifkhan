#include <stdio.h>
void main(void)
{
	float num1, num2, val;
	printf("Enter 2 floating point numbers\n");
	printf("Press q to quit\n");
	while(scanf("%f %f",&num1, &num2) == 2)
	{
		val = (num1 - num2)/(num1*num2);
		printf("The value of val is %10.4f\n",val);
		printf("Enter 2 floating point numbers\n");
		printf("Press q to quit:\n");
	}

}