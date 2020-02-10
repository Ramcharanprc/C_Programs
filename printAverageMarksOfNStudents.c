// Print 5 subjects average marks of n students.
#include<stdio.h>
#include<stdlib.h>
#define NO_OF_SUBJECTS 5
void main()
{
	printf("Print average of 'n' number of students.\n");
	printf("Enter students count: ");
	float average, *marksOfNStudents, studentsCount, totalMarks = 0;
	int counter = 0;
	scanf("%f", &studentsCount);
	marksOfNStudents = malloc(sizeof(float) * NO_OF_SUBJECTS * studentsCount);
	for(int studentsCounter = 0; studentsCounter < studentsCount; studentsCounter++)
	{
		for(int marksCounter = 0; marksCounter < NO_OF_SUBJECTS; marksCounter++)
		{
			printf("Enter subject %d marks of student %d: ", marksCounter + 1, studentsCounter + 1);
			scanf("%f", (marksOfNStudents + counter));
			if(*(marksOfNStudents + counter) > 100 || *(marksOfNStudents + counter) < 0)
			{
				printf("Marks should be in between 0 to 100 please re-enter the marks.\n");
				marksCounter--;
				counter--;
			}
			counter++;
		}
		printf("\n");
	}
	counter = 0;
	printf("\n");
	for(int studentsIndex = 0; studentsIndex < studentsCount; studentsIndex++)
	{
		for(int marksIndex = 0; marksIndex < NO_OF_SUBJECTS; marksIndex++)
		{
			totalMarks = totalMarks + *(marksOfNStudents + counter);
			counter++;
		}
		average = (totalMarks / NO_OF_SUBJECTS);
		printf("Total marks of student %d are %0.2f.\n", studentsIndex + 1, totalMarks);
		printf("student %d average is %0.2f.\n", studentsIndex + 1, average);
		totalMarks = 0;

	}
}