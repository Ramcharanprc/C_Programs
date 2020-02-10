//Print customer account details.
#include<stdio.h>
#define STRING_LENGTH 20
struct accountDetails
{
	char customerName[STRING_LENGTH];
	char bankName[STRING_LENGTH];
	char branchName[STRING_LENGTH];
	long accountNumber;
	char ifscCode[STRING_LENGTH];
	long customerPhoneNumber;
}customerDetails;

void main()
{
	char message[] = "Enter", account[] = "account", number[] = "number";
	char name[] = "name", customer[] = "customer", is[] = "is", bank[] = "bank";
	char branch[] = "branch", IFSC[] = "IFSC", code[] = "code", phone[] = "phone";
	printf("Print customer %s details.\n", number);
	printf("%s %s holder %s: ", message, account, name);
	fgets(customerDetails.customerName, sizeof(customerDetails.customerName), stdin);
	//scanf("%s", customerDetails.customerName);

	printf("%s %s %s: ", message, bank, name);
	scanf("%s", customerDetails.bankName);

	printf("%s %s %s: ", message, branch, name);
	scanf("%s", customerDetails.branchName);

	printf("%s %s %s: ", message, account, number);
	scanf("%ld", &customerDetails.accountNumber);

	printf("%s %s %s: ", message, IFSC, code);
	scanf("%s", customerDetails.ifscCode);

	printf("%s %s %s: ", message, phone, number);
	scanf("%ld", &customerDetails.customerPhoneNumber);

	printf("\n%s %s %s ", customer, name, is);
	puts(customerDetails.customerName);
	printf("%s %s %s %s %s.\n", customer, bank, number, is, customerDetails.bankName);
	printf("%s %s %s %s %s.\n", customer, branch, name, is, customerDetails.branchName);
	printf("%s %s %s %s %ld.\n", customer, account, number, is, customerDetails.accountNumber);
	printf("%s %s %s %s %s.\n", customer, IFSC, code, is, customerDetails.ifscCode);
	printf("%s %s %s %s %ld.\n", customer, phone, number, is, customerDetails.customerPhoneNumber);
	printf("Thank you.\n");
}