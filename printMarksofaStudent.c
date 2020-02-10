//Print 5 subject marks of a student
#include<stdio.h>
#include<string.h>
void main()
{
	char data1[] = "marks", data2[] = "subject", data3[] = "student";
	int countOfSubjects = 5;
	int studentMarks[countOfSubjects];
	printf("Print %d %s %s of a %s.\n", countOfSubjects, data2, data1, data3);
	for(int marksCounter = 0; marksCounter < countOfSubjects; marksCounter++)
	{
		printf("Enter %s of %s %d: ", data1, data2, marksCounter + 1);
		scanf("%d", &studentMarks[marksCounter]);
		int maximumMarks = 100;
		if(studentMarks[marksCounter] > maximumMarks)
		{
			marksCounter--;
			data1[0] = 'M';
			printf("%s should be less than %d.\n", data1, maximumMarks);
			data1[0] = 'm';
		}
	}
	printf("\n");
	for(int marksPrinter = 0; marksPrinter < countOfSubjects; marksPrinter++)
	{
		printf("%s %d %s are %d.\n", data2, marksPrinter + 1, data1, studentMarks[marksPrinter]);
	}
}