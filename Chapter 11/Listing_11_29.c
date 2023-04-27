#include <stdio.h>
#include <string.h>
#define SIZE 81
#define LIM 20

char * s_gets(char * st, int n);
void stsrt(char * strings[], int num);
void main(void)
{
	char lines[LIM][SIZE];
	char * ptrstring[LIM];
	int ct = 0;
	int k;
	puts("Enter some strings(Enter newline to quit):");
	while(ct < LIM && s_gets(lines[ct], SIZE) != NULL && lines[ct][0] != '\0')
	{
		ptrstring[ct] = lines[ct];
		ct++;
	}
	stsrt(ptrstring, ct);
	puts("The sorted strings are:");

	for(k = 0; k < ct; k++)
		puts(ptrstring[k]);

}

char * s_gets(char * st, int n)
{
	char * ret_val;
	char * find;
	int i = 0;
	ret_val = fgets(st, n, stdin);

	if(ret_val)
	{
		find = strchr(st, '\n');
		
		if(find)
			*find = '\0';

		else
			while(getchar() != '\n')
				continue;
	}

	return ret_val;
}

void stsrt(char * strings[], int num)
{
	int top, seek;
	char * temp;

	for(top = 0; top < num-1; top++)
	{
		for(seek = top; seek < num; seek++)
		{
			if(strcmp(strings[top],strings[seek]) > 0)
			{
				temp = strings[top];
				strings[top] = strings[seek];
				strings[seek] = temp;
			}
		}
	}
}