#include <stdio.h>
#define ROW 6
void main(void)
{
	int i,j;
	char ch = 'F';
	for (int i = 1; i <= ROW; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			printf("%c", (int)ch - j);
		}
		printf("\n");
	}
}