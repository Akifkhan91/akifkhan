#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SLEN 30

struct name {
			 char * first;
			 char * last;
			 int letters;
			};

void getinfo(struct name *);
void makeinfo(struct name *);
void showinfo(const struct name *);
void cleanup(const struct name *);
char * s_gets(char st[], int n);

int main(void)
{
	struct name person;

	getinfo(&person);
	makeinfo(&person);
	showinfo(&person);
	return 0;
}

void getinfo(struct name * pst)
{
	char temp[SLEN];
	printf("Enter the first name\n");
	s_gets(temp, SLEN);
	pst->first = (char *)malloc(strlen(temp) + 1);
	strcpy(pst->first, temp);
	printf("Enter the last name\n");
	s_gets(temp, SLEN);
	pst->last = (char *)malloc(strlen(temp) + 1);
	strcpy(pst->last, temp);
}

void makeinfo(struct name * pst)
{
	pst->letters = strlen(pst->first) + strlen(pst->last);
}

void showinfo(const struct name * pst)
{
	printf("The name \"%s %s\", contains %d letters\n", pst->first, pst->last, pst->letters);
}

void cleanup(const struct name * pst)
{
	free(pst->first);
	free(pst->last);
}

char * s_gets(char st[], int n)
{
	char * ret_val;
	int i = 0;
	ret_val = fgets(st, n, stdin);
	if(ret_val)
	{
		while(st[i] != '\n' && st[i] != '\0')
			i++;

		if(st[i] == '\n')
			st[i] = '\0';
		else
			while(getchar() != '\n')
				continue;
	}

	return ret_val;
}