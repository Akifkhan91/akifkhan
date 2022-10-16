#include <stdio.h>
#include <string.h>
#define SIZE_SOURCE 81
#define SIZE_TARGET 10
char * s_gets(char * st, int n);
char * mystrncpy(char * st2, const char * st1, int n);
int main(void)
{
	char string1[SIZE_SOURCE], string2[SIZE_TARGET];
	int n;
	puts("Enter the source string");
	s_gets(string1, SIZE_SOURCE);
	puts("Enter the number of characters to be copied");
	scanf("%d", &n);
	mystrncpy(string2, string1, n);
	puts(string2);
	return 0;
}

char * mystrncpy(char * st2, const char * st1, int n)
{
	if(SIZE_TARGET-1 < n)
	{
		strncpy(st2, st1, n);
		st2[SIZE_TARGET-1] = '\0';
	}
	else
		strncpy(st2, st1, n);

	return st2;
}