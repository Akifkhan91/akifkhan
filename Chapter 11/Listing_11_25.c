#include <stdio.h>
#include <string.h>
#define SIZE 40
#define LIM 5
char * s_gets(char * st, int n);
void main(void)
{
	char qstrings[LIM][SIZE];
	char temp[SIZE];
	int i = 0;
	printf("Enter %d strings starting with \"q\" and I will display them\n", LIM);
	while(i < LIM && s_gets(temp, SIZE))
	{
		if(temp[0] != 'q')
			printf("Entered string: %s, does not begin with q\n", temp);
		else
		{
			strcpy(qstrings[i], temp);
			i++;
		}
	}
	
	printf("The entered strings are:\n");
	for(i = 0; i < LIM; i++)
		puts(qstrings[i]);
}

char * s_gets(char * st, int n)
{
	char * ret_val;
	int i = 0;
	ret_val = fgets(st, n, stdin);
	if(ret_val)
	{
		while(st[i] != '\0' && st[i] != '\n')
			i++;
		
		if(st[i] == '\n')
			st[i] = '\0';
		
		else
		{
			while(getchar() != '\n')
				continue;
		}
	}

	return ret_val;
}