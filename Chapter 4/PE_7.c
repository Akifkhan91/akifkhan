#include <stdio.h>
#include <float.h>
void main(void)
{
	float var1=1.0f/3.0f;
	double var2=1.0/3.0;
	printf("Displaying float to 4, 12, 16 digit precision respectively       %0.4f %0.12f %0.16f\n",var1,var1,var1);
	printf("Displaying double to 4, 12, 16 digit precision respectively      %0.4lf %0.12lf %0.16lf\n",var2,var2,var2);
	printf("The float and double precision for this machine are respectively %d %d\n",FLT_DIG,DBL_DIG);
}