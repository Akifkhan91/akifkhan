#include <stdio.h>
#include <inttypes.h>
void main(void)
{
	unsigned short int ch;
	printf("Enter the value of the character in ASCII\n");
	scanf("\n%hu",&ch);
	printf("The character of the ASCII code is %c\n",ch);
}