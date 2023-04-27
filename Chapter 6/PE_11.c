#include <stdio.h>
void main(void)
{
	int arr[8];
	int i;
	printf("Enter 8 integers\n");

	for(i = 0; i < 8; ++i)
		scanf("%d",&arr[i]);

	for(i = 7; i >= 0; --i)
		printf("%5d",arr[i]);

	printf("\n");
}