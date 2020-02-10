//Print Multiplication tables book.
#include<stdio.h>
#include<string.h>
#include"printUnderlineOne.c"
void main()
{
	char data1[] = "Multiplication", data2[] = "table", data3[] = "Print";
	printf("%s %s %ss book.\n", data3, data1, data2);
	printf("How many %ss do you want to print: ", data2);
	int TableCount;
	scanf("%d", &TableCount);
	printf("\n");
	for(int TableCounter=1; TableCounter <= TableCount; TableCounter++)
	{
		printUnderline(printf("Multiplication table of %d is:\n", TableCounter));
		for(int RowCounter = 1	; RowCounter <= 10; RowCounter++)
		{
			printf("%2d X %2d = %3d\n", TableCounter, RowCounter, TableCounter * RowCounter);
		}
		printf("\n");
	}
	printf("Thank you.\n");
}

