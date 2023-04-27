#include <stdio.h>
#define FUNDLEN 50
struct funds {
			  char bankname[FUNDLEN];
			  double bank;
			  char savename[FUNDLEN];
			  double save;
			 };

double sum(const struct funds money);

int main(void)
{
	struct funds stan = {
						 "Bank of India",
						 1000.0,
						 "Akif Khan",
						 470.0
						};

	printf("The total funds are %0.2f\n", sum(stan));
	return 0;
}

double sum(const struct funds money)
{
	return(money.bank + money.save);
}