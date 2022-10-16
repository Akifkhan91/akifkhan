#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 8
void myatoi(const char * st, int n);
char * s_gets(char * st, int n);
int main(void)
{
	char string[SIZE];
	int i = 0, len;
	puts("Enter a number(Enter newline to quit)");

	s_gets(string, SIZE);

	while(string[i] != '\0')
	{
		if(!isdigit(string[i]))
		{
			printf("Please enter a valid numeric string\n");
			s_gets(string, SIZE);
			i = 0;
		}
		else
			i++;
	}
	
	myatoi(string, i);
	return 0;
}

void myatoi(const char * st, int n)
{
	long int Integer = 0, pow;
	int i;
	for(i = n-1, pow = 1; i >= 0; i--, pow *= 10)
		Integer += (long)(st[i]-48)*pow;

	if(st[0] == '\0')
		printf("No string entered\n");
	else
		printf("The integer form of the entered string is: %ld\n", Integer);
}