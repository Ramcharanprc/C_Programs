// Print Bigger number among two numbers using one extra variable.
#include<stdio.h>
void main()
{
	char data[] = "Bigger", data1[] = "number";
	printf("%s %s among two %ss.\n", data, data1, data1);
	printf("Enter 1st %s: ", data1);
	int FirstNumber, SecondNumber, TemporaryStorage;
	scanf("%d", &FirstNumber);
	printf("Enter 2nd %s: ", data1);
	scanf("%d", &SecondNumber);
	if(SecondNumber > FirstNumber)
	{
		TemporaryStorage = SecondNumber;
		SecondNumber = FirstNumber;
		FirstNumber = TemporaryStorage;
	}
	printf("%d is %s than %d\n", FirstNumber, data, SecondNumber);
}
