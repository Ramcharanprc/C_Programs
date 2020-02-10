//Every char detail in a string.
#include<stdio.h>
void printString(int stingLength, char *anyInput)
{
	for(int index = 0; index < stingLength; index++)
	{
		printf("char %3d is %c %3d.\n", index + 1, anyInput[index], anyInput[index]);
	}
}
void main()
{
	int arraySize = 15;
	char userName[arraySize];
	printString(arraySize, userName);
	printf("Enter the name: ");
	scanf("%s", userName);
	printf("Print a name: %s.\n", userName);
	printString(arraySize, userName);
}