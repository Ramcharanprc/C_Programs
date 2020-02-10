// Read and print n marks
#include<stdio.h>
#define MARKS_LIMIT 100
void main()
{
	char marksWord[] = "marks", subject[] = "subject";
	int noOfMarks;
	printf("How many %s %s do you want to print: ", subject, marksWord);
	scanf("%d", &noOfMarks);
	int marks[noOfMarks];
	for(int scanMarks = 0; scanMarks < noOfMarks; scanMarks++)
	{
		printf("Enter %s %d %s: ", subject, scanMarks + 1, marksWord);
		scanf("%d", &marks[scanMarks]);
		if(marks[scanMarks] > MARKS_LIMIT)
		{
			printf("%s should be less than %d.\n",marksWord, MARKS_LIMIT);
			scanMarks--;
		}
	}
	printf("\n");
	subject[0] = 'S';
	for(int printMarks = 0; printMarks < noOfMarks; printMarks++)
	{
		printf("%s %d %s are %3d\n", subject, printMarks + 1, marksWord, marks[printMarks]);
	}
}