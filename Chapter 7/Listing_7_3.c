#include <stdio.h>
#include <ctype.h>
void main(void)
{
	char ch;
	printf("Enter a sentence!\n");

	while((ch = getchar()) != '\n')
	{
		if(isalpha(ch))
			putchar(ch + 1);

		else
			putchar(ch);
	}
	putchar(ch);
}