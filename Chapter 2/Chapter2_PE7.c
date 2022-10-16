#include<stdio.h>
void Smile_fn(void);
void main(void)
{
	Smile_fn();
	Smile_fn();
	Smile_fn();
	printf("\n");
	Smile_fn();
	Smile_fn();
	printf("\n");
	Smile_fn();
	printf("\n");
}

void Smile_fn(void)
{
	printf("Smile!");
}