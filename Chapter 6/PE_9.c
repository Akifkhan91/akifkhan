#include <stdio.h>
#include <math.h>
float value(float n1, float n2);
void main(void)
{
	float num1, num2, val;
	printf("Enter 2 numbers\n");
	printf("Press q to quit\n");

	while(scanf("%f %f",&num1, &num2) == 2)
	{	
		val = value(num1,num2);
		printf("The value of val is %10.4f\n",val);
		printf("Enter 2 numbers\n");
		printf("Press q to quit\n");
	}
}

float value(float n1, float n2)
{
	float val;
	val = fabs(n1 - n2)/(n1*n2);

	return val;
}