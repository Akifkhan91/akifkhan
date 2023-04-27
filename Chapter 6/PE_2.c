#include <stdio.h>
void main(void)
{
	int i,j;
	const int ROW = 5;

	for(i = 1; i <= ROW; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("$");
		}
		printf("\n");
	}


}