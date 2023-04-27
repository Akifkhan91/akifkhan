#include <stdio.h>
void put1(const char *);
int put2(const char *);
void main(void)
{
	put1("If I'd as much memory");
	put1(" as I could spend,\n");
	printf("I count %d characters.\n", put2("I never would cry old"
		" chairs to mend."));
}

void put1(const char * string)
{
	while(*string) // common idiom, when *string=='\0', while condition is false
		putchar(*string++);
}

int put2(const char * string)
{
	int count = 0;
	while(*string)
	{
		putchar(*string++);
		count++;
	}
	putchar('\n');

	return count;
}