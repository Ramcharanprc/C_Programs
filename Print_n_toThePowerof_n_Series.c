 // Print n to the power of n series.
#include<stdio.h>
void main()
{
	printf("Print n to the power of n series.\n");
	printf("How many terms do you want to print: ");
	int NumberofTerms;
	scanf("%d", &NumberofTerms);
	printf("n to Power n Series.\n====================\n");
	for(int BaseValue = 1; BaseValue <= NumberofTerms; BaseValue++)
	{
		int Product = 1;
		for(int PowerValue = 1; PowerValue <= BaseValue ;PowerValue++)
		{
			Product = Product * BaseValue;
		}
		printf("%d", Product);
		if(BaseValue < NumberofTerms)
		{
			printf(", ");
		}
		else printf(".\n");
	}
}
