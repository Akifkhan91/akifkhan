#include <stdio.h>
#include <stdlib.h>
#define SLEN 81
int main(void)
{
	FILE * fp;
	char file[SLEN], ch;
	long int count, last;
	printf("Enter the name of the file to be processed\n");
	scanf("%80s", file);
	if((fp = fopen(file,"r")) != NULL)
	{
		fprintf(stderr,"Error in opening file\n");
		exit(EXIT_FAILURE);
	}
	fseek(fp, 0L, SEEK_END);
	last = ftell(fp);
	for(count = 1L; count <= last; count++)
	{
		fseek(fp, -count, SEEK_END);
		ch = getc(fp);
		putchar(ch);
	}

	return 0;
}