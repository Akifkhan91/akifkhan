#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(int argc, char * argv[])
{
	char ch;
	printf("Enter some input to format. ");
	puts("The command line options are:");
	puts("-p to print input as is");
	puts("-u to Map input to all uppercase");
	puts("-l to Map input to all lowercase");
	puts("Enter EOF command to quit");
	while((ch = getchar()) != EOF)
	{
	
	if(argc < 2)
		putchar(ch);
	
	else if(strcmp(argv[1], "-p") == 0)
		putchar(ch);
	
	else if(strcmp(argv[1], "-u") == 0)
		putchar(toupper(ch));
	
	else if(strcmp(argv[1], "-l") == 0)
		putchar(tolower(ch));
	
	else
		printf("Invalid input\n");
	}
	return 0;
}