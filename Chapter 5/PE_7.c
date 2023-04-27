#include <stdio.h>
void cube(double n);
void main(void)
{
	double num;
	printf("Enter a number to be cubed\n");
	scanf("%lf",&num);
	cube(num);
}
void cube(double n)
{
	double cube;
	cube = n*n*n;
	printf("The cube of the given number is: %lf\n",cube);
}