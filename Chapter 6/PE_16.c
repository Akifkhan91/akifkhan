#include <stdio.h>
#define PRINCIPAL 100.0f
#define R_SI 10
#define R_CI 5
void main(void)
{
	int year = 0;
	float amount_si, amount_ci;
	amount_si = amount_ci = PRINCIPAL;

	do
	{
		year++;
		amount_si += PRINCIPAL*R_SI/100;
		amount_ci += amount_ci*R_CI/100;  
	}while(amount_si > amount_ci);

	printf("Daphne's investment is %10.2f\n",amount_si);
	printf("Deirdre's investment is %10.2f\n",amount_ci);
	printf("In %d years\n",year);
}