#include <stdio.h>
#include <string.h>
void main(void)
{
	char First_Name[40];
	int Letters;
	printf("Enter your first name\n");
	scanf("%s",First_Name);
	Letters=strlen(First_Name);
	printf("\"%s\"\n",First_Name);
	printf("\"%20s\"\n",First_Name);
	printf("\"%-20s\"\n",First_Name);
	printf("\"%*s\"\n",3+Letters,First_Name);
}