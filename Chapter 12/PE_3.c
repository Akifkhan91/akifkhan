// pe12-2b.c
// compile with pe12-2a.c
#include <stdio.h>
int set_mode(int mode, int prev_mode);
void get_info(int mode);
void show_info(double distance, double FuelConumption, int mode);
int main(void)
{

	int mode, prev_mode = 0;
	
	printf("Enter 0 for metric mode, 1 for US mode: ");
	scanf("%d", &mode);
	while(mode >= 0)
	{
		mode = set_mode(mode, prev_mode);
		prev_mode = mode;
		get_info(mode);
		printf("Enter 0 for metric mode, 1 for US mode");
		printf(" (-1 to quit): \n");
		scanf("%d", &mode);
	}
	printf("Done.\n");
	return 0;
}

int set_mode(int mode, int prev_mode)
{
	if(mode == 0 || mode == 1)
		return mode;
	else
	{
		printf("Invalid mode specified. Mode %d(%s) used\n", prev_mode, "EU");
		return prev_mode;
	}
}

void get_info(int mode)
{
	double distance, FuelConumption;
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
	show_info(distance, FuelConumption, mode);
}

void show_info(double distance, double FuelConumption, int mode)
{
	if(mode == 0)
		printf("Fuel consumption is %0.2lf litres per 100 km\n", FuelConumption/distance);
	else
		printf("Fuel consumption is %0.2lf miles per gallon km\n", FuelConumption/distance);
}
