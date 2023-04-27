#include <stdio.h>
void main(void)
{
	int num1,num2,mod;
	printf("Enter an integer to serve as the second operand\n");
	scanf("%d",&num2);
	printf("Now enter the first operand:");
	scanf("%d",&num1);
	while(num1!=0)
	{
		mod=num1 % num2;
		printf("%d %% %d is %d\n",num1,num2,mod);
		printf("Enter the next number for thr first operand(<= 0 to quit):\n");
		scanf("%d",&num1);
	}
}