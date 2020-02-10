// Print size of pointers.
#include<stdio.h>
void printSize(char message[], int pointerSize)
{
	printf("Size of %s is %d.\n", message, pointerSize);
}
void main()
{
	int *pMarks;
	char *pName;
	float *pPrices;
	printSize("*pMarks", sizeof(*pMarks));
	printSize("*pName", sizeof(*pName));
	printSize("*pPrices", sizeof(*pPrices));
	printf("\n");
	printSize("int", sizeof(int));
	printSize("char", sizeof(char));
	printSize("float", sizeof(float));
	printf("\n");
	printSize("int*", sizeof(int*));
	printSize("char*", sizeof(char*));
	printSize("float*", sizeof(float*));
	printf("\n");
	printSize("pMarks", sizeof(pMarks));
	printSize("pName", sizeof(pName));
	printSize("pPrices", sizeof(pPrices));
	printf("\n");
	printf("%u\n", pName + 1);
	printf("%u\n", pMarks + 1);
	printf("%u\n", pPrices + 1);
}