// Print student names with their average marks.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define STRING_LENGTH 30
void main()
{
	char **namesRegister, dummy;
	int studentsCount, subjectsCount, counter = 0;
	float *marksRegister, average, totalMarks = 0;
	printf("Print average of students.\n");
	printf("Enter students count: ");
	scanf("%d", &studentsCount);
	printf("Enter subjects count: ");
	scanf("%d", &subjectsCount);
	scanf("%c", &dummy);
	namesRegister = malloc(sizeof(char*) * studentsCount);
	for(int studentNamesCounter = 0; studentNamesCounter < studentsCount; studentNamesCounter++)
	{
		namesRegister[studentNamesCounter] = malloc(STRING_LENGTH);
		printf("Enter student name %d: ", studentNamesCounter + 1);
		fgets(namesRegister[studentNamesCounter], STRING_LENGTH, stdin);
		namesRegister[studentNamesCounter][strlen(namesRegister[studentNamesCounter]) - 1] = '\0';
	}
	printf("\n");
	marksRegister = malloc(studentsCount * subjectsCount * sizeof(float));
	for(int studentsCounter = 0; studentsCounter < studentsCount; studentsCounter++)
	{
		for(int marksCounter = 0; marksCounter < subjectsCount; marksCounter++)
		{
			printf("Enter subject %d marks of %s: ", marksCounter + 1, namesRegister[studentsCounter]);
			scanf("%f", marksRegister + counter);
			if(*(marksRegister + counter) > 100 || *(marksRegister + counter) < 0)
			{
				printf("Marks should be in between 0 to 100. Please re-enter.\n");
				counter--;
				marksCounter--;
			}
			counter++;
		}
		printf("\n");
	}
	counter = 0;
	for(int studentsCounter = 0; studentsCounter < studentsCount; studentsCounter++)
	{
		for(int marksCounter = 0; marksCounter < subjectsCount; marksCounter++)
		{
			totalMarks = totalMarks + *(marksRegister + counter);
			counter++;
		}
		average = totalMarks / subjectsCount;
		printf("%s marks are %.1f out of %d and average is %.2f.", namesRegister[studentsCounter], totalMarks, subjectsCount * 100, average);
		totalMarks = 0;
		printf("\n");
	}
}