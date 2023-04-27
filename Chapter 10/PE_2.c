#include <stdio.h>
#define SIZE 10
void enter_data(double [], int);
double get_double(void);
void cpy_1(double target1[], const double source[], int);
void cpy_2(double * target2, const double * source_arr, int);
void cpy_3(double target3[], const double source[], double *);
void show_data(const double[], int);
void main(void)
{
	double source[SIZE];
	double target1[SIZE], target2[SIZE], target3[SIZE];
	double * pt_last;
	pt_last = source + SIZE;
	printf("Enter %d numbers\n", SIZE);
	enter_data(source, SIZE);
	cpy_1(target1, source, SIZE);
	cpy_2(target2, source, SIZE);
	cpy_3(target3, source, pt_last);
	printf("The source file is: \n");
	show_data(source, SIZE);
	printf("Target1:\n");
	show_data(target1, SIZE);
	printf("Target2:\n");
	show_data(target2, SIZE);
	printf("Target3:\n");
	show_data(target3, SIZE);
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

void cpy_1(double target1[], const double source[], int n)
{
	int i;
	for(i = 0; i < n; i++)
		target1[i] = source[i];
}

void cpy_2(double * target2, const double * source, int n)
{
	int i;
	for(i = 0; i < n; i++)
		*(target2 + i) = *(source + i);
}

void cpy_3(double target3[], const double source[], double * pt_last)
{
	int i;
	for(i = 0; i < (pt_last-source); i++)
		target3[i] = source[i]; 
}

void show_data(const double ar[], int n)
{
	int i;
	for(i = 0; i < n; i++)
		printf("%0.2lf ",ar[i]);

	printf("\n");
}