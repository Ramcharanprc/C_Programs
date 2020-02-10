//Print marks of students using struct and pointers.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define STRING_LENGTH 20
#define SUBJECTS_COUNT 5
#define MAXIMUM_MARKS 100
#define MINIMUM_MARKS 0
struct studentDetails
{
	char studentName[STRING_LENGTH], section;
	int marks[SUBJECTS_COUNT];
};
void removeNextLine()
{
	char dummy;
	scanf("%c", &dummy);
	dummy = '\0';
}
void main()
{
	float totalMarks = 0, average, studentsCount;
	char dummy;
	struct studentDetails *pStudents;
	printf("Enter students count: ");
	scanf("%f", &studentsCount);
	removeNextLine();
	pStudents = malloc(sizeof(struct studentDetails) * studentsCount);
	for(int studentsCounter = 0; studentsCounter < studentsCount; studentsCounter++)
	{
		printf("Student %d name: ", studentsCounter + 1);
		fgets((pStudents[studentsCounter].studentName), STRING_LENGTH, stdin);
		(pStudents[studentsCounter].studentName)[strlen(pStudents[studentsCounter].studentName) - 1] = '\0';
		// removeNextLine();	

		printf("%s's section: ", (pStudents[studentsCounter].studentName));
		scanf("%c", &pStudents[studentsCounter].section);
		// fgets((pStudents[studentsCounter].section), STRING_LENGTH, stdin);
		// (pStudents[studentsCounter].section)[strlen(pStudents[studentsCounter].section) - 1] = '\0';

		for(int marksCounter = 0; marksCounter < SUBJECTS_COUNT; marksCounter++)
		{
			printf("Subject %d marks: ", marksCounter + 1);
			scanf("%d", &pStudents[studentsCounter].marks[marksCounter]);
			if(pStudents[studentsCounter].marks[marksCounter] > MAXIMUM_MARKS || pStudents[studentsCounter].marks[marksCounter] < MINIMUM_MARKS)
			{
				printf("Marks should be in between %d and %d.Please re-enter.\n", MAXIMUM_MARKS, MINIMUM_MARKS);
				marksCounter--;
			}
		}
		printf("\n");
		removeNextLine();
	}
	for(int studentsCounter = 0; studentsCounter < studentsCount; studentsCounter++)
	{
		printf("Student name is %s.\n", (pStudents[studentsCounter].studentName));
		printf("Section is %c.\n", (pStudents[studentsCounter].section));
		for(int marksCounter = 0; marksCounter < SUBJECTS_COUNT; marksCounter++)
		{
			printf("Marks are %d.\n", pStudents[studentsCounter].marks[marksCounter]);
			totalMarks = totalMarks + pStudents[studentsCounter].marks[marksCounter];
		}
		average = totalMarks / SUBJECTS_COUNT;
		printf("Total marks are %.2f and average is %.2f.\n", totalMarks, average);
		totalMarks = 0;
		printf("\n");
	}
}