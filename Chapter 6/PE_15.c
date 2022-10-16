#include <stdio.h>
#include <string.h>
void main(void)
{
	int i = 0;
	int length;
	char line[255];
	printf("Enter a sentence!\n");
	scanf("%c",&line[i]);

	while(line[i] != '\n')
	{
		i++;
		scanf("%c",&line[i]);
	}
	
	line[i] = '\0';
	length = strlen(line);

	for(i = length-1; i >= 0; i--)
	{
		printf("%c",line[i]);
	}

	printf("\n");
}