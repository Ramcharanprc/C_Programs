//Read names and store them in a file.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define STRING_LENGTH 20
void main()
{
	char names[STRING_LENGTH], userResponse = 'y', dummy;
	FILE *pNames;
	printf("Read names and store them into a file.\n");
	pNames = fopen("names.lst", "a");
	if(pNames == NULL)
	{
		printf("ERROR!\nFile not found.\n");
		exit(1);
	}
	while(userResponse == 'y')
	{
		printf("Enter the name : ");
		fgets(names, STRING_LENGTH, stdin);
		fputs(names, pNames);
		printf("Do you want to continue? (y or n) ");
		scanf("%c", &userResponse);
		scanf("%c", &dummy);
	}
	fclose(pNames);
	printf("Names recorded successfully.\nThank you.\n");
}