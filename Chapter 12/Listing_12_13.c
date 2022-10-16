#include <stdio.h>
#include "diceroll.h"
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int dice, roll;
	int sides;

	srand((unsigned int) time(0));
	printf("Enter the number of sides per die(Enter 0 to stop)\n");
	while(scanf("%d", &sides) == 1 && sides > 1)
	{
		int status;
		printf("How many dice?\n");
		if((status = scanf("%d", &dice)) !=1)
		{
			if(status == EOF)
				break;
			else
			{
				printf("Enter an integer\n");
				printf("Let's begin again\n");
				while(getchar() != '\n')
					continue;
				printf("How many sides per die(Enter 0 to stop)\n");
				continue;
			}
		}

		roll = roll_n_dice(dice, sides);
		printf("You have rolled a %d total dice using %d %d-sided dice\n", roll, dice, sides);

		printf("How many sides per die(Enter 0 to stop)\n");
	}

	printf("The rollem() function was called %d times\n", roll_count);
	return 0;
}