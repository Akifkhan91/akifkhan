#include "diceroll.h"
#include <stdio.h>
#include <stdlib.h>

int roll_count = 0; // file scope variable with external linkage

static int rollem(int sides)	// static function defination, 
								// local to just this translation unit(this source code file)
{
	int roll;

	roll = rand() % sides + 1;
	++roll_count;	// counts function calls

	return roll;
}

int roll_n_dice(int dice, int sides)
{
	int d;
	int total = 0;
	if(sides < 2)
	{
		printf("No. of sides should be greater than 1\n");
		return -2;
	}
	if(dice < 1)
	{
		printf("No. of dice should be at least 1\n");
		return -1;
	}

	for(d = 0; d < dice; d++)
		total += rollem(sides);
	
	return total;
}