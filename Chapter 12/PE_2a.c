#include <stdio.h>
#include <string.h>
#include "pe12-2a.h"
static char location[5];
void set_mode(int m)
{
	if(m == 0)
	{
		mode = m;
		strncpy(location, "EU",3);
	}
	else if(m == 1)
	{
		mode = m;
		strncpy(location, "US",3);
	}
	else
		printf("Invalid mode specified, Mode %d(%s) used\n", mode, location);
}

void get_info(void)
{
	if(mode == 0)
	{	
		printf("Enter distance traveled in kilometeres: ");
		scanf("%lf", &distance);
		printf("Enter fuel consumed in litres: ");
		scanf("%lf", &FuelConumption);
	}
	else
	{
		printf("Enter distance traveled in miles: ");
		scanf("%lf", &distance);
		printf("Enter fuel consumed in gallons: ");
		scanf("%lf", &FuelConumption);
	}

}


void show_info(void)
{
	if(mode == 0)
		printf("Fuel consumption is %0.2lf litres per 100 km\n", FuelConumption/distance);
	else
		printf("Fuel consumption is %0.2lf miles per gallon km\n", FuelConumption/distance);
}