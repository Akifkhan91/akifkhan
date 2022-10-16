#include <stdio.h>
size_t STR_LEN(const char * s);
int main(void)
{
	int length;
	length = STR_LEN("This is awesome!");
	printf("There are %d characters in the string \"This is awesome!\"\n", length);
	return 0;
}

size_t STR_LEN(const char * s)
{
	int length = 0;
	while(*s)
	{
		length++;
		s++;
	}

	return length;
}