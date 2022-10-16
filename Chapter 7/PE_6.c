#include <stdio.h>
int main(void)
{
	char ch;
	char prev;
	int count = 0;

	while((ch = getchar()) != '#')
	{
		if(ch == 'e')
		{
			prev = ch;
			continue;
		}

		if(prev == 'e' && ch == 'i')
			count++;

		prev = ch;
	}	

	printf("There are %d ei in the input\n",count);
	return 0;
}