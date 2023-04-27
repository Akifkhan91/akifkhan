#include <stdio.h>
#include <string.h>
#define SIZE 81
char * s_gets(char * st, int n);
void str_reverse(char * st, int n);
int main(void)
{
	char string[SIZE];
	puts("Enter a string to be reversed(Enter a newline to quit)");
	while(s_gets(string, SIZE) && string[0] != '\0')
	{
		puts("The reversed string is:");
		str_reverse(string, strlen(string));
		puts(string);
		puts("Enter a string to be reversed(Enter a newline to quit)");
	}
	return 0;
}

void str_reverse(char * st, int n)
{
	char ch;
	int i;
	for(i = 0; i < n/2; i++)
	{
		ch = st[i];
		st[i] = st[n-i-1];
		st[n-i-1] = ch;
	}
}