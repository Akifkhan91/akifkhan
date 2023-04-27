#include <stdio.h>
#define FIRST_NAME_LEN 20
#define MIDDLE_NAME_LEN 20
#define LAST_NAME_LEN 20
#define NO_EMPLOYEE 5

char * s_gets(char st[], int n);

struct name{
			char first[FIRST_NAME_LEN];
			char middle[MIDDLE_NAME_LEN];
			char last[LAST_NAME_LEN];
};

struct employee{
				long int soc_sec;
				struct name employee_name;
};

void print_data(struct employee data[], int N);
void print_data_using_ptr(struct employee * ptr_data, int N);

int main(void)
{
	struct employee data[NO_EMPLOYEE] = { {1234, {"Akif", "Rafique", "Khan"}}, 
								{5678, {"Anique", "", "Blah"}}, 
							    {91011, {"Ayaz", "Ibrahim", "Sheikh"}},
							    {121314, {"Zippy", "Stardust", "Zazzy"}},
								{151617, {"Shauna", "Greg", "Benson"}}
							  };


	print_data(data, NO_EMPLOYEE);
	struct employee * ptr_data;
	ptr_data = &data[0];
	puts("Printing data using pointers");
	print_data_using_ptr(ptr_data, NO_EMPLOYEE);
	return 0;
}

void print_data(struct employee data[], int N)
{
	for(int i = 0; i < N; i++)
	{
		if(data[i].employee_name.middle[0] != '\0')
			printf("%s, %s %c%c %ld\n", data[i].employee_name.last, data[i].employee_name.first, data[i].employee_name.middle[0], '.', data[i].soc_sec);
		else
			printf("%s, %s %ld\n", data[i].employee_name.last, data[i].employee_name.first, data[i].soc_sec);
	}
}

void print_data_using_ptr(struct employee * ptr_data, int N)
{
	for(int i = 0; i < N; i++)
	{
		if(ptr_data->employee_name.middle[0] != '\0')
		{
			printf("%s, %s %c%c %ld\n", ptr_data->employee_name.last, ptr_data->employee_name.first, 
				ptr_data->employee_name.middle[0], '.', ptr_data->soc_sec);
			ptr_data++;
		}
		else
		{
			printf("%s, %s %ld\n", ptr_data->employee_name.last, ptr_data->employee_name.first, ptr_data->soc_sec);
			ptr_data++;
		}
	}
}