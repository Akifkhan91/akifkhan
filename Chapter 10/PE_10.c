#include <stdio.h>
#define SIZE 5
void enter_data(int [], int);
int get_int(void);
void show_data(const int [], int);
void add_array(const int [], const int [], int [], int);
void main(void)
{
	int data1[SIZE];
	int data2[SIZE];
	int sum_data[SIZE];
	printf("Enter contents of array 1:\n");
	enter_data(data1, SIZE);
	printf("Enter contents of data 2:\n");
	enter_data(data2, SIZE);
	printf("Array 1 is :\n");
	show_data(data1, SIZE);
	printf("Array 2 is :\n");
	show_data(data2, SIZE);
	printf("The sum of Array 1 and Array 2 is :\n");
	add_array(data1, data2, sum_data, SIZE);
	show_data(sum_data, SIZE);
}

void enter_data(int ar[], int n)
{
	int i;
	for(i = 0; i < n; i++)
		ar[i] = get_int();
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

void show_data(const int ar[], int n)
{
	int i;
	for(i = 0; i < n; i++)
		printf("%4d ",ar[i]);

	printf("\n");
}

void add_array(const int arr1[], const int arr2[], int arr3[], int n)
{
	int i;
	for(i = 0; i < n; i++)
		arr3[i] = arr1[i] + arr2[i];
}