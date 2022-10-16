#include <stdio.h>
void main(void)
{
	unsigned long Part_a=123456;
	int Part_b=138;
	float Part_c=2.33E+02;
	float Part_d=232.346;
	char Part_e[15]="abcdefghijklmn";
	printf("Part (a) %15lu\n",Part_a);
	printf("Part (b) %#4x\n",Part_b);
	printf("Part (c) %-12.2e\n",Part_c);
	printf("Part (d) %+10.3f\n",Part_d);
	printf("%8.8s\n",Part_e);

}