#include <stdio.h>
void main(void)
{
	const float INTEREST = 8.0f;
	const float AMT_WITHDRAWN = 100000.0f;
	const float PRINCIPAL = 1000000.0f;
	float current_amt = PRINCIPAL;
	int year = 0;

	do
	{
		year++;
		current_amt += current_amt*INTEREST/100 - AMT_WITHDRAWN;
		printf("year = %d current_amt = %f\n",year, current_amt);
	}while((int)current_amt > 0);
	printf("The value of Chukie's bank balance is %f in %d years\n",current_amt,year);

}