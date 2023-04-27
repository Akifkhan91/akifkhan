#include <stdio.h>
void main(void)
{
	int i;
	char letters[26];
	for(i=0;i<26;i++)
		letters[i]=97+i;
	
	for(i=0;i<26;i++)
		printf("%c",letters[i]);

	printf("\n");
}