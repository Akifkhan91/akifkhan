#include <stdio.h>
#define SIZE 81
char * s_gets(char * st, int n);
int main(void)
{
	char string[SIZE];
	printf("Enter a string\n");
	s_gets(string, SIZE);
	printf("%s\n", string);
	return 0;
}

char * s_gets(char * st, int n)
{
	char * ret_val;
	ret_val = fgets(st, n, stdin);
	if(ret_val)
	{
		while(*st != '\n' && *st != '\0')
			st++;

		if(*st == '\n')
			*st = '\0';

		else
			while(getchar() != '\n')
				continue;
	}
	return ret_val;

}

