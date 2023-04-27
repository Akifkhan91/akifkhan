#include <stdio.h>
#include <string.h>
void clear_string(void);
double sum(double x, double y);
double diff(double x, double y);
double multiply(double x, double y);
double divide(double x, double y);

double (* pf[4])(double x, double y);
int main(void)
{
	char ch;
	double num1, num2;
	puts("Enter two floating point numbers");
	scanf("%lf %lf", &num1, &num2);

	clear_string();
	
	puts("Select a choice(Empty line to quit)");
	puts("a) Add          b) Subtract");
	puts("c) Multiply     d) Divide");
	
	while((ch = getchar()) != '\n')
	{
		clear_string();

		if(strchr("abcd", ch) == NULL)
		{
			puts("Select a valid menu choice");
			continue;
		}
		
		switch(ch)
		{
			case 'a': pf[0] = sum; printf("The sum is %lf\n",pf[0](num1, num2)); break;
			case 'b': pf[1] = diff; printf("The diff is %lf\n",pf[1](num1, num2)); break;
			case 'c':pf[2] = multiply; printf("The multiplication is %lf\n",pf[2](num1, num2)); break;
			case 'd':pf[3] = divide; printf("The division is %lf\n",pf[3](num1, num2)); break;
		}

	puts("Select a choice(Empty line to quit)");
	puts("a) Add          b) Subtract");
	puts("c) Multiply     d) Divide");
	
	}
	
	return 0;
}

double sum(double x, double y)
{
	return (x + y);
}

double diff(double x, double y)
{
	return (x - y);
}

double multiply(double x, double y)
{
	return (x * y);
}

double divide(double x, double y)
{

	return (x/y);
}

void clear_string(void)
{
	while(getchar() != '\n')
		continue;
}