#include <stdio.h>
#define MAXTITL 41
#define MAXAUTL 31

struct book {
			 char title[MAXTITL];
			 char author[MAXAUTL];
			 float value;
			};

int main(void)
{
	struct book readfirst;
	float score;

	printf("Enter test score: \n");
	scanf("%f", &score);

	if(score >= 84)
		readfirst = (struct book){"The orphan master's son", "Adam Jhonson", 29.99};
	else
		readfirst = (struct book){"Beloved", "Toni Morrison", 19.99};

	printf("Your assigned reading:\n");
	printf("%s by %s: %0.2f\n", readfirst.title, readfirst.author, readfirst.value);

	return 0;
}