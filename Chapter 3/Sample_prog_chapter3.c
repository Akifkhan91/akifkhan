#include <stdio.h>
void main(void)
{
	float var;
	printf("Enter the floating point value\n");
	scanf("%f",&var);
	printf("The value of the varibale in decimal notation is:%f\n",var);
	printf("The value of the varibale in exponential notation is:%e\n",var);
	printf("The value of the varibale in p(hexadecimal) notation is:%a\n",var);
}