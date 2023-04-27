#include <stdio.h>
extern int count; // reference declaration, as count is of external linkage

static int total = 0; // static variable, internal linkage
void accumulate(int k)
{
	static int subtotal = 0;
	if(k <= 0)
	{
		printf("loop cycle %d\n", count);
		printf("subtotal: %d, total: %d\n", subtotal, total);
		subtotal = 0;
	}
	else
	{
		subtotal += k;
		total += k;
	}

}