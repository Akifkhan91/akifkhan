#include<stdio.h>
void main(void)
{
	unsigned width, precision;
	int number = 256;
	float weight = 242.5f; 
	printf("Field width control with the * modifier\n");
	printf("For printf, * defines the field width\n");
	printf("Enter a field width\n");
	scanf("%u",&width);
	printf("The number is %*d\n",width,number);
	printf("Enter width & precision\n");
	scanf("%u %u",&width,&precision);
	printf("Your weight is %*.*f\n",width,precision,weight);
	printf("Now we demonstrate how * is used with scanf to suppress input\n");
	printf("Enter three numbers\n");
	scanf("%*f %*f %f",&weight);
	printf("The last number is %0.3f\n",weight);
}