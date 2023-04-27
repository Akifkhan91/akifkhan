#include <stdio.h>
#define STLEN 14
void main(void)
{
	char words[STLEN];

	puts("Enter a string please:");
	fgets(words, STLEN, stdin); /* fgets takes 3 arguments. The character string,
								 the maximum length of the string, 
								 the file input(stdin for keyboard input)
								 fgets also doesn't discard the \n
								 when we press enter for the input, i.e
								 if the input is less that the max length of
								 the string. 
								 */ 
	printf("Your string twice(puts(), then fputs():)\n");
	puts(words); 				/* As fgets doesn't discard the \n when we press
								   enter after the input, we see and additional
								   newline as puts displays the output after
								   adding a newline character
								*/
	fputs(words, stdout);
	puts("Enter another string please:");
	fgets(words, STLEN, stdin);
	printf("Your string twice(puts(), then fputs():)\n");
	puts(words);
	fputs(words, stdout);
	printf("Done.\n");
}