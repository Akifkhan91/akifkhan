#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define STOP '|'

void main(void)
{
	char c;
	long int characters = 0L;
	int words = 0;
	int lines = 0;
	int p_lines = 0;
	bool inword = false;
	char prev = '\n';
	
	printf("Enter some text\n");
	printf("Press | to quit.\n");

	while((c = getchar())!= STOP)
	{
		characters++;

		if(c == '\n')
			lines++;

		if(!isspace(c) && !inword)
		{
			words++;
			inword = true;
		}

		else if(isspace(c) && inword)
			inword = false;

		prev = c;
	}

	if(prev != '\n')
		p_lines = 1;

	printf("There are %ld characters, %d words, %d lines and %d partial lines in the sentence\n",
		characters, words, lines, p_lines);
}