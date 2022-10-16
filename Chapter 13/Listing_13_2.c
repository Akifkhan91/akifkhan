#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 20

int main(int argc, char const * argv[])
{
	int count = 0;
	FILE * in, * out; // declare two file pointers
	char ch, name[LEN];

	// check for command line arguments
	if(argc < 2)
	{
		printf("Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	// set up input
	if((in = fopen(argv[1], "r")) == NULL)
	{
		printf("Error in opening file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	
	// set up output
	strncpy(name, argv[1], LEN-5);
	name[LEN-5] = '\0';
	strcat(name, ".red");

	if((out = fopen(argv[2], "w")) == NULL)
	{
		fprintf(stderr, "Error can't create output file\n");
		exit(EXIT_FAILURE);
	}
	
	// copy data
	while((ch = getc(in)) != EOF)
	{
		if(count++ % 3 == 0)
			putc(ch, out);
	}

	// clean up: closing files
	if(fclose(in) != 0 || fclose(out) != 0)
		fprintf(stderr, "Error in closing files\n");

	return 0;
}