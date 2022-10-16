#include <stdio.h>
#define FUNDLEN 50

struct funds {
				char bank[FUNDLEN];
				double bankfund;
				char save[FUNDLEN];
				double savefund;
			 };

double sum(const struct funds *);

int main(void)
{
	struct funds stan = {"Bank of India",
						 1000.0,
						 "Akif Khan",
						 470.0
						};

	struct funds * money = &stan;	
	printf("The total funds are %0.2f\n", sum(money));

	return 0;
}

double sum(const struct funds * money)
{
	return(money->bankfund + money->savefund);
}