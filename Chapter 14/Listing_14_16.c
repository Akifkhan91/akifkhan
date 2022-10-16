#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LEN 81
char * s_gets(char st[], int n);
char showmenu(void);
void eatline(void);
void show(void (* fp)(char *), char * str);
void ToUpper(char *);
void ToLower(char *);
void Transpose(char *);
void Dummy(char *);

int main(void)
{
	char line[LEN];
	char copy[LEN];
	char choice;
	void (*pfun)(char *); // A pointer to a function which takes an input argument of char * (i.e. a string)
						  // and returns void
	puts("Enter a string(Empty line to quit)");
	while(s_gets(line, LEN) != NULL && line[0] != '\0')
	{
		while((choice = showmenu()) != 'n')
		{
			switch (choice)
			{
				case 'u': pfun = ToUpper;
						  break;
				case 'l': pfun = ToLower;
						  break;
				case 't': pfun = Transpose;
						  break;
				case '0': pfun = Dummy;
						  break;
			}
		}
		strcpy(copy, line);
		show(pfun, copy);
		puts("Enter a string(empty line to quit)");
	}

	puts("Bye");

	return 0;
}

char showmenu(void)
{
	char ans;
	puts("Enter menu choice");
	puts("u)	uppercase	l) lowercase");
	puts("t)	transpose	o) original case");
	puts("n) next string");
	ans = getchar();
	ans = tolower(ans);
	eatline();

	while(strchr("ulton", ans) == NULL)
	{
		puts("Please enter a u, l, t, o, n:");
		ans = tolower(getchar());
		eatline();
	}

	return ans;
}

void eatline(void)
{
	while(getchar() != '\n')
		continue;
}

void show(void (* fp)(char *), char * str)
{
	(*fp)(str);
	puts(str);
}

void ToUpper(char * st)
{
	while(*st)
	{
		*st = toupper(*st);
		st++;
	}
}

void ToLower(char * st)
{
	while(*st)
	{
		*st = tolower(*st);
		st++;
	}
}

void Transpose(char * st)
{
	while(*st)
	{
		if(isupper(*st))
			*st = tolower(*st);
		else if(islower(*st))
			*st = toupper(*st);

		st++;
	}
}

void Dummy(char * st)
{
	// Do nothing
}

char * s_gets(char st[], int n)
{
	char * ret_val;
	int i = 0;
	ret_val = fgets(st, n, stdin);
	if (ret_val)
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