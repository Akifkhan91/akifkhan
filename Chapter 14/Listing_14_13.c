#include <stdio.h>

#define FUNDLEN 50
#define N 2

struct funds {
			  char bank[FUNDLEN];
			  double bankfund;
			  char save[FUNDLEN];
			  double savefund;
			 };

double totalfunds(const struct funds money[], int n);

int main(void)
{
	struct funds jones[N] = {
							 {"Bank of India", 1000.0, "Akif Khan", 500.0},
							 {"Bank of Baroda", 1000.0, "Zahra Sherwani", 500.0}
							};

	printf("The jonses have a total of %0.2f\n", totalfunds(jones, N));
	return 0;
}

double totalfunds(const struct funds money[], int n)
{
	double sum = 0.0;
	for(int i = 0; i < n; i++)
		sum += money[i].bankfund + money[i].savefund;
	
	return sum;
}