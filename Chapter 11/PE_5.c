#include <stdio.h>
#include <string.h>
#define SIZE 81
char * s_gets(char * st, int n);
char * str_comp(char * st1, const char c);
int main(void)
{
	char string1[SIZE], ch;
	char * ptr;
	puts("Enter the string to search from");
	s_gets(string1, SIZE);
	puts("Enter a character to search for inside the string(Enter newline to quit)");
	
	while((ch = getchar()) != '\n')
	{
		puts("The pointer the first character in string1 is");
		printf("%p\n", string1);
		ptr = str_comp(string1, ch);
		if(ptr != NULL)
		{
			puts("The pointer to the first matching character in string1 is:");
			printf("%p\n", ptr);
		}
		else
		{
			puts("No matching string found");
			printf("%p\n", ptr);
		}

		while(getchar() != '\n')
			continue;

		puts("Enter a character to search for inside the string(Enter newline to quit)");
	}

	return 0;
}

char * str_comp(char * st1, const char c)
{
	int j;

	for(j = 0; j < strlen(st1); j++)
	{
		if(st1[j] == c)
			return(st1 + j);
	}

	return NULL;
}