//Read 5 names and print them.
#include<stdio.h>
#include<string.h>
void main()
{
	char data[] = "name";
	printf("Print 5 %ss.\n", data);
	int noOfNames = 5, nameLength = 20;
	char userNames[noOfNames][nameLength];
	for(int scanNames = 0; scanNames < noOfNames; scanNames++)
	{
		printf("Enter %s %d: ", data, scanNames+1);
		scanf("%s", userNames[scanNames]);
	}
	printf("\n");
	for(int printNames = 0; printNames < noOfNames; printNames++)
		{
			data[0] = 'N';
			printf("%s %d is %s.\n", data, printNames+1, userNames[printNames]);
		}
}