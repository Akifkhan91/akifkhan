#include <stdio.h>
#include <string.h>

#define NLEN 30

struct name {
			 char first[NLEN];
			 char last[NLEN];
			 int letters;
			};

void getinfo(struct name *);
void makeinfo(struct name *);
void showinfo(const struct name *);
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
	printf("Enter the first name\n");
	s_gets(pst->first, NLEN);
	printf("Enter the last name\n");
	s_gets(pst->last, NLEN);
}

void makeinfo(struct name * pst)
{
	pst->letters = strlen(pst->first) + strlen(pst->last);
}

void showinfo(const struct name * pst)
{
	printf("The name \"%s %s\", contains %d letters", pst->first, pst->last, pst->letters);
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