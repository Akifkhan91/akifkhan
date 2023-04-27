#include <stdio.h>
#include <string.h>

#define NLEN 30

struct name {
			 char first[NLEN];
			 char last[NLEN];
			 int letters;
			};

struct name getinfo(void);
struct name makeinfo(struct name);
struct name showinfo(const struct name);
char * s_gets(char st[], int n);

int main(void)
{
	struct name person;

	person = getinfo();
	person = makeinfo(person);
	showinfo(person);

	return 0;
}

struct name getinfo(void)
{
	struct name temp;
	printf("Enter your first name\n");
	s_gets(temp.first, NLEN);
	printf("Enter your last name\n");
	s_gets(temp.last, NLEN);

	return temp;
}

struct name makeinfo(struct name info)
{
	info.letters = strlen(info.first) + strlen(info.last);

	return info;
}

struct name showinfo(const struct name info)
{
	printf("The name \"%s %s\", has %d letters\n", info.first, info.last, info.letters);
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