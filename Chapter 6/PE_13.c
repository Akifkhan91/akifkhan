#include <stdio.h>
void main(void)
{
	int i;
	int num[8];
	
	for(i = 1, num[0] = 2; i < 8; i++)
	{
		num[i] = 2*num[i-1]; 
	}

	i = 0;
	do
	{
		printf("%d\t",num[i]);
		i++;
	}while(i < 8);
	printf("\n");
}