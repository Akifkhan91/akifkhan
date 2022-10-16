#include <stdio.h>
int main(void)
{
	char ch;
	int sub_period = 0;
	int sub_excl = 0;
	printf("Enter some input\n");
	printf("Press # to quit\n");

	while((ch = getchar()) != '#')
	{
		switch(ch)
		{
			case '.':
				putchar('!');
				sub_period++;
				break;

			case '!':
				printf("!!");
				sub_excl++;
				break;

			default :
				putchar(ch);
		}
	}
	printf("\nThere were %d period substitutions and ", sub_period);
	printf("%d exclamtion substitutions\n", sub_excl);
	return 0;
}