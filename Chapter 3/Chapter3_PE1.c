#include <stdio.h>
#include <inttypes.h>
#include <limits.h>
#include <float.h>
void main(void)
{
	int var_int;
	float var_flt,var_flt_overflow,var_flt_underflow;
	var_int=INT_MAX - 1;
	var_flt=FLT_MAX+1.0e5;
	var_flt_overflow=var_flt-FLT_MAX;
	var_flt_underflow=FLT_MIN/1.0e10;

	printf("Maximum Integer supported by this system is: %d\n",INT_MAX);
	printf("Value of Int max - 1: %d\n",var_int); 
	printf("Maximum Float supported by this system is: %e\n",FLT_MAX);
	printf("Overflow when 1.0e5 is added to FLT_MAX %e\n",var_flt_overflow);
	printf("Minimum Float supported by this system is: %e\n",FLT_MIN);
	printf("Underflow when divided by 1.0e10 %e\n",var_flt_underflow); 
}