//Print Multiplication table of User choice.
#include<stdio.h>
int main()
{
	printf("Print Multiplication table.\n");
	printf("Enter a Table number you want to print: ");
	int TableNumber;
	scanf("%d", &TableNumber);
	int RowCounter;
	printf("Table - %d\n==========\n", TableNumber);
	for(RowCounter = 1; RowCounter <= 10; RowCounter++)
	{
		printf("%2d X %2d = %3d\n", TableNumber, RowCounter, TableNumber * RowCounter);
	}
}
