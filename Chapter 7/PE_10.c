#include <stdio.h>
#define BASE_TAX 15
#define EXCESS_TAX 28
#define SINGLE 17850
#define HEAD_OF_HOUSE 23900
#define MARRIED_J 29750
#define MARRIED_SEP 14875
void display_tax(void);
int main(void)
{
	float tax_inc;
	float taxes;
	char category;
	display_tax();
	switch(category)
	{
		case 'A':

	}

	display_tax();

	return 0;
}

void display_tax(void)
{
	printf("The tax schedule is as follows\n");
	printf("***************************************************************\n");
	printf("Category\t\t\t\t\tTax\n");
	printf("***************************************************************\n");
	printf("A:\tSingle  \t\t\t\t\t%d%% of first $%d plus %d%% of excess\n",BASE_TAX,SINGLE,EXCESS_TAX);
	printf("B:\tHead of Household\t\t\t\t%d%% of first $%d plus %d%% of excess\n",BASE_TAX,HEAD_OF_HOUSE,EXCESS_TAX);
	printf("C:\tMarried, Joint\t\t\t\t\t%d%% of first $%d plus %d%% of excess\n",BASE_TAX,MARRIED_J,EXCESS_TAX);
	printf("D:\tMarried, Seperate\t\t\t\t%d%% of first $%d plus %d%% of excess\n",BASE_TAX,MARRIED_SEP,EXCESS_TAX);
	printf("***************************************************************\n");
	printf("Select your category to continue\n");
	printf("\n");
}