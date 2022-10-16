#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTITL 41
#define MAXAUTL 31
#define MAXBKS 10

char * s_gets(char st[], int n);

struct book {
			 char title[MAXTITL];
			 char author[MAXAUTL];
			 float value;
			};

int main(void)
{
	struct book library[MAXBKS];
	int count = 0;
	int index, filecount;
	FILE * pbooks;
	int size = sizeof(struct book);

	if((pbooks = fopen("book.txt","a+b")) == NULL)
	{
		printf("Cannot open \"book.txt\"\n");
		exit(1);
	}

	rewind(pbooks);

	while(count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
	{
		if(count == 0)
			puts("Current content of \"books.txt\"\n");
		printf("%s by %s: $%0.2f\n", library[count].title, library[count].author, library[count].value);
		count++;
	}

	filecount = count;
	if(count == MAXBKS)
	{
		printf("The \"books.txt\" file is full\n");
		exit(2);
	}

	puts("Please add new titles:");
	puts("Press [enter] at the start of a newline to quit");
	while(count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
	{
		puts("Now enter the author name");
		s_gets(library[count].author, MAXAUTL);
		puts("Now enter the value");
		scanf("%f", &library[count].value);
		while(getchar() != '\n')
			continue;
		puts("Enter another title");
		puts("Press [enter] at the start of a newline to quit");
		count++;
	}

	if(count > 0)
	{
		puts("Here are the books in \"books.txt\" file");
		for(index = 0; index < count; index++)
			printf("%s by %s: $%0.2f", library[index].title, library[index].author, library[index].value);
		
		fwrite(&library[filecount], size, count - filecount, pbooks);
	}
	else
		printf("\nNo books? Too bad.\n");
	printf("\nBye\n");
	fclose(pbooks);

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
			while(getchar() != '\n')
				continue;
	}

	return ret_val;
}