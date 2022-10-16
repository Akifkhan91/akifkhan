#include <stdio.h>
#include <ctype.h>
int main(void)
{
	char ch;
	int n_punc = 0, n_upp_case = 0, n_low_case = 0, n_digit = 0;
	int n_words = 0;
	puts("Enter some lines(Input EOF command to quit)");
	while((ch = getchar()) != EOF)
	{
		while(!isspace(ch))
		{
			if(isdigit(ch))
				n_digit++;
			else if(ispunct(ch))
				n_punc++;
			else if(isupper(ch))
				n_upp_case++;
			else if(islower(ch))
				n_low_case++;	

			ch = getchar();
		}
		n_words++;
	}
	printf("The number of punctuation characters are = %d\n", n_punc);
	printf("The number of upper case characters are = %d\n", n_upp_case);
	printf("The number of lower case characters are = %d\n", n_low_case);
	printf("The number of digit characters are = %d\n", n_digit);
	printf("The number of words are = %d\n", n_words);
	return 0;
}