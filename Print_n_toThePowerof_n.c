// Print n to the power of n.
#include<stdio.h>
void main()
{
	printf("Print n to the power of n.\n");
	printf("Enter the BaseValue: ");
	int BaseValue;
	scanf("%d", &BaseValue);
	int Product = 1;
	for(int Counter=1; Counter < BaseValue; Counter++)
	{
		Product = Product * BaseValue;
	}
	printf("The value %d to the power of %d is %d.\n", BaseValue, BaseValue, Product);
}
