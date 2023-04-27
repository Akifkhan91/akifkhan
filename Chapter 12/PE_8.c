#include <stdio.h>
#include <stdlib.h>
int * make_array(int elem, int val);
void show_array(const int ar[], int n);
int main(void)
{
	int * pa;
	int size, value;

	printf("Enter the number of elements: \n");
	while((scanf("%d", &size) == 1) && size > 0)
	{
		printf("Enter the intialization value\n");
		scanf("%d", &value);
		pa = make_array(size, value);
		if(pa)
		{	
			printf("The array is:\n");
			show_array(pa, size);
			free(pa);
		}
		printf("\nEnter the number of elements(Press 0 to quit):\n");
	}
	printf("Done!\n");
	return 0;
}

int * make_array(int elem, int val)
{
	int * arr = malloc(elem*sizeof(int));
	for(int i = 0; i < elem; i++)
		arr[i] = val;

	return arr;
}

void show_array(const int ar[], int n)
{
	for(int i = 0; i < n; i++)
	{
		if(i% 8 == 0)
			putchar('\n');
		printf("%d ", ar[i]);
	}
}