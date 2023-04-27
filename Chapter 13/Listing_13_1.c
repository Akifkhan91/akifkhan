#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const * argv[])
{
	char ch;
	FILE * fp;
	unsigned long int count = 0;
	if(argc != 2)
	{
		printf("Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if((fp = fopen(argv[1],"r")) == NULL)
	{
		printf("Unable to open file\n");
		exit(EXIT_FAILURE);
	}
	while((ch = getc(fp)) != EOF)
	{
		putc(ch, stdout);
		count++;
	}
	fclose(fp);
	printf("There are %lu characters in the file %s\n", count, argv[1]);
	return 0;
}