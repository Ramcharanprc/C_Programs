// Read and print n names using pointer.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define STRING_LENGTH 30
void main()
{
	char **pNames;
	int numberOfNames;
	char dummy;
	printf("How many names do you want to print: ");
	scanf("%d", &numberOfNames);
	scanf("%c", &dummy);
	pNames = malloc(sizeof(char*) * numberOfNames);
	for(int namesCounter = 0; namesCounter < numberOfNames; namesCounter++)
	{
		pNames[namesCounter] = malloc(STRING_LENGTH);
		printf("Enter name %d: ", namesCounter + 1);
		fgets(pNames[namesCounter], STRING_LENGTH , stdin);
		pNames[namesCounter][strlen(pNames[namesCounter]) - 1] = '\0';
	}
	printf("\n");
	printf("Names you entered are: \n");
	for(int namesIndex = 0; namesIndex < numberOfNames; namesIndex++)
	{
		printf("%d) %s.\n", namesIndex + 1, pNames[namesIndex]);
	}
}