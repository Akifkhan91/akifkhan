#include <stdio.h>
#include <string.h>
#define SIZE 80
#define BUGSIZE 13
char * s_gets(char * string, int n);
void main(void)
{
	char flower[SIZE];
	char addon[] = "s smell like old shoes";
	char bug[BUGSIZE];

	int available;
	puts("What is your favorite flower?");
	s_gets(flower, SIZE);
	
	if(strlen(addon) + strlen(flower) + 1 <= SIZE)
		strcat(flower, addon);

	puts(flower);
	puts("What is your favorite bug?");
	s_gets(bug, BUGSIZE);
	available = BUGSIZE - strlen(bug) - 1;
	strncat(bug, addon, available);
	puts(bug);
}

char * s_gets(char * string, int n)
{
	char * ret_val;
	int i = 0;
	ret_val = fgets(string, n, stdin);
	if(ret_val)
	{
		while(string[i] != '\n' && string[i] != '\0')
			i++;

		if(string[i] == '\n')
			string[i] = '\0';
		else
			while(getchar() != '\n')
				continue;
	}
	return ret_val;
}