
//Check whether a number is prime number or not.
#include<stdio.h>
#include<math.h>
void main()
{
	char data[] = "prime number";
	printf("Print whether a number is %s or not.\n", data);
	printf("Enter a number: ");
	int userNumber;
	scanf("%d", &userNumber);
	int counter = 0;
	double squareRoot = sqrt(userNumber);
	if(userNumber >= 2)
	{
		for(int checkingNumber = 1; checkingNumber <= squareRoot; checkingNumber++)
		{
			for(int userNumberCopy = userNumber; userNumberCopy >= checkingNumber; userNumberCopy = userNumberCopy - checkingNumber)
			{
				if(userNumberCopy - checkingNumber == 0)
					counter++;
			}
		}
	}
	if(counter == 1)
	{
		printf("%d is a %s.\n", userNumber, data);
	}
	else printf("%d is not a %s.\n", userNumber, data);
}
