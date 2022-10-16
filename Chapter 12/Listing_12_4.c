#include <stdio.h>
int units = 0;
void critic(void);

int main(void)
{
	extern int units; // Optional declaration

	printf("How many pounds to a firkin of butter?\n");
	scanf("%d", &units);
	while(units != 56)
		critic();

	printf("You must had looked it up!\n");
	return 0;
}

void critic(void)
{
	// Optional decleration omitted

	printf("No luck, my friend. Try again.\n");
	scanf("%d", &units);
}

