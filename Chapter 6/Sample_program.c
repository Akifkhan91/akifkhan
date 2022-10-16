#include <stdio.h>
#include <math.h>
void main(void)
{
	double pi_response;
	printf("Enter the value of pi!\n");
	scanf("%lf",&pi_response);
	while(fabs(M_PI-pi_response)>0.001)
	{
		printf("Not good enough! Enter a new response\n");
	}
	printf("This is a good response\n");
}
