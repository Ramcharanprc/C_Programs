// Read and print n marks using pointer.
#include<stdio.h>
#include<stdlib.h>
void main()
{
	int *pMarks, noOfMarks;
	printf("How many values do want to print: ");
	scanf("%d", &noOfMarks);
	pMarks = malloc(noOfMarks * sizeof(int));
	for(int marksCounter = 0; marksCounter < noOfMarks; marksCounter++)
	{
		printf("Enter subject %d marks: ", marksCounter + 1);
		scanf("%d", (pMarks + marksCounter));
		if(*(pMarks + marksCounter) > 100)
		{
			printf("Marks should be less than 100 please re-enter the marks.\n");
			marksCounter--;
		}
		else if(*(pMarks + marksCounter) < 0)
		{
			printf("Marks should be more than 0 please re-enter the marks.\n");
			marksCounter--;
		}
	}
	printf("\n");
	for(int index = 0;index < noOfMarks; index++)
	{
		printf("Subject %d marks are %d.\n", index + 1, *(pMarks + index));
	}
}