#include <stdio.h>
#define PERIOD '.'
#define EXCLAMATION '!'
int main(void)
{
	char ch;
	int sub_period = 0;
	int sub_excl = 0;
	printf("Enter some input.\n");
	printf("Press # to quit.\n");

	while((ch = getchar()) != '#')
	{

		if(ch == PERIOD)
		{
			putchar(EXCLAMATION);
			sub_period++;
		}

		else if(ch == EXCLAMATION)
		{
			printf("%c%c", EXCLAMATION, EXCLAMATION);
			sub_excl++;	
		}

		else
			putchar(ch);

	}	

	printf("\nThere were %d period substitutions and ", sub_period);
	printf("%d exclamtion substitutions\n", sub_excl);
	return 0;
}