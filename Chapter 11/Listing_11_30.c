#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 81

void ToUpper(char *);
int  IsPunct(const char *);

void main(void)
{
	char line[SIZE];
	char * find;
	puts("Enter a line:");
	fgets(line, SIZE, stdin);
	find = strchr(line, '\n');
	if(find)
		*find = '\0';

	ToUpper(line);
	puts(line);
	printf("The line has %d Punctuation characters\n", IsPunct(line));
}

void ToUpper(char * str)
{
	while(*str)
	{
		*str = toupper(*str);
		str++;
	}
}

int IsPunct(const char * str)
{
	int ct = 0;
	while(*str)
	{
		if(ispunct(*str))
			ct++;

		str++;
	}
	return ct;
}