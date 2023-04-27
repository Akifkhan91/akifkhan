#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LIM 10
#define SIZE 81
char * s_gets(char * st, int n);
char get_choice(void);
void print_string(const char st[][SIZE], const int rows);
void get_length(char * ptr[], const int rows);
void str_srt_ASCII(char * ptr[], const int rows);
void str_sort_first_word(char st[][SIZE], const int rows);
int main(void)
{
	char strings[LIM][SIZE], * ptr[LIM];
	char ch;
	int nrows = 0;
	puts("Enter some strings(Enter EOF to quit entering)");
	while(nrows < LIM && s_gets(strings[nrows], SIZE) && strings[nrows][0] != EOF)
	{
		ptr[nrows] = strings[nrows];
		nrows++;
	}
	
	if(strings[0][0] != '\0')
	{
		ch = get_choice();

		switch(ch)
		{
			case 'a':
					print_string(strings, nrows);
					break;

			case 'b':
					str_srt_ASCII(ptr, nrows);
					break;

			case 'c':
					get_length(ptr, nrows);
					break;

			case 'd':
					str_sort_first_word(strings, nrows);
					break;
		}
	}
	else
		puts("No string entered");
}

char get_choice(void)
{
	char ch;
	printf("Enter a choice:\n");
	printf("a) Print all the original list of strings\n");
	printf("b) Print the strings in ASCII collating sequence\n");
	printf("c) Print strings in order of increasing length\n");
	printf("d) Print the strings in order of length of the first word\n");
	
	while((ch = getchar()) < 'a' || ch > 'd')
	{
		puts("Enter a valid choice");
		while(getchar() != '\n')
			continue;
	}
	return ch;

}

void print_string(const char st[][SIZE], const int nrows)
{
	int i;
	for(i = 0; i < nrows; i++)
		printf("%s\n", st[i]);
}

void get_length(char * ptr[], const int rows)
{
	int i, j;
	char * temp;
	for(i = 0; i < rows-1; i++)
	{
		for(j = i+1; j < rows; j++)
		{
			if(strlen(ptr[i]) > strlen(ptr[j]))
			{
				temp = ptr[i];
				ptr[i] = ptr[j];
				ptr[j] = temp;
			}
		}
	}
	for(i = 0; i < rows; i++)
		puts(ptr[i]);
}


void str_srt_ASCII(char * ptr[], const int rows)
{
	int i, j;
	char * temp;
	for(i = 0; i < rows-1; i++)
	{
		for(j = i+1; j < rows; j++)
		{
			if(strcmp(ptr[i], ptr[j]) > 0)
			{
				temp = ptr[i];
				ptr[i] = ptr[j];
				ptr[j] = temp;
			}
		}
	}
	
	for(i = 0; i < rows; i++)
		puts(ptr[i]);
}

void str_sort_first_word(char st[][SIZE], const int rows)
{
	char ch, word[rows][SIZE], * ptr[rows];
	int i, j;

	for(i = 0; i < rows; i++)
	{
		for(j = 0; j < SIZE-1; j++)
		{
			ch = st[i][j];
			if(isspace(ch))
				continue;

			else
			{
				word[i][j] = ch;
				if(word[i][j+1] == ' ')
					break;
			}
			word[i][SIZE-1] = '\0';
		}
	}

	for(i = 0; i < rows; i++)
		ptr[i] = word[i];

	get_length(ptr, rows);
}