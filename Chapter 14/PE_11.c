#include <stdio.h>
#include <math.h>
#define LEN 100
double (*pf)(double x);
void transform(double source[], double target[], int n, double (*pf)(double x));
void print_arr(const double target[], int n);

int main(void)
{
	double source[LEN], target[LEN];
	for(int i = 0; i < LEN; i++)
		source[i] = i;

	transform(source, target, LEN, sin);
	puts("sin(target) = ");
	print_arr(target, LEN);
	transform(source, target, LEN, cos);
	puts("cos(target) = ");
	print_arr(target, LEN);

	return 0;
}

void transform(double source[], double target[], int n, double (*pf)(double x))
{
	for(int i = 0; i < n; i++)
		target[i] = pf(source[i]);
}

void print_arr(const double target[], int n)
{
	for(int i = 0; i < n; i++)
		printf("%1.2f\n", target[i]);
}