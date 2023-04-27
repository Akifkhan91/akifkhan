#include <stdio.h>
#define SIZE 10
void enter_data(double [], int);
double get_double(void);
void show_data(const double [], int);
int diff_large_small(const double [], int);
void main(void)
{
	double data[SIZE];
	double diff;
	printf("Enter some data:\n");
	enter_data(data, SIZE);
	printf("The entered data is:\n");
	show_data(data, SIZE);
	diff = diff_large_small(data, SIZE);
	printf("The differece between the largest and smallest value is: %lf:\n", diff);
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
	while(scanf("%lf", &num) != 1)
	{
		printf("Please enter a number like -1, 3.00, 1e5\n");
		scanf("%*s");
	}
	return num;
}

void show_data(const double ar[], int n)
{
	int i;
	for(i = 0; i < n; i++)
		printf("%lf \n", ar[i]);

	printf("\n");
}

int diff_large_small(const double ar[], int n)
{
	int i;
	double largest, smallest;
	for(i = 1, largest = ar[0], smallest = ar[0]; i < n; i++)
	{
		if(ar[i] > largest)
			largest = ar[i];

		if(ar[i] < smallest)
			smallest = ar[i];
	}

	return (largest - smallest);
}