#include <stdio.h>
#define ROWS 3
#define COLS 5
void enter_data(int [][COLS], int);
int get_int(void);
void show_data(const int [][COLS], int);
void double_arr(const int [][COLS], int [][COLS], int);
void main(void)
{
	int data[ROWS][COLS];
	int new_data[ROWS][COLS];
	printf("Enter contents of 3X5 array:\n");
	enter_data(data, ROWS);
	printf("The entered array is:\n");
	show_data(data, ROWS);
	printf("The 2 * [entered array] is:\n");
	double_arr(data, new_data, ROWS);
	show_data(new_data, ROWS);
}

void enter_data(int ar[][COLS], int rows)
{
	int r, c;
	for(r = 0; r < rows; r++)
	{
		printf("Enter elements of row %d\n",r);
		for(c = 0; c < COLS; c++)
			ar[r][c] = get_int();
	}
}

int get_int(void)
{
	int num;
	while(scanf("%d",&num) != 1)
	{
		printf("Enter a number like -3, 17.00, 1.3e3\n");
		while(getchar() != '\n')
			continue;
	}
	return num;
}

void show_data(const int ar[][COLS], int rows)
{
	int r, c;
	for(r = 0; r < rows; r++)
	{
		for(c = 0; c < COLS; c++)
			printf("%5d ",ar[r][c]);

		printf("\n");
	}
}

void double_arr(const int arr1[][COLS], int arr2[][COLS], int rows)
{
	int r, c;
	for(r = 0; r < rows; r++)
	{
		for(c = 0; c < COLS; c++)
			arr2[r][c] = 2 * arr1[r][c];
	}
}