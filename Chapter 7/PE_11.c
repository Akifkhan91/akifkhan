#include <stdio.h>
#define COST_ARTICHOKE 2.05
#define COST_BEET 1.15
#define COST_CARROT 1.09
#define DISCOUNT_PER 5.00
#define MIN_ORDER_FOR_DISC 100.00
#define COST_SHIP_A 6.50
#define COST_SHIP_B 14.00
#define EXCESS_SHIP_COST 0.50
#define EXCESS_WEIGHT 20.00
void display_menu(void);
void main(void)
{
	float lb_artichoke, lb_beet, lb_carrot;
	float tot_artichoke, tot_beet,tot_carrot;
	float tot_weight;
	float discount, shipping;
	float total_charges, grand_total;
	char choice;
	display_menu();
	
	tot_artichoke = tot_beet = tot_carrot = 0.0;
	while((choice = getchar()) != 'q')
	{
		switch(choice)
		{
			case 'a':
			case 'A':
			printf("Enter pounds of artichokes\n");
			scanf("%f",&lb_artichoke);
			tot_artichoke += lb_artichoke;
			break;

			case 'b':
			case 'B':
			printf("Enter pounds of beets\n");
			scanf("%f",&lb_beet);
			tot_beet += lb_beet;
			break; 

			case 'c':
			case 'C':
			printf("Enter pounds of carrots\n");
			scanf("%f",&lb_carrot);
			tot_carrot += lb_carrot;
			break;

			default:
			printf("Not a valid option! Please enter again!\n");
		}
		while(getchar() != '\n')
			continue;

		display_menu();
	}

	total_charges = tot_artichoke*COST_ARTICHOKE + tot_beet*COST_BEET + tot_carrot*COST_CARROT;

	if(total_charges >= MIN_ORDER_FOR_DISC)
		discount = DISCOUNT_PER*total_charges/100.0;
	else
		discount = 0.0;

	tot_weight = tot_artichoke + tot_beet + tot_carrot;

	if(tot_weight != 0)
	{
		if(tot_weight <= COST_SHIP_A)
			shipping = COST_SHIP_A;

		else if(tot_weight > COST_SHIP_A && tot_weight < COST_SHIP_B)
			shipping = COST_SHIP_B;

		else
			shipping = COST_SHIP_B + (tot_weight - EXCESS_WEIGHT)*EXCESS_SHIP_COST;
	}
	else
		shipping = 0.0;
	
	printf("Here is your bill\n");
	printf("**************************************************\n");
	printf("Artichokes:%20.2f lb\n",tot_artichoke);
	printf("Beets:%25.2f lb\n",tot_beet);
	printf("Carrots:%23.2f lb\n",tot_carrot);
	printf("Cost of Artichokes:%12.2f $\n",tot_artichoke*COST_ARTICHOKE);
	printf("Cost of Beets:%17.2f $\n",tot_beet*COST_BEET);
	printf("Cost of Carrots:%15.2f $\n",tot_carrot*COST_CARROT);
	printf("Total charges:%17.2f $\n",total_charges);
    printf("Discount:%22.2f $\n",discount);
    printf("Shipping charges:%14.2f $\n",shipping);
    printf("Grand total:%19.2f $\n",total_charges - discount + shipping);
}

void display_menu(void)
{
	printf("The cost of vegetables is as follows\n");
	printf("*******************************************************************\n");
	printf("Vegetables\t\t\tCost\n");
	printf("*******************************************************************\n");
	printf("a) Artichokes\t\t\t$%f\n",COST_ARTICHOKE);
	printf("b) BEETS     \t\t\t$%f\n",COST_BEET);
	printf("c) CARROTS   \t\t\t$%f\n",COST_CARROT);
}