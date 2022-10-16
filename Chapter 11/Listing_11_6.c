#include <stdio.h>
#define STLEN 81
void main(void)
{
	char words[STLEN];

	puts("Enter a string please:");
	gets(words); // gets discards the newline character when we press enter to 
				 // for the buffer to flush 
	printf("Your string twice\n");
	printf("%s\n",words); // The \n makes the output on the newline
	puts(words); // puts appends a \n at the end of the output
	puts("Done.");
}