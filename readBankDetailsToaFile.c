//Read bank details to a file.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define STRING_LENGTH 30
struct accountDetails
{
	char customerName[STRING_LENGTH], ifscCode[STRING_LENGTH];
	long int bankAccountNumber;
};
void clearBuffer()
{
	char dummy;
	scanf("%c", &dummy);
	dummy = '\0';
}
void main()
{
	int customerCounter = 0;
	char userResponse = 'y';
	FILE *readCustomerDetails;
	readCustomerDetails = fopen("customerDetails.dat", "a");
	printf("Read bank details of customers.\n");
	struct accountDetails customerDetails;
	if(readCustomerDetails == NULL)
	{
		printf("ERROR!\nFile not found.\n");
		exit(1);
	}
	while(userResponse == 'y')
	{
		printf("Enter customer %d account number: ", customerCounter + 1);
		scanf("%ld", &customerDetails.bankAccountNumber);
		clearBuffer();

		printf("Enter customer %d name: ", customerCounter + 1);
		fgets(customerDetails.customerName, STRING_LENGTH, stdin);
		customerDetails.customerName[strlen(customerDetails.customerName) - 1] = '\0';

		printf("Enter customer %d IFSC code: ", customerCounter + 1);
		fgets(customerDetails.ifscCode, STRING_LENGTH, stdin);
		customerDetails.ifscCode[strlen(customerDetails.ifscCode) - 1] = '\0';

		customerCounter++;
		fwrite(&customerDetails, sizeof(struct accountDetails), 1, readCustomerDetails);

		printf("Do you want to enter another customer details? (y or n) ");
		scanf("%c", &userResponse);
		clearBuffer();
	}
	fclose(readCustomerDetails);
}