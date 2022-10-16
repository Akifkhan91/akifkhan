#include <stdio.h>
#define SIZE 10
void enter_data(int [], int);
int get_int(void);
int largest_int(const int [], int);
void show_data(const int [], int);
void main(void)
{
	int data[SIZE];
	int largest;
	printf("Enter some integer values: \n");
	enter_data(data, SIZE);
	largest = largest_int(data, SIZE);
	printf("The array you have inputted is:\n");
	show_data(data, SIZE);
	printf("The largest value in the array is = %d\n",largest);
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
		printf("Enter an integer like -1, 4, 15\n");
		while(getchar() != '\n')
			continue;
	}
	return num;
}

int largest_int(const int ar[], int n)
{
	int i;
	int largest;
	for(i = 1, largest = ar[0]; i < n; i++)
	{
		if(ar[i] > largest)
			largest = ar[i];
	}
	return largest;
}

void show_data(const int ar[], int n)
{
	int i;
	for(i = 0; i < n; i++)
		printf("%d ",ar[i]);

	printf("\n");
}