// Print size of char vaiable and char datatype.
#include<stdio.h>
#include<string.h>
#define STRING_LENGTH 30
void main()
{
	char name[STRING_LENGTH];
	printf("Size of char: %ld\n", sizeof(char));
	printf("Size of name: %ld\n", sizeof(name));
	printf("length of name: %ld\n", strlen(name));
	for(int counter = 0; counter < STRING_LENGTH; counter++)
	{
		printf("%c %5d\n", name[counter], name[counter]);
	}
}