// Print average of students in 'n' sections. Count of students in each section are different.
#include<stdio.h>
#include<stdlib.h>
#include "printUnderlineOne.c"
#define MAXIMUM_MARKS 100
#define MINIMUM_MARKS 0
void main()
{
	float **marksPointer, *sectionWiseStudentsCount, totalMarks = 0, average;
	int sectionsCount, subjectsCount;
	printf("Print average of student marks in every section.\n");
	printf("Enter number of subjects: ");
	scanf("%d", &subjectsCount);
	printf("Enter number of sections: ");
	scanf("%d", &sectionsCount);
	marksPointer = malloc(sizeof(float) * sectionsCount);
	sectionWiseStudentsCount = malloc(sizeof(float) * sectionsCount);
	for(int studentsCounter = 0; studentsCounter < sectionsCount; studentsCounter++)
	{
		printf("Enter section %d students count: ", studentsCounter + 1);
		scanf("%f", (sectionWiseStudentsCount + studentsCounter));
	}
	printf("\n");
	for(int sectionsCounter = 0; sectionsCounter < sectionsCount; sectionsCounter++)
	{
		marksPointer[sectionsCounter] = malloc(sizeof(float) * subjectsCount * *(sectionWiseStudentsCount + sectionsCounter));
		printUnderline(printf("Section %d:\n", sectionsCounter + 1));
		printf("\n");
		for(int studentsCounter = 0; studentsCounter < *(sectionWiseStudentsCount + sectionsCounter); studentsCounter++)
		{
			printUnderline(printf("Student %d:\n", studentsCounter + 1));
			for(int marksCounter = 0; marksCounter < subjectsCount; marksCounter++)
			{
				printf("Enter subjects %d marks: ", marksCounter + 1);
				scanf("%f", (marksPointer[sectionsCounter] + studentsCounter));
			}
		}
		printf("\n");
	}
	for(int sectionsCounter = 0; sectionsCounter < sectionsCount; sectionsCounter++)
	{
		printUnderline(printf("Section %d:\n", sectionsCounter + 1));
		printf("\n");
		for(int studentsCounter = 0; studentsCounter < *(sectionWiseStudentsCount + sectionsCounter); studentsCounter++)
		{
			for(int marksCounter = 0; marksCounter < subjectsCount; marksCounter++)
			{
				totalMarks = totalMarks + *(marksPointer[sectionsCounter] + studentsCounter);
			}
			average = totalMarks / subjectsCount;
			printf("Students %d marks are %.2f and average is %.2f\n", studentsCounter + 1, totalMarks, average);
			totalMarks = 0;
		}
		printf("\n");
	}
}