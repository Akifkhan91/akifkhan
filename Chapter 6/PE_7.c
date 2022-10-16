#include <stdio.h>
#include <string.h>
void main(void)
{
	int length, i;
	char word[40];
	
	printf("Enter a word!\n");
	scanf("%s",word);
	length = strlen(word);
	
	for(i = length - 1; i >= 0; --i)
		printf("%c",word[i]);

	printf("\n");
}



