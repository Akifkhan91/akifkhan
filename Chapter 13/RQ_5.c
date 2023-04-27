#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * s_gets(char st[], int n);
int main(int argc, char * argv[])
{
	FILE * data;
	char ch, ch_input;
	long line_end = 0L;

	if(argc != 3)
	{
		printf("Usage error: %s\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if(sizeof(*argv[1]) != sizeof(char))
	{
		puts("The first argument to main must be a character");
		exit(EXIT_FAILURE);
	}

	if((data = fopen(argv[2], "r")) == NULL)
	{
		printf("Unable to open file %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	while((ch = getc(data)) != EOF)
	{
		line_end++;
		if(ch == *argv[1])
		{
			fseek(data, -line_end, SEEK_CUR);
			while((ch = getc(data)) != '\n')
				putchar(ch);
			
			putchar('\n');
			line_end = 0L;
		}
		else if(ch == '\n')
			line_end = 0L;
	}
	
	fclose(data);

	return 0;
}

