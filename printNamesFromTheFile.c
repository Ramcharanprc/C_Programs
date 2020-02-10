//Print names in the file.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define STRING_LENGTH 20
void main()
{
	char fileName[STRING_LENGTH], dummy, printName;
	FILE *pNames;
	printf("Print names in the file.\n");
	printf("Enter file name: ");
	scanf("%s", fileName);
	scanf("%c", &dummy);
	pNames = fopen(fileName, "r");
	if(pNames == NULL)
	{
		printf("ERROR!\nFile not found.\n");
		exit(1);
	}
	while(printName != EOF)
	{
		printName = fgetc(pNames);
		printf("%c", printName);
	}
	fclose(pNames);
}
