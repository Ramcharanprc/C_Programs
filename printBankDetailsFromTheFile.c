// Print bank detialis from the file using fread.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define STRING_LENGTH 30
struct accountDetails
{
	char customerName[STRING_LENGTH], ifscCode[STRING_LENGTH];
	long int bankAccountNumber;
};
void main()
{
	int customerCounter = 0;
	FILE *printCustomerDetails;
	printf("Print bank details of customers.\n");
	printCustomerDetails = fopen("customerDetails.dat", "r");
	if(printCustomerDetails == NULL)	
	{
		printf("ERROR!\nFile not found.\n");
		exit(1);
	}
	struct accountDetails customerDetails;
	while(fread(&customerDetails, sizeof(struct accountDetails), 1, printCustomerDetails))
	{
		printf("Customer %d name is %s.\n", customerCounter + 1, customerDetails.customerName);
		printf("IFSC code of %s is %s.\n", customerDetails.customerName, customerDetails.ifscCode);
		printf("%s's account number is %ld.\n", customerDetails.customerName, customerDetails.bankAccountNumber);
		customerCounter++;
	}
	fclose(printCustomerDetails);
}