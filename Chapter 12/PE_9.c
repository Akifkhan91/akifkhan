#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 20
int main(void)
{
	int num_words, i = 0;
	char temp[MAX_LEN];
	printf("How many words you wish to enter?\n");
	scanf("%d", &num_words);

	char ** char_ptr = (char **)malloc(num_words * sizeof(char *));
	printf("Enter %d words now:\n", num_words);
	
	while(i < num_words)
	{
		scanf("%s", temp);
		char_ptr[i] = (char *)malloc(strlen(temp) * sizeof(char));
		strcpy(char_ptr[i],temp);
		i++;

	}
	printf("Here are your words:\n");
	for(int i = 0; i < num_words; i++)
		printf("%s\n", char_ptr[i]);

	free(char_ptr);

	return 0;
}