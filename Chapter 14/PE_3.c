#include <stdio.h>
#include <string.h>

#define MAXTITL 50
#define MAXAUTL 50
#define MAXBKS 100

struct book {
			 char title[MAXTITL];
			 char author[MAXAUTL];
			 float value;
			};

char * s_gets(char st[], int n);
void sort_by_value(struct book library[], int nbooks);
void sort_by_alphabetical(struct book library[], int nbooks);

int main(void)
{
	struct book library[MAXBKS];
	struct book * pts;

	int count = 0;
	puts("Enter book title(empty line to quit)");
	while(count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
	{
		puts("Now enter the author name");
		s_gets(library[count].author, MAXAUTL);
		puts("Enter the value");
		scanf("%f", &library[count].value);
		while(getchar() != '\n')
			continue;
		count++;
		if(count < MAXBKS)
			puts("Enter book title(empty line to quit)");
	}

	if(count > 0)
	{
		
		puts("The books entered are:");
		for(int i = 0; i < count; i++)
			printf("%s by %s: $%0.2f\n", library[i].title, library[i].author, library[i].value);

		puts("The books in order of increasing value are");
		sort_by_value(library, count);
		for(int i = 0; i < count; i++)
			printf("%s by %s: $%0.2f\n", library[i].title, library[i].author, library[i].value);

		puts("The books in alphabetical order are");
		sort_by_alphabetical(library, count);
		for(int i = 0; i < count; i++)
			printf("%s by %s: $%0.2f\n", library[i].title, library[i].author, library[i].value);

	}

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
			while(getchar() != '\0')
				continue;
	}

	return ret_val;
}

void sort_by_value(struct book library[], int nbooks)
{
	float temp;
	char copy_title[MAXTITL]; 
	char copy_author[MAXAUTL];
	for(int i = 0; i < nbooks-1; i++)
	{
		for(int j = i+1; j < nbooks; j++)
		{
			if(library[i].value > library[j].value)
			{
				temp = library[i].value;
				library[i].value = library[j].value;
				library[j].value = temp;

				strcpy(copy_title, library[i].title);
				strcpy(library[i].title, library[j].title);
				strcpy(library[j].title, copy_title);
				
				strcpy(copy_author, library[i].author);
				strcpy(library[i].author, library[j].author);
				strcpy(library[j].author, copy_author);

			}
		}
	}
}

void sort_by_alphabetical(struct book library[], int nbooks)
{
	float temp;
	char copy_title[MAXTITL]; 
	char copy_author[MAXAUTL];
	for(int i = 0; i < nbooks-1; i++)
	{
		for(int j = i+1; j < nbooks; j++)
		{
			if(strcmp(library[i].title, library[j].title) > 0)
			{
				temp = library[i].value;
				library[i].value = library[j].value;
				library[j].value = temp;

				strcpy(copy_title, library[i].title);
				strcpy(library[i].title, library[j].title);
				strcpy(library[j].title, copy_title);
				
				strcpy(copy_author, library[i].author);
				strcpy(library[i].author, library[j].author);
				strcpy(library[j].author, copy_author);

			}
		}
	}
}