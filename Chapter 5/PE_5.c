#include <stdio.h>
void main(void)
{
	int n,count,sum;
	n=0;
	sum=0;

	printf("Enter the number upto which the sum is required:");
	scanf("%d",&count);
	while(n++<count)
	{
		sum=sum+n;
	}
	printf("The sum is = %5d\n",sum);
}