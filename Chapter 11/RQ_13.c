#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 81
#define ANSWER "GRANT"
char * s_gets(char * st, int n);
void ToUpper(char * st);
int main(void)
{
	char string[SIZE];
	int i = 0;
	printf("Who is buried in Grant's tomb?\n");
	s_gets(string, SIZE);
	ToUpper(string);

	while(strcmp(string, ANSWER) != 0)
	{
		puts("Wrong answer. Try again.");
		s_gets(string, SIZE);
		ToUpper(string);
	}
	puts("That's right");

	return 0;
}

void ToUpper(char * st)
{
	while(*st != '\0')
	{
		*st = toupper(*st);
		st++;
	}
}

