#include <stdio.h>
#include <ctype.h>
#define SIZE 81
int main(void)
{
	char ch;
	int i = 0;
	char word[SIZE];
	puts("Enter a line of input and i will give you the first word:");
	puts("Enter press newline to quit");
	ch = getchar();
	
	while(isspace(ch))
		ch = getchar();

	while(!isspace(ch))
	{
		word[i] = ch;
		ch = getchar();
		i++;
	}
	word[i] = '\0';

	while(getchar() != '\n')
		continue;

	puts(word);
	return 0;
}