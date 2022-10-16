#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int rand0(int sides);
int main(void)
{
	int sets;
	int sides, dice;
	int subtotal = 0;
	printf("Enter the number of sets(Press q to quit):\n");
	srand((unsigned int) time(0)); // randomizing seed
	while((scanf("%d", &sets) == 1) && sets > 0)
	{
		printf("How many sides and how many dice:\n");
		scanf("%d %d", &sides, &dice);
		if(sides < 2)
		{
			printf("Number of sides of die should be at least 2\n");
			printf("\nEnter the number of sets(Press q to quit):\n");
			continue;
		}
		else if(dice < 1)
		{
			printf("Number of die should be at least 1\n");
			printf("\nEnter the number of sets(Press q to quit):\n");
			continue;
		}
		else
		{
			printf("Here are %d sets of %d %d-sided throws:\n", sets, dice, sides);
			for(int i = 0; i < sets; i++)
			{
				for(int j = 0; j < dice; j++)
					subtotal += rand0(sides);

				printf("%d ", subtotal);
				subtotal = 0;
			}
		
		}
		printf("\nEnter the number of sets(Press q to quit):\n");
	}

	return 0;
}

int rand0(int sides)
{
	return rand() % sides + 1; 
}