#include <stdio.h>
#include <string.h>
#define SIZE 81
char * s_gets(char * st, int n);
char * str_comp(char * st1, char * st2);
int main(void)
{
	char string1[SIZE], string2[SIZE], ch;
	char * ptr;
	puts("Enter the string to search from");
	s_gets(string1, SIZE);
	puts("Enter a character to search for inside the string(Enter newline to quit)");
	
	while(s_gets(string2, SIZE) && string2[0] != '\0')
	{
		puts("The pointer the first character in string1 is");
		printf("%p\n", string1);
		ptr = str_comp(string1, string2);
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

		puts("Enter a character to search for inside the string(Enter newline to quit)");
	}

	return 0;
}

char * str_comp(char * st1, char * st2)
{
	int j, count = 0;
	char * ret_val = NULL;

	for(j = 0; j < strlen(st1); j++)
	{
		if(st1[j] == st2[count])
		{
			count++;
			if(count == strlen(st2))
			{
				ret_val = st1 +j - count + 1;
				break;
			}
		}
	}

	return ret_val;
}