#include <stdio.h>
#include <stdlib.h>
#define ARSIZE 1000

int main(void)
{
	double numbers[ARSIZE];
	double value;
	const char * file = "numbers.dat";
	int i;
	long int pos;
	FILE * iofile;

	//create a set of double values
	for(i = 0; i < ARSIZE; i++)
		numbers[i] = 100.0 * (double) i + 1.0/(double) (i + 1);

	if((iofile = fopen(file, "wb")) == NULL)
	{
		fprintf(stderr, "Unable to open output file %s\n", file);
		exit(EXIT_FAILURE);
	} 

	fwrite(numbers, sizeof(double), ARSIZE, iofile);
	fclose(iofile);

	if((iofile = fopen(file, "rb")) == NULL)
	{
		fprintf(stderr, "Unable to open %s for random access\n", file);
		exit(EXIT_FAILURE);
	}

	printf("Enter an index in the range of 0-%d\n", ARSIZE-1);
	while(scanf("%d", &i) == 1 && i >= 0 && i < ARSIZE)
	{
		pos = (long) i * sizeof(double);
		fseek(iofile, pos, SEEK_SET);
		fread(&value, sizeof(double), 1, iofile);
		printf("The value there is %f\n", value);
		printf("Next index (out of range to quit:)\n");
	}
	fclose(iofile);
	puts("Done");

	return 0;
}