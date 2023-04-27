#include <stdio.h>
#include "PE_6_header.h"
void main(void)
{
	double data[SIZE];
	printf("Enter some data:\n");
	enter_data(data, SIZE);
	printf("The entered data is: \n");
	show_data(data, SIZE);
	printf("The array after reversing it is\n");
	reverse_arr(data, SIZE-1);
	show_data(data, SIZE);
}

void enter_data(double ar[], int n)
{
	int i;
	for(i = 0; i < n; i++)
		ar[i] = get_double();
}

double get_double(void)
{
	double num;
	while(scanf("%lf",&num) != 1)
	{
		printf("Enter a number like -3, 17.00, 1.3e3\n");
		scanf("%*s");
	}
	return num;
}

void reverse_arr(double ar[], int n)
{
	int i, temp;			  // SIZE = 10 => n = 9 => n/2 = 4
	for(i = 0; i <= n/2; i++)  // ar[0] = ar[9], ar[1] = ar[8]...ar[4] = ar[5]
	{						  // SIZE = 9 => n = 8 => n/2 = 4
		temp = ar[i];
		ar[i] = ar[n-i];
		ar[n-i] = temp;
	}
}

void show_data(const double ar[], int n)
{
	int i;
	for(i = 0; i < n; i++)
		printf("%0.2lf ",ar[i]);

	printf("\n");
}