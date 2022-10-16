#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 10
int get_num(const int str_len);
char * s_gets(char * st, int n);
int main(void)
{
	char string1[SIZE], string2[SIZE];
	int num, str_len;
	char word[SIZE];
	puts("Enter a line of input and input the maximum number of characters to be read:");
	s_gets(string1, SIZE);
	str_len = strlen(string1);
	puts("Enter the maximum characters to be read");
	num = get_num(str_len);
	strncpy(string2, string1, num);
	string2[num] = '\0';
	puts("The copied string is");
	puts(string2);
	return 0;
}

int get_num(const int str_len)
{
	int num;
	while((scanf("%d", &num) != 1) || num > str_len)
	{
		printf("Enter a valid integer between 1 to %d\n", str_len);
		while(getchar() != '\n')
			continue;
	}

	return num;
}