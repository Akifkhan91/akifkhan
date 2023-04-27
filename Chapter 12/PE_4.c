#include <stdio.h>

static int count = 0;

void CallThisFunc(void);

int main(void)
{
	int call;
	printf("Enter number of times CallThisFunc should be called\n");
	scanf("%d", &call);
	for(int i = 0; i < call; i++)
		CallThisFunc();

	printf("The CallThisFunc was called %d times\n", count);

	return 0;
}

void CallThisFunc(void)
{
	count++;
}