#include <stdio.h>
void main(void)
{
	printf("Part (a) *%d*\n",100);
	printf("Part (b) %4X\n",138); /* To convert decimal to hexadecimal, 0-9 decimal are mapped 
	to 0-9 hex, 10-16 decimal are mapped to A-F hexadecimal. Say the number in decimal is 138
	so to convert into hex, divide by 16, the quotient is the leading digit and the remainder
	is the hex, so 138/16 = (Quotient=8, Remainder=10), the remainder in hex maps to 10~A, so the 
	equivalent in hex is 8A. */
	printf("Part (c) %10.3f\n",232.346);
	printf("Part (d) %12.2e\n",2.33e+002);
	printf("%-30s \n","This is the Output of part e");
}