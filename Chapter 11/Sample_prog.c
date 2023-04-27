/*
#include <stdio.h>
void main(void)
{
	char * pt = "Klingon";
	puts("Kilngon"); // This causes program to abort (Segmentation fault)
					  // Using a pointer to change a string literal is undefined
					  // in C. Use const char * pt = "Kilingon" if using a 
					  // pointer to a string literal		
	printf("Beware the %ss\n", "Klingon");
}
*/


#include <stdio.h>
#define STLEN 10
void main(void)
{
	char * pt;
	char words[STLEN];
	puts("Enter a string:");
	pt = fgets(words, STLEN, stdin);
	printf("Entered string = %s, pointer to the first letter = %p, "
		"Return value of fgets = %p\n", words, words, pt);
}