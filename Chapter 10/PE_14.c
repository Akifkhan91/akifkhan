#include <stdio.h>
double get_double(void);
void get_arr(int col, double ar[]);
double get_avg_single_arr(int col, const double ar[]);
double avg_mult_arr(int row, int col, const double ar[row][col]);
double largest(int row, int col, const double ar[row][col]);
void disp_results(int row, int col, const double ar[row][col], double avg_row[], double *, double *);
void main(void)
{
	int i;
	int row = 3, col = 5; 
	double data[row][col];
	double avg_row[row];
	double avg_all, la_val;
	printf("Enter 3 sets of double values:\n");

	for(i = 0; i < row; i++)
	{
		printf("Enter %dst set:\n", i+1);
		get_arr(col, data[i]);
	}

	for(i = 0; i < row; i++)
		avg_row[i] = get_avg_single_arr(col, data[i]);

	avg_all = avg_mult_arr(row, col, data);
	la_val = largest(row, col, data); 
	disp_results(row, col, data, avg_row, &avg_all, &la_val);
}


void get_arr(int col, double ar[])
{
	int i;
	for(i = 0; i < col; i++)
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

double get_avg_single_arr(int col, const double ar[])
{
	int i;
	double avg;
	for(i = 0, avg = 0.0; i < col; i++)
		avg += ar[i];

	return avg/col;
}

double avg_mult_arr(int row, int col, const double ar[row][col])
{
	int r, c;
	double total;
	for(r = 0, total = 0.0; r < row; r++)
	{
		for(c = 0; c < col; c++)
			total += ar[r][c];
	}
	return total/(row*col);
}

double largest(int row, int col, const double ar[row][col])
{
	int r, c;
	double la_val;
	for(r = 0, la_val = ar[0][0]; r < row; r++)
	{
		for(c = 0; c < col; c++)
		{
			if(ar[r][c] > la_val)
				la_val = ar[r][c];
		}
	}
	return la_val;
}

void disp_results(int row, int col, const double ar[row][col], double avg_row[], double * avg_all, double * la_val)
{
	int r, c;
	int i;
	printf("The inputted array is:\n");
	for(r = 0; r < row; r++)
	{
		for(c = 0; c < col; c++)
			printf("%5.2lf ",ar[r][c]);

		printf("\n");
	}

	for(i = 0; i < row; i++)
		printf("Average of row %d = %0.2lf\n",i+1, avg_row[i]);
	
	printf("The average of all 15 values is %0.2lf\n", *avg_all);
	printf("The largest of all 15 values is %0.2lf\n", *la_val);
}