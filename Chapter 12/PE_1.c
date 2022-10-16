#include <stdio.h>
int get_val(void);
int main(void)
{
	int units;
	printf("How many pounds in a frikin of butter?\n");
	units = get_val();

	while(units != 56)
	{
		printf("No luck! Try again!\n");
		units = get_val();	
	}
	printf("You must had looked it up!\n");
	return 0;
}

int get_val(void)
{
	int val;
	while((scanf("%d", &val) != 1))
	{
		printf("Please enter an integer!\n");
		while(getchar() != '\n')
			continue;
	}
	return val;
}