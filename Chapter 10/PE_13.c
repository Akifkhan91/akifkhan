#include <stdio.h>
#define ROWS 3
#define COLS 5
double get_double(void);
void get_arr(double [], int);
double get_avg_single_arr(const double [], int);
double avg_mult_arr(const double [][COLS], int);
double largest(const double [][COLS], int);
void disp_results(const double [][COLS], int, double [], double *, double *);
void main(void)
{
	int i;
	double data[ROWS][COLS];
	double avg_row[ROWS];
	double avg_all, la_val;
	printf("Enter 3 sets of double values:\n");

	for(i = 0; i < ROWS; i++)
	{
		printf("Enter %dst set:\n", i+1);
		get_arr(data[i], COLS);
	}

	for(i = 0; i < ROWS; i++)
		avg_row[i] = get_avg_single_arr(data[i], COLS);

	avg_all = avg_mult_arr(data, ROWS);
	la_val = largest(data, ROWS); 
	disp_results(data, ROWS, avg_row, &avg_all, &la_val);
}


void get_arr(double ar[], int n)
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

double get_avg_single_arr(const double ar[], int n)
{
	int i;
	double avg;
	for(i = 0, avg = 0.0; i < n; i++)
		avg += ar[i];

	return avg/n ;
}

double avg_mult_arr(const double ar[][COLS], int rows)
{
	int r, c;
	double total;
	for(r = 0, total = 0.0; r < rows; r++)
	{
		for(c = 0; c < COLS; c++)
			total += ar[r][c];
	}
	return total/(rows*COLS);
}

double largest(const double ar[][COLS], int rows)
{
	int r, c;
	double la_val;
	for(r = 0, la_val = ar[0][0]; r < rows; r++)
	{
		for(c = 0; c < COLS; c++)
		{
			if(ar[r][c] > la_val)
				la_val = ar[r][c];
		}
	}
	return la_val;
}

void disp_results(const double ar[][COLS], int rows, double avg_row[], double * avg_all, double * la_val)
{
	int r, c;
	int i;
	printf("The inputted array is:\n");
	for(r = 0; r < rows; r++)
	{
		for(c = 0; c < COLS; c++)
			printf("%5.2lf ",ar[r][c]);

		printf("\n");
	}

	for(i = 0; i < rows; i++)
		printf("Average of row %d = %0.2lf\n",i+1, avg_row[i]);
	
	printf("The average of all 15 values is %0.2lf\n", *avg_all);
	printf("The largest of all 15 values is %0.2lf\n", *la_val);
}