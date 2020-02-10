// Print larger number among two numbers without using extra variable.
#include<stdio.h>
void main()
{
	char data[] = "Larger", data1[] = "number";
	printf("Print %s %s among two %ss.\n" ,data, data1, data1);
	int FirstNumber, SecondNumber;
	printf("Enter 1st %s: ", data1);
	scanf("%d", &FirstNumber);
	printf("Enter 2nd %s: ", data1);
	scanf("%d", &SecondNumber);
	if(SecondNumber > FirstNumber)
	{
		SecondNumber = FirstNumber + SecondNumber;
		FirstNumber = SecondNumber - FirstNumber;
		SecondNumber = SecondNumber - FirstNumber;
	}
	printf("%d is %s than %d.\n", FirstNumber, data, SecondNumber);
}
