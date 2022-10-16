#include <stdio.h>
#define BOOK "War and Peace"
void main(void)
{
	float cost=12.99;
	float percent=80.0;
	printf("This copy of \"%s\" sells for $%2.2f\n",BOOK,cost);
	printf("That is %2.0f%% of list.\n",percent);
}