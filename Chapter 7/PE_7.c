#include <stdio.h>
#define BASIC_PAY 10.0 //10$/hr
#define OVERTIME 1.5 //Times basic pay rate
#define TAX_RATE_1 0.15 //15% of the first 300$
#define TAX_RATE_2 0.20 //20% of the next 150$
#define TAX_RATE_3 0.25 //25% of the rest
#define SLAB_1 300.0
#define SLAB_2 450.0

int main(void)
{
	float hours;
	float gross_pay, net_pay;
	float taxes;
	printf("Enter number of hours per week\n");

	while(scanf("%f", &hours) == 1)
	{
		if(hours > 0)
		{
			if(hours <= 40)
				gross_pay = hours*BASIC_PAY;
			
			else
				gross_pay = (40.0f + (hours - 40.0f)*OVERTIME)*BASIC_PAY;

			if(gross_pay <= SLAB_1)
				taxes = TAX_RATE_1*gross_pay;

			else if(gross_pay > SLAB_1 && gross_pay <= SLAB_2)
				taxes = TAX_RATE_1*SLAB_1 + TAX_RATE_2*(gross_pay - SLAB_1);

			else
				taxes = TAX_RATE_1*SLAB_1 + TAX_RATE_2*(SLAB_2 - SLAB_1) + 
						TAX_RATE_3*(gross_pay - SLAB_2);
		
		printf("The gross pay is %0.2f\n", gross_pay);
		printf("The taxes are %0.2f\n", taxes);
		printf("The net pay is %0.2f\n", gross_pay - taxes);

		printf("Contine? Press q to quit.\n");
		}
		else
			printf("Enter a postive value of hours worked!\n");
	}	

	return 0;
}