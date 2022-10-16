#include <stdio.h>
void main(void)
{
	printf("%6.4d\n",123);
	printf("%*o\n",10,140);
	printf("%2c\n",'$');
	printf("%+*.*f\n",6,2,3.13);
	printf("%-7.5s\n","Alackazam!");
}