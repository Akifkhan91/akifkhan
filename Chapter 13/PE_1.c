#include <stdio.h>
#include <stdlib.h>
#define SLEN 81
char * s_gets(char st[], int n);
int main(void)
{
	char ch;
	FILE * fp;
	unsigned long int count = 0;
	char file_name[SLEN];

	puts("Enter a file name");
	while(s_gets(file_name, SLEN) == NULL)
		continue;

	if((fp = fopen(file_name,"w")) == NULL)
	{
		printf("Unable to open file\n");
		exit(EXIT_FAILURE);
	}
	puts("Enter the contents of file");

	while((ch = getc(fp)) != '\n')
	{
		putc(ch, stdout);
		count++;
	}
	fclose(fp);
	printf("There are %lu characters in the file %s\n", count, file_name);
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
		
		if(st[i] == '\0')
			while(getchar() != '\n')
				continue;
	}
	return ret_val;
}