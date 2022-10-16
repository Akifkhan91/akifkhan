#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int static_store = 30;
const char * pcg = "String Literal";

int main(void)
{
	int auto_store = 40;
	char auto_string[] = "Auto char Array";
	int * pi;
	char * pc1;

	pi = (int *)malloc(sizeof(int));
	*pi = 35;
	pc1 = (char *)malloc(strlen("Dynamic string")+1);
	strcpy(pc1, "Dynamic string");

	printf("static int storage: %d at %p\n", static_store, &static_store);
	printf("static string storage: %s at %p\n", pcg, pcg);

	printf("Automatic int storage: %d at %p\n", auto_store, &auto_store);
	printf("Automatic string storage: %s at %p\n", auto_string, auto_string);

	printf("Dynamic int storage: %d at %p\n", *pi, pi);
	printf("Dynamic string storage: %s at %p\n", pc1, pc1);

	printf("String literal: %s at %p\n", "Quoted string", "Quoted string");

	free(pi);
	free(pc1); 
} 