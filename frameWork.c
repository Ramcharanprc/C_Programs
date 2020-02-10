//Generic CRUD functions for various domains.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define STRING_LENGTH 100
#define STRING_LENGTH_TWO 2
#define INITIAL_VALUE 0
#define MENU "bankMenu.cfg"
#define FIELDS "bankFields.cfg"
#define GENERAL "bankGeneral.cfg"
#define DATA_FILE "bank.dat"
#define ACTIVE "A"
#define INACTIVE "I"

void create();
void view();
void update();
void delete();
void search();
void showMenu();
void exitFromProgram();
void clearNewLineFromBuffer();
int compareStatusAndId(FILE *fpFile);
char* getGeneralConfigurationValue(char* configurationKey);	
int getRecordCount(FILE *fpFile);
void printDetailsNotFound(int flag);
void printNewLine();
void readConfigurationFile(int *ptrCount, char *file, char ***ptrArray);
void readId();
void removeNewLine(char*);
void scanText(char *details);

FILE *fpDataFile;
int counter = INITIAL_VALUE, menuCount, fieldCount, generalLineCount;
int fieldCounter = INITIAL_VALUE, flag = INITIAL_VALUE;
char confirmation, delimiter[] = ":";
char userInput[STRING_LENGTH], status[STRING_LENGTH_TWO], Id[STRING_LENGTH];
char **menu, **field, **general;

void main()
{
	showMenu();
}

void showMenu()
{
	readConfigurationFile(&menuCount, MENU, &menu);
	readConfigurationFile(&fieldCount, FIELDS, &field);
	readConfigurationFile(&generalLineCount, GENERAL, &general);
	void (*ptrFunction[])() = {create, view, update, delete, search, exitFromProgram};
	confirmation = 'n';
	int userChoice = INITIAL_VALUE;
	for(counter = INITIAL_VALUE; counter < menuCount; counter++)
	{
		printf("%s\n", menu[counter]);
	}
	do
	{
		printf("%s: ", getGeneralConfigurationValue("Choice"));
		scanf("%d", &userChoice);
		clearNewLineFromBuffer();
		printNewLine();
		if(userChoice != 1 && userChoice != 2 && userChoice != 3 && userChoice != 4 && userChoice != 5 && userChoice != 6)
		{
			printf("Invalid choice!\nEnter a valid number.\n\n");
		}
		else
		{
			confirmation = 'y';
		}
	}while(confirmation == 'n');
	// for(counter = 0; counter < fieldCount; counter++)
	// {
	// 	printf("%s.", field[counter]);
	// }
	(ptrFunction[userChoice - 1])();
	// switch(userChoice)
	// {
	// 	case 1:
	// 	create();
	// 	break;

	// 	case 2:
	// 	view();
	// 	break;

	// 	case 3:
	// 	update();
	// 	break;

	// 	case 4:
	// 	delete();
	// 	break;

	// 	case 5:
	// 	search();
	// 	break;

	// 	case 6:
	// 	printf("Thank You!\n");
		// exit(1);
	// }
	showMenu();
}

void clearNewLineFromBuffer()
{
	char dummy;
	scanf("%c", &dummy);
}

int compareStatusAndId(FILE *fpFile)
{
	int recordCount = INITIAL_VALUE;
	recordCount = getRecordCount(fpFile);
	readId();
	for(counter = INITIAL_VALUE; counter < recordCount; counter++)
	{
		fseek(fpFile, (STRING_LENGTH * fieldCount), SEEK_CUR);
		fread(status, 1, 1, fpFile);
		if(strcmp(status, ACTIVE) == INITIAL_VALUE)
		{
			fseek(fpFile, -((STRING_LENGTH * fieldCount) + 1), SEEK_CUR);
			fread(userInput, STRING_LENGTH, 1, fpFile);
			if(strcmp(userInput, Id) == INITIAL_VALUE)
			{
				confirmation = 'y';
				return 0;
			}
			else
			{
				confirmation = 'n';
				fseek(fpFile, ((STRING_LENGTH * (fieldCount - 1)) + 1), SEEK_CUR);
			}
		}
	}
}

char* getGeneralConfigurationValue(char *configurationKey)
{
	int splitCounter = INITIAL_VALUE;
	char *token, array[STRING_LENGTH_TWO][STRING_LENGTH], *generalMessage;
	generalMessage = malloc(STRING_LENGTH);
	for(counter = INITIAL_VALUE; counter < generalLineCount; counter++)
	{
		strcpy(generalMessage, general[counter]);
		token = strtok(generalMessage, delimiter);
		while(token != NULL)
		{
			strcpy(array[splitCounter], token);
			splitCounter++;
			token = strtok(NULL, delimiter);
		}
		splitCounter = INITIAL_VALUE;
		if(strcmp(array[splitCounter], configurationKey) == INITIAL_VALUE)
		{
			strcpy(generalMessage, array[splitCounter + 1]);
			return generalMessage;
		}
		splitCounter = INITIAL_VALUE;
	}
	return NULL;
}

int getRecordCount(FILE *fpFile)
{
	int recordCount = INITIAL_VALUE;
	char record[(STRING_LENGTH * fieldCount) + 1];
	while(fread(record, (STRING_LENGTH * fieldCount) + 1, 1, fpFile))
	{
		recordCount++;
	}
	rewind(fpFile);
	return recordCount;
}

void printDetailsNotFound(int flag)
{
	if(flag != 1)
	{
		printf("%s\n", getGeneralConfigurationValue("IdNotFound"));
		printNewLine();
	}
	flag = INITIAL_VALUE;
}

void printNewLine()
{
	printf("\n");
}

void readConfigurationFile(int *ptrCount, char *file, char ***ptrArray)
{
	FILE *fpFile = fopen(file, "r");
	int lineCounter = INITIAL_VALUE;
	while(fgets(userInput, STRING_LENGTH, fpFile))
	{
		lineCounter++;
	}
	*ptrCount = lineCounter;
	rewind(fpFile);
	*ptrArray = malloc(sizeof(char*) * (*ptrCount));
	for(lineCounter = INITIAL_VALUE; lineCounter < *ptrCount; lineCounter++)
	{
		(*ptrArray)[lineCounter] = malloc(STRING_LENGTH);
		fgets(userInput, STRING_LENGTH, fpFile);
		removeNewLine(userInput);
		strcpy((*ptrArray)[lineCounter], userInput);
	}
	fclose(fpFile);
}

void readId()
{
	printf("%s: ", getGeneralConfigurationValue("Id"));
	scanText(Id);
}

void removeNewLine(char *string)
{
	string[strlen(string) - 1] = '\0';
}

void scanText(char *details)
{
	fgets(details, STRING_LENGTH, stdin);
	details[strlen(details) - 1] = '\0';
}

void create()
{
	fpDataFile = fopen(DATA_FILE, "a");
	printf("%s\n", getGeneralConfigurationValue("Create"));
	for(fieldCounter = INITIAL_VALUE; fieldCounter <= fieldCount; fieldCounter++)
	{
		if(fieldCounter != fieldCount)
		{
			memset(userInput, '\0', STRING_LENGTH);
			printf("Enter %s: ", field[fieldCounter]);
			scanText(userInput);
			fwrite(userInput, STRING_LENGTH, 1, fpDataFile);
		}
		else
		{
			fwrite(ACTIVE, 1, 1, fpDataFile);
		}
	}
	printf("%s\n", getGeneralConfigurationValue("Details"));
	printNewLine();
	fclose(fpDataFile);
}

void view()
{
	int recordCount;
	fpDataFile = fopen(DATA_FILE, "r");
	printf("%s\n", getGeneralConfigurationValue("View"));
	recordCount = getRecordCount(fpDataFile);
	if(recordCount == INITIAL_VALUE)
	{
		printf("%s\n", getGeneralConfigurationValue("notCreated"));
	}
	printNewLine();
	for(counter = INITIAL_VALUE; counter < recordCount; counter++)
	{
		fseek(fpDataFile, (STRING_LENGTH * fieldCount), SEEK_CUR);
		fread(status, 1, 1, fpDataFile);
		if(strcmp(status, ACTIVE) == INITIAL_VALUE)
		{
			fseek(fpDataFile, -((STRING_LENGTH * fieldCount) + 1), SEEK_CUR);
			for(fieldCounter = INITIAL_VALUE; fieldCounter < fieldCount; fieldCounter++)
			{
				fread(userInput, STRING_LENGTH, 1, fpDataFile);
				printf("%s: %s.\n", field[fieldCounter], userInput);
			}
			printNewLine();
			fseek(fpDataFile, 1, SEEK_CUR);
		}
	}
	fclose(fpDataFile);
}

void update()
{
	fpDataFile = fopen(DATA_FILE, "r +");
	int updateChoice;
	printf("%s\n", getGeneralConfigurationValue("Update"));
	compareStatusAndId(fpDataFile);
	if(confirmation == 'y')
	{
		for(int recordCounter = 1; recordCounter < fieldCount; recordCounter++)
		{
			fread(userInput, STRING_LENGTH, 1, fpDataFile);
			printf("%s: %s.\n", field[recordCounter], userInput);
		}
		printNewLine();
		fseek(fpDataFile, -(STRING_LENGTH * (fieldCount - 1)), SEEK_CUR);
		for(fieldCounter = 1; fieldCounter < fieldCount; fieldCounter++)
		{
			printf("%d) %s.\n", fieldCounter, field[fieldCounter]);
		}
		printf("%s: ", getGeneralConfigurationValue("Choice"));
		scanf("%d", &updateChoice);
		clearNewLineFromBuffer();
		for(fieldCounter = 1; fieldCounter < fieldCount; fieldCounter++)
		{
			if((fieldCounter) == updateChoice)
			{
				printf("Enter %s: ", field[fieldCounter]);
				scanText(userInput);
				fwrite(userInput, STRING_LENGTH, 1, fpDataFile);
				printf("%s\n", getGeneralConfigurationValue("Updated"));
				printNewLine();
				break;
			}
			else
			{
				fseek(fpDataFile, STRING_LENGTH, SEEK_CUR);
			}
			flag = 1;
		}
	}
	printDetailsNotFound(flag);
	fclose(fpDataFile);
}

void delete()
{
	fpDataFile = fopen(DATA_FILE, "r +");
	confirmation = 'n';
	printf("%s\n", getGeneralConfigurationValue("Delete"));
	printNewLine();
	compareStatusAndId(fpDataFile);
	if(confirmation == 'y')
	{
		for(fieldCounter = 1; fieldCounter < fieldCount; fieldCounter++)
		{
			fread(userInput, STRING_LENGTH, 1, fpDataFile);
			printf("%s: %s.\n", field[fieldCounter], userInput);
		}
		printNewLine();
		printf("%s? (y or n) ", getGeneralConfigurationValue("Confirmation"));
		scanf("%c", &confirmation);
		clearNewLineFromBuffer();
		if(confirmation == 'y' || confirmation == 'Y')
		{
			fwrite(INACTIVE, 1, 1, fpDataFile);
			printf("%s\n", getGeneralConfigurationValue("Deleted"));
			printNewLine();
		}
		else
		{
			printNewLine();
		}
		flag = 1;
	}

	printDetailsNotFound(flag);
	fclose(fpDataFile);
}

void search()
{
	fpDataFile = fopen(DATA_FILE, "r");
	printf("%s\n", getGeneralConfigurationValue("Search"));
	printNewLine();
	compareStatusAndId(fpDataFile);
	if(confirmation == 'y')
	{
		for(fieldCounter = 1; fieldCounter < fieldCount; fieldCounter++)
		{
			fread(userInput, STRING_LENGTH, 1, fpDataFile);
			printf("%s: %s.\n", field[fieldCounter], userInput);
		}
		printNewLine();
		flag = 1;	
	}
	printDetailsNotFound(flag);
	fclose(fpDataFile);
}

void exitFromProgram()
{
	printf("Thank You!\n");
	exit(1);
}