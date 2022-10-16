#include <stdio.h>
char * first_space(char * str);
int main(void)
{
	char string[] = "Mendonza Grape";
	char * ptr; 
	ptr = first_space(string);
	puts("The string is:");
	puts(string);
	puts("The pointer to the first character is:");
	printf("%p\n", &string[0]);
	puts("The pointer to the first space is(Returns NULL pointer if no space present)");
	printf("%p\n", ptr);
	
	return 0;
}

char * first_space(char * str)
{
	char * ptr = NULL;
	while(*str != ' ' && *str != '\0')
		str++;

	if(*str == ' ')
		return str;

	else
		return ptr;
}