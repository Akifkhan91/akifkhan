#include <stdio.h>
#include <string.h>
#define LEN 12

struct month {
			  char * month_name;
			  int month_days;
			 };

const struct month months[12] = {{"january", 31}, {"february", 28}, {"march", 31}, {"april", 30}, {"may", 31}, {"june", 30},
							   {"july", 31}, {"august", 31}, {"september", 30}, {"october", 31}, {"november", 30}, {"december", 31}};

int days(char month[], int month_number);

int main(void)
{

	char input_month[12];
	int flag = 0;

	puts("Enter name of the month");
	scanf("%s", input_month);
	while(getchar() != '\n')
		continue;

	for(int i = 0; i < 12; i++)
	{
		if(strcmp(input_month, months[i].month_name) == 0)
		{
			printf("The number of days till month %d are %d\n", i+1, days(input_month, i));
			flag = 1;
			break;
		}
	}

	if(flag == 0)
	puts("No month found");
	
	return 0;
}

int days(char month[], int month_number)
{
	int index, total;
	for(index = 0, total = 0; index <= month_number; index++)
		total += months[index].month_days;

	return(total);
}