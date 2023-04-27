#include <stdio.h>
#include <string.h>
#define LIM 5
#define SIZE 40
#define TARGSIZE 7
char * s_gets(char * st, int n);
void main(void)
{
	char qwords[LIM][TARGSIZE];
	char temp[SIZE];
	int i = 0;

	puts("Enter words beggining with \"q\"");

	while(i < LIM && s_gets(temp, SIZE))
	{
		if(temp[0] != 'q')
			puts("Entered string doesn't begin with \"q\"");
		
		else
		{
			strncpy(qwords[i], temp, TARGSIZE-1);
			qwords[i][TARGSIZE-1] = '\0';
			i++;
		}
	}
	puts("The entered strings are: ");

	for(i = 0; i < LIM; i++)
		puts(qwords[i]);

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
			while(getchar() != '\n')
				continue;
	}

	return ret_val;
}