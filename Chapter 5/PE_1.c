#include<stdio.h>
const int SEC_PER_MIN = 60;
const int MIN_PER_HR = 60;
void main(void)
{
	float min,sec,hr;
	printf("Enter the number of minutes\n");
	printf("Enter 0 to exit.\n");
	scanf("%f",&min);
	while(min>0)
	{
		sec=SEC_PER_MIN*min;
		hr=min/MIN_PER_HR;
		printf("Time in seconds is: %10.2f\n",sec);
		printf("Time in hours is: %10.2f\n",hr);
		printf("Enter new input?\n");
		printf("Enter 0 to exit.\n");
		scanf("%f",&min);
	}
}	