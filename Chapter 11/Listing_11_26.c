#include <stdio.h>
#include <string.h>
#define WORDS "beast"
#define SIZE 40
void main(void)
{
	const char * orig = WORDS;
	char copy[SIZE] = "Be the best that you can be.";
	char * ps;

	puts(orig);
	puts(copy);
	ps = strcpy(copy + 7, orig);
	puts(copy);
	puts(ps);

}