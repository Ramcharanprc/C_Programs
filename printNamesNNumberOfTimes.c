//Print a name 'n' number of times.
#include<stdio.h>
#include<stdlib.h>
void main(int argc, char* argv[])
{
	if(argc > 3)
	{
		printf("Please enter a name and repetition count.\n");
	}
	else
	{
		for(int counter = 0; counter < atoi(argv[2]); counter++)
		{
			printf("%s\n", argv[1]);
		}
	}
}