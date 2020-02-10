//Program to create, print, update, cancel and search passenger details
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define STRING_LENGTH 50
#define FILE_NAME "passengers.dat"
#define ACTIVE 'A'
#define INACTIVE 'D'
#define INITIAL_VALUE 0

void bookTicket();
void viewBookingList();
void updatebookingDetails();
void cancleTicket();
void findBookingDetails();
void clearNewLineFromBuffer();
void printNewLine();
void printDetailsNotFound(int checkFlag);
void printTicketNumber(char details[STRING_LENGTH]);
void printPassengerName(char details[STRING_LENGTH]);
void printContactNumber(char details[STRING_LENGTH]);
void scanText(char details[STRING_LENGTH]);

struct passenger
{
	char ticketNumber[STRING_LENGTH], passengerName[STRING_LENGTH];
	char status, contactNumber[STRING_LENGTH];
}passengerDetails;

int flag = INITIAL_VALUE;
FILE *ptrFile;
char confirmation;
char userRequest[STRING_LENGTH];

void main()
{
	printf("Welcome to Red Bus.\n");
	printf("1) Book a ticket.\n2) View booking list.\n3) Update booking details.\n");
	printf("4) Cancel the ticket.\n5) Find booking details.\n6) Exit.\n");
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
		bookTicket();
		main();

		case 2:
		viewBookingList();
		main();

		case 3:
		updatebookingDetails();
		main();

		case 4:
		cancleTicket();
		main();

		case 5:
		findBookingDetails();
		main();
		
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

void printContactNumber(char details[STRING_LENGTH])
{
	printf("Passenger contact number is %s.\n", details);
}

void printNewLine()
{
	printf("\n");
}

void printPassengerName(char details[STRING_LENGTH])
{
	printf("Passenger name is %s.\n", details);
}

void printTicketNumber(char details[STRING_LENGTH])
{
	printf("Passenger ticket number is %s.\n", details);
}

void requestTicketNumber(char userRequest[STRING_LENGTH])
{
	printf("Enter passenger ticket number: ");
	scanText(userRequest);
}

void scanText(char details[STRING_LENGTH])
{
	fgets(details, STRING_LENGTH, stdin);
	details[strlen(details) - 1] = '\0';
}

void printDetailsNotFound(int checkFlag)
{
	if(checkFlag != 1)
	{
		printf("Details not found.\nEnter a valid ticket number.\n\n");
		flag = INITIAL_VALUE;
	}
}

void bookTicket()
{
	ptrFile = fopen(FILE_NAME, "a");
	printf("Book a ticket.\n");
	printf("Enter ticket number: ");
	scanText(passengerDetails.ticketNumber);
	printf("Enter passenger name: ");
	scanText(passengerDetails.passengerName);
	printf("Enter passenger contact number: ");
	scanText(passengerDetails.contactNumber);
	passengerDetails.status = ACTIVE;
	fwrite(&passengerDetails, sizeof(struct passenger), 1, ptrFile);
	printf("Ticket generated successfully.\n");
	printNewLine();
	fclose(ptrFile);
}

void viewBookingList()
{
	ptrFile = fopen(FILE_NAME, "r");
	printf("Bookings list.\n\n");
	int counter = INITIAL_VALUE;
	while(fread(&passengerDetails, sizeof(struct passenger), 1, ptrFile))
	{
		if(passengerDetails.status == ACTIVE)
		{
			printTicketNumber(passengerDetails.ticketNumber);
			printPassengerName(passengerDetails.passengerName);
			printContactNumber(passengerDetails.contactNumber);
			printNewLine();
			counter++;
		}
	}
	if(counter == INITIAL_VALUE)
	{
		printf("No bookings are created yet.\nPlease create.\n");
	}
	fclose(ptrFile);
}

void updatebookingDetails()
{
	int modification;
	ptrFile = fopen(FILE_NAME, "r +");
	printf("Update booking details.\n");
	requestTicketNumber(userRequest);
	printNewLine();
	while(fread(&passengerDetails, sizeof(struct passenger), 1, ptrFile))
	{
		if(passengerDetails.status == ACTIVE)
		{
			if(strcmp(passengerDetails.ticketNumber, userRequest) == INITIAL_VALUE)
			{
				printTicketNumber(passengerDetails.ticketNumber);
				printPassengerName(passengerDetails.passengerName);
				printContactNumber(passengerDetails.contactNumber);
				printNewLine();
				printf("1) Name.\n2) Contact Number.\n");
				printf("Enter your choice of modification: ");
				scanf("%d", &modification);
				clearNewLineFromBuffer();
				if(modification == 1)
				{
					printf("Enter passenger name: ");
					scanText(passengerDetails.passengerName);
				}
				else if(modification == 2)
				{
					printf("Enter passenger contact number: ");
					scanText(passengerDetails.contactNumber);
				}
				fseek(ptrFile, -sizeof(struct passenger), SEEK_CUR);
				fwrite(&passengerDetails, sizeof(struct passenger), 1, ptrFile);
				printf("Booking details are updated successfully.\n\n");
				flag = 1;
				break;
			}
		}
	}
	printDetailsNotFound(flag);
	fclose(ptrFile);
}

void cancleTicket()
{
	ptrFile = fopen(FILE_NAME, "r +");
	printf("Cancel the ticket.\n");
	requestTicketNumber(userRequest);
	printNewLine();
	while(fread(&passengerDetails, sizeof(struct passenger), 1, ptrFile))
	{
		if(passengerDetails.status == ACTIVE)
		{
			if(strcmp(passengerDetails.ticketNumber, userRequest) == INITIAL_VALUE)
			{
				printTicketNumber(passengerDetails.ticketNumber);
				printPassengerName(passengerDetails.passengerName);
				printContactNumber(passengerDetails.contactNumber);
				printNewLine();
				printf("Do you want to cancel the ticket? (y or n) ");
				scanf("%c", &confirmation);
				clearNewLineFromBuffer();
				if(confirmation == 'y')
				{
					passengerDetails.status = INACTIVE;
				}
				fseek(ptrFile, -sizeof(struct passenger), SEEK_CUR);
				fwrite(&passengerDetails, sizeof(struct passenger), 1, ptrFile);
				flag = 1;
				break;	
			}
		}
	}
	printDetailsNotFound(flag);
	fclose(ptrFile);
}

void findBookingDetails()
{
	ptrFile = fopen(FILE_NAME, "r");
	printf("Find booking details.\n");
	requestTicketNumber(userRequest);
	printNewLine();
	while(fread(&passengerDetails, sizeof(struct passenger), 1, ptrFile))
	{
		if(passengerDetails.status == ACTIVE)
		{
			if(strcmp(passengerDetails.ticketNumber, userRequest) == INITIAL_VALUE)
			{
				printTicketNumber(passengerDetails.ticketNumber);
				printPassengerName(passengerDetails.passengerName);
				printContactNumber(passengerDetails.contactNumber);
				printNewLine();
				flag = 1;
				break;
			}
		}
	}
	printDetailsNotFound(flag);
	fclose(ptrFile);
}
