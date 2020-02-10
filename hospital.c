//Program to create, print, update, delete and search patient details.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define STRING_LENGTH 50
#define INITIAL_VALUE 0
#define ACTIVE "Not Discharged"
#define INACTIVE "Discharged"
#define FILE_NAME "patients.dat"

void createPatientDetails();
void printPatientDetails();
void updatePatientDetails();
void dischargePatient();
void searchPatientDetails();
void clearNewLineFromBuffer();
void printpatientId(char details[STRING_LENGTH]);
void printpatientName(char details[STRING_LENGTH]);
void printContactNumber(char details[STRING_LENGTH]);
void readText(char details[STRING_LENGTH]);
void printDetailsNotFound(int Checkflag);

struct patient
{
	char patientId[STRING_LENGTH], patientName[STRING_LENGTH];
	char contactNumber[STRING_LENGTH], status[STRING_LENGTH];
}patientDetails;

FILE *ptrFile;
char confirmation;
char Id[STRING_LENGTH];
int flag = INITIAL_VALUE;

void main()
{
	printf("Welcome to Image Hospital.\n");
	printf("1) Create new patient details.\n2) Print patient details.\n3) Update patient details.\n");
	printf("4) Discharge patient.\n5) Search patient details.\n6) Exit.\n");
	confirmation = 'n';
	int userOption;
	do
	{
		printf("\nPlease enter your choice: ");
		scanf("%d", &userOption);
		clearNewLineFromBuffer();
		if(userOption != 1 && userOption != 2 && userOption != 3 && userOption != 4 && userOption != 5 && userOption != 6)	
		{
			printf("Invalid choice.\nPlease enter a valid number.\n");
		}
		else
		{
			confirmation = 'y';
		}
	}while(confirmation == 'n');
	confirmation = 'y';
	switch(userOption)
	{
		case 1:
		createPatientDetails();
		main();
		break;

		case 2:
		printPatientDetails();
		main();
		break;

		case 3:
		updatePatientDetails();
		main();
		break;

		case 4:
		dischargePatient();
		main();
		break;

		case 5:
		searchPatientDetails();
		main();
		break;

		case 6:
		exit(1);
	}
}

void clearNewLineFromBuffer()
{
	char dummy;
	scanf("%c", &dummy);
	dummy = '\0';
}

void printNewLine()
{
	printf("\n");
}

void printDetailsNotFound(int checkFlag)
{
	if(checkFlag != 1)
	{
		printf("Details not found.\nEnter a valid patient ID.\n\n");
		flag = 0;
	}
}

void printpatientId(char details[STRING_LENGTH])
{
	printf("patient ID is %.*s.\n", STRING_LENGTH, details);
}

void printpatientName(char details[STRING_LENGTH])
{
	printf("patient name is %s.\n", details);
}

void printContactNumber(char details[STRING_LENGTH])
{
	printf("patient contact number is %s.\n", details);
}

void patientIdRequest(char IdRequest[STRING_LENGTH])
{
	printf("Enter patient ID: ");
	readText(IdRequest);
}

void printStatus(char details[STRING_LENGTH])
{
	printf("Status: %s.\n\n", patientDetails.status);
}

void readText(char details[STRING_LENGTH])
{
	fgets(details, STRING_LENGTH, stdin);
	details[strlen(details) - 1] = '\0';
}

void createPatientDetails()
{
	ptrFile = fopen(FILE_NAME, "a");
	printf("\nCreate a new patient details.\n");
	printf("Enter patient ID: ");
	readText(patientDetails.patientId);
	printf("Enter patient name: ");
	readText(patientDetails.patientName);
	printf("Enter patient contact number: ");
	readText(patientDetails.contactNumber);
	strcpy(patientDetails.status, ACTIVE);
	fwrite(&patientDetails, sizeof(struct patient), 1, ptrFile);
	printf("Details recorded successfully.\n");
	printNewLine();
	fclose(ptrFile);
}

void printPatientDetails()
{
	ptrFile = fopen(FILE_NAME, "r");
	int counter = INITIAL_VALUE;
	printf("\nPrint patient details.\n");
	while(fread(&patientDetails, sizeof(struct patient), 1, ptrFile))
	{
		if(strcmp(patientDetails.status, ACTIVE) == 0)
		{
			printpatientId(patientDetails.patientId);
			printpatientName(patientDetails.patientName);
			printContactNumber(patientDetails.contactNumber);
			printStatus(patientDetails.status);
			counter++;
		}
	}
	if(counter == 0)
	{
		printf("No patient records are created yet.\nPlease create.\n\n");
	}
	fclose(ptrFile);
}

void updatePatientDetails()
{
	ptrFile = fopen(FILE_NAME, "r +");
	int modification;
	printf("\nUpdate patient's salary.\n");
	patientIdRequest(Id);
	printNewLine();
	while(fread(&patientDetails, sizeof(struct patient), 1, ptrFile))
	{
		if(strcmp(patientDetails.status, ACTIVE) == 0)
		{
			if(strcmp(patientDetails.patientId, Id) == 0)
			{
				printpatientId(patientDetails.patientId);
				printpatientName(patientDetails.patientName);
				printContactNumber(patientDetails.contactNumber);
				printf("1) Name.\n2) Contact Number.\n");
				printf("Enter your choice of modification: ");
				scanf("%d", &modification);
				clearNewLineFromBuffer();
				if(modification == 1)
				{
					printf("Enter patient name: ");
					readText(patientDetails.patientName);
				}
				else if(modification == 2)
				{
					printf("Enter patient contact number: ");
					readText(patientDetails.contactNumber);
				}
				fseek(ptrFile, -sizeof(struct patient), SEEK_CUR);
				fwrite(&patientDetails, sizeof(struct patient), 1, ptrFile);
				printf("patient details updated successfully.\n\n");
				flag = 1;
				break;
			}	
		}
	}
	printDetailsNotFound(flag);
	fclose(ptrFile);
}

void dischargePatient()
{
	ptrFile = fopen(FILE_NAME, "r +");
	printf("\nDelete patient detials.\n");
	patientIdRequest(Id);
	printNewLine();
	while(fread(&patientDetails, sizeof(struct patient), 1, ptrFile))
	{
		if(strcmp(patientDetails.status, ACTIVE) == 0)
		{
			if(strcmp(patientDetails.patientId, Id) == 0)
			{
				printpatientId(patientDetails.patientId);
				printpatientName(patientDetails.patientName);
				printContactNumber(patientDetails.contactNumber);
				printf("Patient discharge confirmation: (y or n) ");
				scanf("%c", &confirmation);
				clearNewLineFromBuffer();
				if(confirmation == 'y')
				{
					strcpy(patientDetails.status, INACTIVE);
				}
				fseek(ptrFile, -sizeof(struct patient), SEEK_CUR);
				fwrite(&patientDetails, sizeof(struct patient), 1, ptrFile);
				printf("patient details are deleted successfully.\n\n");
				flag = 1;
				break;	
			}
		}
	}
	printDetailsNotFound(flag);
	fclose(ptrFile);
}

void searchPatientDetails()
{
	ptrFile = fopen(FILE_NAME, "r");
	printf("\nSearch for an patient.\n");
	patientIdRequest(Id);
	printNewLine();
	while(fread(&patientDetails, sizeof(struct patient), 1, ptrFile))
	{
		if(strcmp(patientDetails.patientId, Id) == 0)
		{
			printpatientId(patientDetails.patientId);
			printpatientName(patientDetails.patientName);
			printContactNumber(patientDetails.contactNumber);
			printStatus(patientDetails.status);
			printNewLine();
			flag = 1;
			break;
		}
	}
	printDetailsNotFound(flag);
	fclose(ptrFile);
}