#include <stdio.h>
#define FUNDLEN 50
struct funds {
			  char bank[FUNDLEN];
			  double bankfund;
			  char save[FUNDLEN];
			  double savefund;
			 };

double sum(double x, double y);

int main(void)
{
	struct funds stan = {"Bank of India", 
						 1000.0,
						 "Akif Khan",	
						 470.0
						};

	printf("The total funds are %0.2f\n", sum(stan.bankfund, stan.savefund));

	return 0;
}

double sum(double x, double y)
{
	return (x+y);
}