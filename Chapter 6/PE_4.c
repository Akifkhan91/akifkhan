#include <stdio.h>
void main(void)
{
	const int ROW = 6;
	int i, j;
	char ch = 'A';
	
	for(i = 1; i <= ROW; ++i)
	{
		for(j = 1; j <= i; ++j)
			{
			printf("%c",ch);
			ch = (int)ch + 1;
			}
		printf("\n");
	}	
}