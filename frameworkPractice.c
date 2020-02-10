//CRUD for various domains.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define STRING_LENGTH 100
#define STRING_LENGTH_TWO 2
#define INITIAL_VALUE 0
#define ACTIVE 'A'
#define INACTIVE 'I'
#define NEW_LINE "\n"
#define COLON_AND_SPACE ": "
#define MENU "bankMenu.cfg"
#define FIELD "bankFields.cfg"
#define GENERAL "bankGeneral.cfg"
#define DATA_FILE "bank.dat"

void create();
void view();
void update();
void delete();
void search();
void exitFromProgram();
void showMenu();
void clearNewLineFromBuffer();
void compareId(FILE*);
void compareStatus(FILE*);
void countRecords(FILE*);
char* getGeneralConfigurationValue(char* ptrConfigurationKey);
void readConfigurationFile(char* ptrConfigurationFile, int* ptrCount, char ***ptrConfigurationArray);
void readId();
void printNewLine();
void printDetailsNotFound(int);
void printConfigurationValue(char*, char*);
void scanText(char*);

int menuCount, fieldCount, generalLineCount, counter = INITIAL_VALUE;
int recordCount, fieldCounter, flag = INITIAL_VALUE, recordCounter;
char **menu, **field, **general, Id[STRING_LENGTH], text[STRING_LENGTH];
char userInput[STRING_LENGTH], confirmation, status, IdConfirmation, fieldValue[STRING_LENGTH];
FILE *fpDataFile;

void main()
{
	showMenu();
}

void showMenu()
{
	int userChoice = INITIAL_VALUE;
	confirmation = 'n';
	readConfigurationFile(MENU, &menuCount, &menu);
	readConfigurationFile(FIELD, &fieldCount, &field);
	readConfigurationFile(GENERAL, &generalLineCount, &general);
	void (*ptrFunction[])() = {create, view, update, delete, search, exitFromProgram};
	for(counter = INITIAL_VALUE; counter < menuCount; counter++)
	{
		printf("%s\n", menu[counter]);
	}
	printConfigurationValue(getGeneralConfigurationValue("Choice"), COLON_AND_SPACE);
	scanf("%d", &userChoice);
	clearNewLineFromBuffer();
	printNewLine();
	do
	{
		if(userChoice != 1 && userChoice != 2 && userChoice != 3 && userChoice != 4 && userChoice != 5 && userChoice != 6)
		{
			printConfigurationValue(getGeneralConfigurationValue("Invalid"), NEW_LINE);
			printConfigurationValue(getGeneralConfigurationValue("enterValid"), NEW_LINE);
			break;
		}
		else
		{
			confirmation = 'y';
		}
	}while(confirmation == 'n');
	if(userChoice == 1 || userChoice == 2 || userChoice == 3 || userChoice == 4 || userChoice == 5 || userChoice == 6)
	{
		(*ptrFunction[userChoice - 1])();
	}
	showMenu();
}

void clearNewLineFromBuffer()
{
	char dummy;
	scanf("%c", &dummy);
	dummy = '\0';
}

void compareId(FILE *fpFile)
{
	IdConfirmation = 'n';
	fread(text, STRING_LENGTH, 1, fpFile);
	if(strcmp(text, Id) == 0)
	{
		IdConfirmation = 'y';
	}
}

void compareStatus(FILE *fpFile)
{
	confirmation = 'n';
	int statusActive;
	fseek(fpFile, (STRING_LENGTH * fieldCount), SEEK_CUR);
	fread(&status, 1, 1, fpFile);
	if(status == ACTIVE)
	{
		confirmation = 'y';
		fseek(fpFile, -((STRING_LENGTH * fieldCount) + 1), SEEK_CUR);
	}
}

void countRecords(FILE *fpFile)
{
	recordCounter = INITIAL_VALUE;
	char record[(STRING_LENGTH * fieldCount) + 1];
	while(fread(record, ((STRING_LENGTH * fieldCount) + 1), 1, fpFile))
	{
		recordCounter++;
	}
	recordCount = recordCounter;
	rewind(fpFile);
}

char* getGeneralConfigurationValue(char* ptrConfigurationKey)
{
	char delimiter[STRING_LENGTH_TWO] = ":";
	char *message = malloc(STRING_LENGTH);
	int splitCounter = INITIAL_VALUE;
	char *token, keyAndValue[STRING_LENGTH_TWO][STRING_LENGTH];
	for(counter = INITIAL_VALUE; counter < generalLineCount; counter++)
	{
		strcpy(text, general[counter]);
		token = strtok(text, delimiter);
		while(token != NULL)
		{
			strcpy(keyAndValue[splitCounter], token);
			splitCounter++;
			token = strtok(NULL, delimiter);
		}
		splitCounter = INITIAL_VALUE;
		if(strcmp(keyAndValue[INITIAL_VALUE], ptrConfigurationKey) == 0)
		{
			strcpy(message, keyAndValue[1]);
			break;
		}
	}
	return message;
}

void readConfigurationFile(char* ptrConfigurationFile, int* ptrCount, char ***ptrConfigurationArray)
{
	FILE *fpFile = fopen(ptrConfigurationFile, "r");
	counter = INITIAL_VALUE;
	while(fgets(text, STRING_LENGTH, fpFile))
	{
		counter++;
	}
	*ptrCount = counter;
	rewind(fpFile);
	*ptrConfigurationArray = malloc(sizeof(char*) * *ptrCount);
	for(counter = 0; counter < *ptrCount; counter++)
	{
		(*ptrConfigurationArray)[counter] = malloc(STRING_LENGTH);
		fgets(text, STRING_LENGTH, fpFile);
		text[strlen(text) - 1] = '\0';
		strcpy((*ptrConfigurationArray)[counter], text);
	}
	fclose(fpFile);
}

void readId()
{
	printConfigurationValue(getGeneralConfigurationValue("Id"), COLON_AND_SPACE);
	scanText(Id);
}

void printConfigurationValue(char* configurationFunction, char* details)
{
	printf("%s%s", configurationFunction, details);
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

void scanText(char* text)
{
	fgets(text, STRING_LENGTH, stdin);
	text[strlen(text) - 1] = '\0';
}

void create()
{
	fpDataFile = fopen(DATA_FILE, "a");
	printConfigurationValue(getGeneralConfigurationValue("Create"), NEW_LINE);
	printNewLine();
	for(counter = 0; counter < fieldCount; counter++)
	{
		memset(userInput, '\0', STRING_LENGTH);
		printf("Enter %s%s", field[counter], COLON_AND_SPACE);
		scanText(userInput);
		fwrite(userInput, STRING_LENGTH, 1, fpDataFile);
	}
	status = ACTIVE;
	fwrite(&status, 1, 1, fpDataFile);
	printConfigurationValue(getGeneralConfigurationValue("Details"), NEW_LINE);
	printNewLine();
	fclose(fpDataFile);
}

void view()
{
	fpDataFile = fopen(DATA_FILE, "r");
	countRecords(fpDataFile);
	printConfigurationValue(getGeneralConfigurationValue("View"), NEW_LINE);
	printNewLine();
	if(recordCount == INITIAL_VALUE)
	{
		printf("%s\n", getGeneralConfigurationValue("notCreated"));
	}
	for(counter = 0; counter < recordCount; counter++)
	{
		compareStatus(fpDataFile);
		if(confirmation == 'y')
		{
			for(fieldCounter = INITIAL_VALUE; fieldCounter < fieldCount; fieldCounter++)
			{
				fread(fieldValue, STRING_LENGTH, 1, fpDataFile);
				printf("%s: %s.\n", field[fieldCounter], fieldValue);
			}
			fseek(fpDataFile, 1, SEEK_CUR);
		}
		printNewLine();
	}
	fclose(fpDataFile);
}

void update()
{
	int updateChoice;
	fpDataFile = fopen(DATA_FILE, "r +");
	countRecords(fpDataFile);
	printConfigurationValue(getGeneralConfigurationValue("Update"), NEW_LINE);
	printNewLine();
	readId();
	for(recordCounter = INITIAL_VALUE; recordCounter < recordCount; recordCounter++)
	{
		compareStatus(fpDataFile);
		if(confirmation == 'y')
		{
			compareId(fpDataFile);
			if(IdConfirmation == 'y')
			{
				for(fieldCounter = 1; fieldCounter < fieldCount; fieldCounter++)
				{
					fread(fieldValue, STRING_LENGTH, 1, fpDataFile);
					printf("%s%s%s\n", field[fieldCounter], COLON_AND_SPACE, fieldValue);
				}
				fseek(fpDataFile, -(STRING_LENGTH * (fieldCount - 1)), SEEK_CUR);
				printNewLine();
				for(fieldCounter = 1; fieldCounter < fieldCount; fieldCounter++)
				{
					printf("%d) %s.\n", fieldCounter, field[fieldCounter]);	
				}
				printConfigurationValue(getGeneralConfigurationValue("Choice"), COLON_AND_SPACE);
				scanf("%d", &updateChoice);
				clearNewLineFromBuffer();
				for(fieldCounter = 1; fieldCounter < fieldCount; fieldCounter++)
				{
					if(fieldCounter == updateChoice)
					{
						printf("Enter %s%s", field[fieldCounter], COLON_AND_SPACE);
						scanText(userInput);
						fwrite(userInput, STRING_LENGTH, 1, fpDataFile);
						break;
					}
					else
					{
						fseek(fpDataFile, STRING_LENGTH, SEEK_CUR);
					}
				}
				printConfigurationValue(getGeneralConfigurationValue("Updated"), NEW_LINE);
				printNewLine();
				flag = 1;
			}
			else
			{
				fseek(fpDataFile, (STRING_LENGTH * (fieldCount - 1) + 1), SEEK_CUR);
			}
		}
	}
	printDetailsNotFound(flag);
	fclose(fpDataFile);
}

void delete()
{
	fpDataFile = fopen(DATA_FILE, "r +");
	countRecords(fpDataFile);
	char userConfirmation = 'n';
	printConfigurationValue(getGeneralConfigurationValue("Delete"), NEW_LINE);
	printNewLine();
	readId();
	for(counter = INITIAL_VALUE; counter < recordCount; counter++)
	{
		compareStatus(fpDataFile);
		if(confirmation == 'y')
		{
			compareId(fpDataFile);
			if(IdConfirmation == 'y')
			{
				for(fieldCounter = 1; fieldCounter < fieldCount; fieldCounter++)
				{
					fread(fieldValue, STRING_LENGTH, 1, fpDataFile);
					printf("%s%s%s\n", field[fieldCounter], COLON_AND_SPACE, fieldValue);
				}
				printConfigurationValue(getGeneralConfigurationValue("Confirmation"), COLON_AND_SPACE);
				scanf("%c", &userConfirmation);
				if(userConfirmation == 'y')
				{
					status = INACTIVE;
					fwrite(&status, 1, 1, fpDataFile);
					printConfigurationValue(getGeneralConfigurationValue("Deleted"), NEW_LINE);
				}
				printNewLine();
				flag = 1;
			}
			else
			{
				fseek(fpDataFile, (STRING_LENGTH * (fieldCount - 1) + 1), SEEK_CUR);
			}
		}
	}
	printDetailsNotFound(flag);
	fclose(fpDataFile);
}

void search()
{
	fpDataFile = fopen(DATA_FILE, "r +");
	countRecords(fpDataFile);
	char userConfirmation = 'n';
	printConfigurationValue(getGeneralConfigurationValue("Delete"), NEW_LINE);
	printNewLine();
	readId();
	for(counter = INITIAL_VALUE; counter < recordCount; counter++)
	{
		compareStatus(fpDataFile);
		if(confirmation == 'y')
		{
			compareId(fpDataFile);
			if(IdConfirmation == 'y')
			{
				for(fieldCounter = 1; fieldCounter < fieldCount; fieldCounter++)
				{
					fread(fieldValue, STRING_LENGTH, 1, fpDataFile);
					printf("%s%s%s\n", field[fieldCounter], COLON_AND_SPACE, fieldValue);
				}
				printNewLine();
				flag = 1;
			}
			else
			{
				fseek(fpDataFile, (STRING_LENGTH * (fieldCount - 1) + 1), SEEK_CUR);
			}
		}
	}
	printDetailsNotFound(flag);
	fclose(fpDataFile);
}


void exitFromProgram()
{
	printf("%s\n", getGeneralConfigurationValue("ThankYou"));
	exit(1);
}