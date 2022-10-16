#include <stdio.h>
void enter_data(int rows, int cols, double ar[rows][cols]);
double get_double(void);
void cpy(double target[], const double source[], int n);
void show_data(int rows, int cols, const double ar[rows][cols]);
void main(void)
{
 int i;
 int rows = 3, cols = 3;
 double data[rows][cols];
 double cp_data[rows][cols];
 printf("Enter a %dX%d array.\n",rows, cols);
 enter_data(rows, cols, data);
 for(i = 0; i < rows; i++)
 	cpy(cp_data[i], data[i], cols);

printf("The entered data is:\n");
show_data(rows, cols, data);
printf("The copied data is:\n");
show_data(rows, cols, cp_data);
}


void enter_data(int rows, int cols, double ar[rows][cols])
{
	int r, c;
	for(r = 0; r < rows; r++)
	{
		printf("Enter Row %d:\n",r+1);
		for(c = 0; c < cols; c++)
			ar[r][c] = get_double();
	}
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

void cpy(double target[], const double source[], int n)
{
	int i;
	for(i = 0; i < n; i++)
		target[i] = source[i];
}

void show_data(int rows, int cols, const double ar[rows][cols])
{
	int r, c;
	for(r = 0; r < rows; r++)
	{
		for(c = 0; c < cols; c++)
			printf("%0.2lf ",ar[r][c]);

		printf("\n");
	}
}