#include <stdio.h>
int main(void)
{
	char ch;

	while((ch = getchar()) != '#')
	{
		if(ch == '\n')
			continue;
		
		printf("Step 1\n");
		
		switch(ch)
		{
			
			case 'c':
				continue;

			case 'b':
				break;

			case 'h':
				printf("Step 3\n");
				continue;
 			
 			default :
 				printf("Step 2\n");
 				printf("Step 3\n");
		}
		if(ch == 'b')
			break;
	}
	printf("Done!\n");	
	return 0;
}