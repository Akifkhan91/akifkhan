#include <stdio.h>
#include <ctype.h>
#define SIZE 81
char * s_gets(char * st, int n);
void rem_space(const char * st1, char * st2);
int main(void)
{
	char string[SIZE], no_space_str[SIZE];
	puts("Enter a string(Enter newline to quit)");
	while(s_gets(string, SIZE) && string[0] != '\0')
	{
		rem_space(string, no_space_str);
		puts("The string without any spaces is:");
		puts(no_space_str);
		puts("Enter a string(Enter newline to quit)");
	}
	return 0;
}

void rem_space(const char * st1, char * st2)
{
	int i = 0, j = 0;
	while(st1[i] != '\0')
	{
		if(isblank(st1[i]))
			i++;
		else
		{
			st2[j] = st1[i];
			i++;
			j++;
		}
	}
}
