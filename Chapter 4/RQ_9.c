#include <stdio.h>
void main(void)
{
	int a;
	float b1,b2;
	char c[20];
	char d1[10];
	char d2[10];
	printf("Enter the input for part (a)\n");
	scanf("%d",&a);
	printf("Enter the input for part (b1) & (b2)\n");
	scanf("%f %f",&b1,&b2);
	printf("Enter the input for part (c)\n");
	scanf("%s",c);
	printf("Enter the input for part (d)\n");
	scanf("%s %s",d1,d2);
	printf("Enter the input for part (e)\n");
	scanf("%*s %s",d2);
	printf("Part (a) is %15d\n",a);
	printf("Part (b) is %15f and %10E\n",b1,b2);
	printf("Part (c) is %15s\n",c);
	printf("Part (d) is %10s %5s\n",d1,d2);
	printf("Part (e) is %15s\n",d2);
}