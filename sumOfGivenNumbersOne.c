// print sum of given numbers.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main(int argc, char* argv[])
{
	long int values[], sum = 0;
	if(argc != 1)
	{
		for(int counter = 1; counter < argc; counter++)
		{
			if(atoi(argv[counter]) != 0 && strcmp(argv[counter], "0"))
			{
				values[counter] = atoi(argv[counter]);
				sum = sum + values[counter];
			}
			else
			{
				printf("%s is not a number.\nPlease enter numbers and try again.\n", argv[counter]);
				exit(1);
			}
		}
		printf("Sum of");
		for(int counter = 1; counter < values.length; counter++)
		{
			printf(" %ld", values[counter]);
			if(counter < values.length - 2)
			{
				printf(",");
			}
			else if(counter < values.length - 1)
			{
				printf(" and");
			}
		}
		printf(" is %ld.\n", sum);
	}
}