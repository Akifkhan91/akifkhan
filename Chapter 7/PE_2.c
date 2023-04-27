#include <stdio.h>
#include <ctype.h>
int main(void)
{
	char ch;
	int char_count = 0;
	printf("Enter some input.\n");
	printf("And i will give you the ASCII value of each characater.\n");
	printf("Enter # to quit.\n");


	while((ch = getchar()) != '#')
	{
		char_count++;
		printf("%c --> %d\t",ch, ch);

		if(char_count % 8 == 0)
			printf("\n");
	}
	
	printf("\n");
	printf("There are %d number of characters\n",char_count);
	return 0;
}