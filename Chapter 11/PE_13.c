#include <stdio.h>
int main(int argc, char * argv[])
{
	int i;
	if(argc < 2)
		printf("Usage %s positive number\n", argv[0]);
	else
	{
		for(i = argc-1; i >= 1; --i)
			printf("%s ", argv[i]);
	}
	putchar('\n');
	return 0;
}