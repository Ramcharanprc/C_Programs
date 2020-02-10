//Read and print five marks.
#include<stdio.h>
#define MARKS_LIMIT 100
#define NO_OF_MARKS 5
void main()
{
	char marksWord[] = "marks", subject[] = "subject";
	int marks[NO_OF_MARKS];
	for(int index = 0; index < NO_OF_MARKS; index++)
	{
		printf("Enter %s %d %s: ", subject, index + 1, marksWord);
		scanf("%d", &marks[index]);
		if(marks[index] > MARKS_LIMIT)
		{
			printf("%s should be less than %d.\n",marksWord, MARKS_LIMIT);
			index--;
		}
	}
	printf("\n");
	subject[0] = 'S';
	for(int printMarks = 0; printMarks < NO_OF_MARKS; printMarks++)
	{
		printf("%s %d %s are %d.\n", subject, printMarks + 1, marksWord, marks[printMarks]);
	}
}