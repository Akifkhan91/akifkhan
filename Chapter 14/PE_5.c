#include <stdio.h>
#define LEN 30
#define GRADE_LEN 3
#define CSIZE 4
struct name{
			char first[LEN];
			char last[LEN];
		   };

struct student{
			   struct name student_name;
			   float grade[GRADE_LEN];
			   float avg_grade;
			  };

int main(void)
{
	struct student student_data[CSIZE] = {
		{{"Akif", "Khan"}}, {{"Anique", "Khan"}},{{"Nuzhat", "Khan"}}, {{"Rafique", "Khan"}}
										 };
	return 0;
}