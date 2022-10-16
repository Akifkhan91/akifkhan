#include <stdio.h>
#include <stdlib.h>
int main(int argc, char * argv[])
{
	int i;
	double power;
	
	if(argc < 2)
		printf("Usage %s is a postive number\n", argv[0]);
	else if(atof(argv[1]) && atoi(argv[2]))
	{
		for(i = 1, power = 1.0; i <= atoi(argv[2]); i++)
			power *=  atof(argv[1]);

		printf("%0.4lf\n", power);
	}
	else
		printf("Invalid arguments\n");

	return 0;
}