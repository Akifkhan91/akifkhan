#include <stdio.h>
#include <ctype.h>
void main(void)
{
	char ch;
	printf("Enter a lowercase character\n");
	printf("And i'll name an animal starting with it\n");
	printf("Press # to quit\n");

	while((ch = getchar()) != '#')
	{
		if(ch == '\n')
			continue;

		if(islower(ch))
		{
			switch(ch)
			{
				case 'a' :
				printf("This is animal \'a\'\n");
				break;

				case 'b' :
				printf("This is animal \'b\'\n");

				case 'c' :
				printf("This is animal \'c\'\n");
				break;

				default  :
				printf("This is animal \'default\'\n");
			}
		}
		
		else
			printf("I accept only lowercase characters!\n");

		while(getchar() != '\n')
			continue;
	
		printf("Enter a new character\n");
		printf("Press # to quit.\n");
	}
}