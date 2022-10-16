#include <stdio.h>
void main(int argc, char * argv[])
{
	int i;
	printf("The command line has %d arguments\n", argc - 1);
	for(i = 1; i < argc; i++)
		printf("%d: %s\n", i, argv[i]);
	
	puts("\n");
}