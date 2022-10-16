#include <stdio.h>
#include <stdlib.h>
int main(int argc, char * argv[])
{
	FILE * num_list;
	double num, sum = 0.0, avg;
	size_t bytes;
	int n_num = 0;

	if(argc > 2)
	{
		printf("Invalid number of arguments\n");
		exit(EXIT_FAILURE);
	}	
	else if(argc == 1)
	{
		puts("Enter some floating point numbers(Enter non-numeric character to quit)");
		while(scanf("%lf", &num) == 1)
		{
			sum += num;
			n_num++;
		}
		avg = sum/(double)n_num;
		printf("The average of the numbers is %lf\n", avg);
	}

	else if(argc == 2)
	{
		if((num_list = fopen(argv[1], "rb")) == NULL)
		{
			printf("Unable to open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
		
		while(fscanf(num_list, "%lf", &num) == 1)
		{
			sum += num;
			n_num++;
		}

		avg = sum/(double)n_num;
		printf("The average of the numbers is %lf\n", avg);
		
	}

	fclose(num_list);
	return 0;
}
