#include <stdio.h>
void main(void)
{
	int rows, curr_row, space, asc_let, dsc_let;
	char ch;
	printf("Enter a uppercase letter!\n");
	scanf("%c",&ch);
	//Caluclating number of rows by subtracting from ASCII value of 'A'
	rows = ch - 64;

	//Number of rows
	for(curr_row = 1; curr_row <= rows ; curr_row++)
	{
	
		for(space = rows-1; space >= curr_row; space--)
			printf(" ");	

		for(asc_let = 1; asc_let <= curr_row; asc_let++)
			printf("%c",asc_let + 64);

		for (dsc_let = curr_row-1; dsc_let >= 1; dsc_let--)
			printf("%c",dsc_let + 64);
	
		printf("\n");
	}

}