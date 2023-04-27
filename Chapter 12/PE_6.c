#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1000
#define RANDMAX 10
void DisplayArr(const int arr[], int length);
void SetFreqToZero(int arr[], int length);
int main(void)
{
	int ListOfNum[SIZE];
	int FreqOfNum[RANDMAX];
	time_t seconds;
	for(int i = 0; i < 10; i++)
	{
		srand((i+1)*time(NULL));
		SetFreqToZero(FreqOfNum, RANDMAX);
		for(int j = 0; j < SIZE; j++)
		{
			ListOfNum[j] = (rand() % RANDMAX) + 1;
			++FreqOfNum[ListOfNum[j]-1];
		}
		printf("The frequency of the numbers are:\n");
		DisplayArr(FreqOfNum, RANDMAX);
	}
	return 0;
}

void DisplayArr(const int arr[], int length)
{
	for(int i = 0; i < length; i++)
		printf("%d ", arr[i]);

	putchar('\n');
}

void SetFreqToZero(int arr[], int length)
{
	for(int i = 0; i < length; i++)
		arr[i] = 0;
}
