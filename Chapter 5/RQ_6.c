#include<stdio.h>
#define FORMAT "%s! C is cool!\n"
int main(void)
{
	int num=10;
	printf(FORMAT,FORMAT); /*%s! C is cool! (The \n inside the second string is a non printing
											 character and will be printed)
						     ! C is cool!*/ 
	
	printf("%d\n",++num); //11
	printf("%d\n",num++); //11
	printf("%d\n",num--); //12
	printf("%d\n",num); //11
	return 0;
}