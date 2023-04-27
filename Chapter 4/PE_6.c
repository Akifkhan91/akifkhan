#include <stdio.h>
#include <string.h>
void main(void)
{
	char First_Name[20];
	char Last_Name[20];
	printf("Enter your first name\n");
	scanf("%s",First_Name);
	printf("Now enter your last name\n");
	scanf("%s",Last_Name);
	int No_Letters_First_Name=strlen(First_Name);
	int No_Letters_Last_Name=strlen(Last_Name);
	printf("%*s %*s\n",No_Letters_First_Name,First_Name,No_Letters_Last_Name,Last_Name);
	printf("%*zd %*zd \n",No_Letters_First_Name,strlen(First_Name),No_Letters_Last_Name,strlen(Last_Name));
	printf("%*s %*s\n",No_Letters_First_Name,First_Name,No_Letters_Last_Name,Last_Name);
	printf("%-*zd %-*zd \n",No_Letters_First_Name,strlen(First_Name),No_Letters_Last_Name,strlen(Last_Name));

}