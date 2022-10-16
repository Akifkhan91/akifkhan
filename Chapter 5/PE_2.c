#include <stdio.h>
void main(void)
{
	int num, count;
	printf("Enter an integer\n");
	scanf("%d",&num);
	printf("%10d\n",num);
	count=num+10;
	while(num++<count)
		printf("%10d\n",num);
}