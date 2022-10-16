#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100
void IntSort(int arr[], int length);
void DisplayArr(const int arr[], int length);
int main(void)
{
	int ListOfNum[SIZE];

	srand((unsigned int) time(0)); // randomize seed
	for(int i = 0; i < SIZE; i++)
		ListOfNum[i] = (rand() % 10) + 1;

	printf("The ListOfNum array is:\n"); 
	DisplayArr(ListOfNum, SIZE);
	printf("Sorting the array\n");
	IntSort(ListOfNum, SIZE);
	printf("Sorted array is:\n");
	DisplayArr(ListOfNum, SIZE);

	return 0;
}

void IntSort(int arr[], int length)
{
	for(int i = 0; i < length - 1; i++)
	{
		for(int j = i+1; j < length; j++)
		{
			if(arr[i] < arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void DisplayArr(const int arr[], int length)
{
	for(int i = 0; i < length; i++)
		printf("%d ", arr[i]);

	putchar('\n');
}
