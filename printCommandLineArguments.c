//Print command line aguments.
#include<stdio.h>
void main(int argc, char *argv[])
{
	printf("Number of arguments you entered are %d.\n", argc - 1);
	for(int counter = 1; counter < argc; counter++)
	{
		printf("Argument %d is %s.\n", counter, argv[counter]);
	}
}