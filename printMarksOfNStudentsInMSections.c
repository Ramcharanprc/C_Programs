// Read and print marks of 'n' students in 'm' sections.
#include<stdio.h>
#include<stdlib.h>
#define MAXIMUM_MARKS 100
#define MINIMUM_MARKS 0
void main()
{
	float *marksPointer, totalMarks = 0, average;
	int studentsCount, sectionsCount, subjectsCount, counter = 0;
	printf("Print Average of 'n' students in 'm' sections.\n");
	printf("Enter number of subjects: ");
	scanf("%d", &subjectsCount);
	printf("Enter number of sections: ");
	scanf("%d", &sectionsCount);
	printf("Enter number of students in each section: ");
	scanf("%d", &studentsCount);
	marksPointer = malloc(sizeof(int) * sectionsCount * studentsCount * subjectsCount);
	for(int sectionsCounter = 0; sectionsCounter < sectionsCount; sectionsCounter++)
	{
		for(int studentsCounter = 0; studentsCounter < studentsCount; studentsCounter++)
		{
			for(int marksCounter = 0; marksCounter < subjectsCount; marksCounter++)
			{
				printf("Enter section %d student %d subject %d marks: ", sectionsCounter + 1, studentsCounter + 1, marksCounter + 1);
				scanf("%f", (marksPointer + counter));
				if(*(marksPointer + counter) > MAXIMUM_MARKS || *(marksPointer + counter) < 0)
				{
					printf("Marks should be in between %d to %d. Please re-enter.\n", MAXIMUM_MARKS, MINIMUM_MARKS);
					counter--;
					marksCounter--;
				}
				counter++;
			}
			printf("\n");
		}
	}
	counter = 0;
	for(int sectionsCounter = 0; sectionsCounter < sectionsCount; sectionsCounter++)
	{
		for(int studentsCounter = 0; studentsCounter < studentsCount; studentsCounter++)
		{
			for(int marksCounter = 0; marksCounter < subjectsCount; marksCounter++)
			{
				totalMarks = totalMarks + *(marksPointer + counter);
				counter++;
			}
			average = (totalMarks / subjectsCount);
			printf("section %d Student %d totalMarks are %.2f and his average is %.2f.\n", sectionsCounter + 1, studentsCounter + 1, totalMarks, average);
			totalMarks = 0;
		}
		printf("\n");
	}
}