#include <stdio.h>
#define BASIC_PAY_1 8.75 //8.75 $/hr
#define BASIC_PAY_2 9.33 //9.33 $/hr
#define BASIC_PAY_3 10.00 //10.00 $/hr
#define BASIC_PAY_4 11.20 //11.20 $/hr
#define OVERTIME 1.5 //Times basic pay rate
#define TAX_RATE_1 15.0 //15% of the first 300$
#define TAX_RATE_2 20.0 //20% of the next 150$
#define TAX_RATE_3 25.0 //25% of the rest
#define SLAB_1 300.0
#define SLAB_2 450.0
#define BASE_HRS 40.0

float hours_worked(void);
float gross_pay_calc(float bp_rate, float overtime, float hours);
float tax_pay_calc(float gross_pay);
void display_menu(void);
int main(void)
{
	char choice;
	float hours;
	float gross_pay, taxes;

	display_menu();
	while((choice = getchar()) != '5')
	{	

		switch(choice)
		{
			case '1':
			hours = hours_worked();
			gross_pay = gross_pay_calc(BASIC_PAY_1, OVERTIME, hours);
			taxes = tax_pay_calc(gross_pay);
			printf("The gross_pay is %0.2f\nThe tax you have to pay is %0.2f\n",gross_pay,taxes);
			printf("Your net pay is %0.2f\n",gross_pay-taxes);
			break;

			case '2':
			hours = hours_worked();
			gross_pay = gross_pay_calc(BASIC_PAY_2, OVERTIME, hours);
			taxes = tax_pay_calc(gross_pay);
			printf("The gross_pay is %0.2f\nThe tax you have to pay is %0.2f\n",gross_pay,taxes);
			printf("Your net pay is %0.2f\n",gross_pay-taxes);
			break;

			case '3':
			hours = hours_worked();
			gross_pay = gross_pay_calc(BASIC_PAY_3, OVERTIME, hours);
			taxes = tax_pay_calc(gross_pay);
			printf("The gross_pay is %0.2f\nThe tax you have to pay is %0.2f\n",gross_pay,taxes);
			printf("Your net pay is %0.2f\n",gross_pay-taxes);
			break;

			case '4':
			hours = hours_worked();
			gross_pay = gross_pay_calc(BASIC_PAY_4, OVERTIME, hours);
			taxes = tax_pay_calc(gross_pay);
			printf("The gross_pay is %0.2f\nThe tax you have to pay is %0.2f\n",gross_pay,taxes);
			printf("Your net pay is %0.2f\n",gross_pay-taxes);
			break;

			default:
			printf("Invalid choice! Please select an appropriate choice\n");
			display_menu();
			continue;
		}
		

	display_menu();
	while(getchar() != '\n')
		continue;
	}
	
	printf("Done!\n");
	return 0;
}

float hours_worked(void)
{
	float hours;
	printf("Enter the hours worked\n");
	scanf("%f",&hours);
	return hours;
}


float gross_pay_calc(float bp_rate, float overtime, float hours)
{
	float gross_pay = 0.0;
	if(hours > 0)
	{
		if(hours <= BASE_HRS)
			gross_pay = bp_rate*hours;
		else
			gross_pay = BASE_HRS*bp_rate + overtime*(hours - BASE_HRS)*bp_rate;
	}
	else
		printf("Enter a positive value of hours!\n");

	return gross_pay;
}

float tax_pay_calc(float gross_pay)
{
	float taxes;
	
	if(gross_pay <= SLAB_1)
		taxes = TAX_RATE_1*gross_pay/100;
	
	else if(gross_pay >= SLAB_1 && gross_pay <= SLAB_2)
		taxes = TAX_RATE_1*SLAB_1/100.0 + TAX_RATE_2*(gross_pay - SLAB_2)/100.0;

	else if(gross_pay >= SLAB_2)
		taxes = TAX_RATE_1*SLAB_1/100.0 + TAX_RATE_2*SLAB_2/100.0 + TAX_RATE_3*(gross_pay - SLAB_2)/100.0;

	return taxes;
}

void display_menu(void)
{
			printf("********************************************************************\n");
			printf("Enter the number corresponding to the desired pay rate or action\n");
			printf("1) $8.75/hr \t\t\t2) $9.33/hr\n");
			printf("3) $10.00/hr\t\t\t4) $11.20/hr\n");
			printf("5) quit\n");
			printf("********************************************************************\n");	
}