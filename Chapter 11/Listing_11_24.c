#include <stdio.h>
#include <string.h>
#define LISTSIZE 6
void main()
{
	const char * list[LISTSIZE] = {"astronomy","astounding","astrophysics","ostracize",
								   "asterism","astrophobia"
								  };

	int count = 0;
	int i;

	for(i = 0; i < LISTSIZE; i++)
	{
		if(strncmp(list[i], "astro", 5) == 0)
		{
			printf("Found: %s\n", list[i]);
			count++;
		}
	}

	printf("The list contains %d words beginning with astro.\n", count);
}