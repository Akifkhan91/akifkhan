#include <stdio.h>
#define SIZE 10
void enter_data(double [], int);
double get_double(void);
void show_data(const double [], int);
void largest_index(const double [], int, double *, int *);
void main(void)
{
	double data[SIZE];
	double largest;
	int index_l;
	printf("Enter some data:\n");
	enter_data(data, SIZE);
	printf("The entered data is:\n");
	show_data(data, SIZE);
	printf("The index of the largest value is:\n");
	largest_index(data, SIZE, &largest, &index_l);
	printf("The largest value is: %lf, having the index: %d\n", largest, index_l);
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

void largest_index(const double ar[], int n, double * lar_val, int * ind_l)
{
	int i;
	for(i = 1, *lar_val = ar[0], *ind_l = 0; i < n; i++)
		if(ar[i] > *lar_val)
		{
			*lar_val = ar[i];
			*ind_l = i;
		}
}