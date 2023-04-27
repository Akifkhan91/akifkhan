#include <stdio.h>
void enter_data(int cols, double ar[cols]);
double get_double(void);
void cpy(double cp_data[], double * start, double * end);
void show_data(int cols, double cp_data[]);
void main(void)
{
	int cols = 7;
	double data[cols];
	double cp_data[3];
	printf("Enter a 7 numbers:\n");
	enter_data(cols, data);
	cpy(cp_data, data+2, data+4);
	printf("The copied sub array is:\n");
	show_data(3, cp_data);
}

void enter_data(int cols, double ar[cols])
{
	int c;
	for(c = 0; c < cols; c++)
		ar[c] = get_double();
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

void cpy(double cp_data[], double * start, double * end)
{
	int i;
	for(i = 0; start <= end; i++, start++)
		cp_data[i] = *start;
}

void show_data(int cols, double cp_data[])
{
	int c;
	for(c = 0; c < cols; c++)
		printf("%5.2lf",cp_data[c]);

	printf("\n");
}