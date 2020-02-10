//Retrieving vaiables using pointers
#include<stdio.h>
void main()
{
	char message[] = "Marks", message1[] = "are";
	int marks = 98, *pMarks = &marks;
	char name = 'R', *pName = &name;
	float price = 100, *pPrice = &price;
	printf("%s %s %u\n", message, message1, marks);
	printf("%s %s %u\n", message, message1, pMarks);
	printf("%s %s %u\n", message, message1, &marks);
	printf("%s %s %u\n", message, message1, *pMarks);
	printf("%s %s %u\n", message, message1, *(&marks))	;
}