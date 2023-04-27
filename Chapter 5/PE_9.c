#include <stdio.h>
const float CELC_TO_K = 273.16f;
const float FARA_TO_C_SCALE = 5.0f/9.0f;
const float FARA_TO_C_FAC = 32.0f;
void Temperatures(double T);
void main(void)
{
	int rv_scanf;
	double Temp;
	printf("Enter the temperature in fahrenheit\n");
	printf("Enter a character to exit.\n");
	rv_scanf=scanf("%lf",&Temp);
	while(rv_scanf==1)
	{
		Temperatures(Temp);
		printf("Enter the temperature in fahrenheit\n");
		printf("Enter a character to exit.\n");
		rv_scanf=scanf("%lf",&Temp);
	}
}
void Temperatures(double T)
{
	double Celsius, Kelvin;
	Celsius=FARA_TO_C_SCALE*(T - FARA_TO_C_FAC);
	Kelvin=Celsius+273.16;
	printf("The temperature in Celsius is %10.2lf\n",Celsius);
	printf("The temperature in Kelvin is  %10.2lf\n",Kelvin); 
}