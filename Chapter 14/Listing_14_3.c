#include <stdio.h>
#define LEN 20
const char * msgs[5] = {" Thank you for the wonderful evening, ",
						"You certainly prove that a ",
						"is a special kind of a guy. We must get together",
						"over a delicious ",
						" and have a few laughs"
						};

struct names {
			  char first[LEN];
			  char last[LEN];
			 };

struct guy {
			struct names handle;
			char favfood[LEN];
			char job[LEN];
			float income;
		   };

int main(void)
{
	struct guy fellow = {
						 {"Akif", "Khan"},
						 "Pav Bhaji",
						 "Scientist",
						 70000.0
						};

	printf("Dear %s, \n\n\n", fellow.handle.first);
	printf("%s%s.\n", msgs[0], fellow.handle.first);
	printf("%s%s\n", msgs[1], fellow.job);
	printf("%s", msgs[2]);
	printf("%s%s%s", msgs[3], fellow.favfood, msgs[4]);
	if(fellow.income > 100000.0)
		puts("!!");
	else if(fellow.income > 60000.0)
		puts("!");
	else
		puts(".");

	printf("\n%40s%s\n", " ", "See you soon,");
	printf("\n%40s%s\n", " ", "Shalala");

	return 0;
}