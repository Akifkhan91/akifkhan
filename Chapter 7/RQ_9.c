/*
What will the following program print given this input?
q
c
h
b
*/


#include <stdio.h>
void main(void)
{
	char ch;

	while((ch = getchar()) != '#')
	{
		if(ch == '\n')
			continue;
		printf("Step 1\n");
		if(ch == 'c')
			continue;
		else if(ch == 'b')
			break;
		else if(ch == 'h')
			goto laststep;
		printf("Step 2\n");

		laststep: printf("Step 3\n");
	}
	printf("Done!\n");
}

/*
Answer:
q
Step 1
Step 2
Step 3
c
Step 1
h
Step 1
Step 3
b
Step 1
Done!
*/