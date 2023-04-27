#include <stdio.h>
#include <string.h>
#define MAXTITL 41
#define MAXAUTL 31
#define MAXBKS 100
char * s_gets(char st[], int n);

struct book
{
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

int main(void)
{
	struct book library[MAXBKS];
	int count = 0;
	int index;

	printf("Enter the book title(s)\n");
	printf("Press [enter] at newline to quit\n");
	while(count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
	{
		printf("Enter the name of the author\n");
		s_gets(library[count].author, MAXTITL);
		printf("Enter the value of the book\n");
		scanf("%f", &library[count].value);
		
		while(getchar () != '\n')
			continue;

		count++;
		printf("Enter next title\n");
	}

	if(count > 0)
	{
		printf("Here is a list of books\n");
		for(index = 0; index < count; index++)
			printf("%s by %s: $%0.2f\n", library[index].title, library[index].author, library[index].value);
	}

	else
		printf("No books? Too bad.\n");

	return 0;
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
		{
			while(getchar() != '\n')
			continue;
		}
	}

	return ret_val;
}