//Addition of given numbers.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main(int argc, char* argv[])
{
	long int sum = 0;
	if(argc == 1)
	{
		printf("Invalid input.\n");
	}
	else
	{
		for(int counter = 1; counter < argc; counter++)
		{
			sum = sum + atol(argv[counter]);
			if(atoi(argv[counter]) == 0 && strcmp(argv[counter], "0"))
			{
				printf("%s is not a number.\nPlease enter numbers and try again.\n", argv[counter]);
				exit(1);
			}
		}
		printf("Sum of");
		for(int counter = 1; counter < argc; counter++)
		{
			if(atoi(argv[counter]) != 0)
			{
				printf(" %s", argv[counter]);
				if(counter < argc - 2)
				{
					printf(",");
				}
				else if(counter < argc - 1)
				{
					printf(" and");
				}
			}
		}
		printf(" is %ld.\n", sum);
	}
}