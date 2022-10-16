#include <stdio.h>
#include <ctype.h>
int main(void)
{
	char ch;
	int newline_ch = 0;
	int space = 0;
	long int oth_ch = 0L;

	printf("Enter some input!\n");
	printf("Press # + [Enter] to quit.\n");

	while((ch = getchar()) != '#')
	{
		if(isgraph(ch))
			oth_ch++;

		else if(isspace(ch) && ch != '\n')
			space++;

		else
			newline_ch++;
	}

	printf("Spaces | Newline | Other Character\n");
	printf("%3d %8d %12ld\n",space, newline_ch, oth_ch);
	return 0;
}