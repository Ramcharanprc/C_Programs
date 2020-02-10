//Read user details and store them in a file.
#include<stdio.h>
#include<string.h>
#define STRING_LENGTH 
struct updateDetails
{
	long int userId;
	char userName[STRING_LENGTH];
	long int contactNumber;
	char job[STRING_LENGTH];
}updateUserDetails;
void main()
{
	char dummy, userConformation = 'y';
	int counter = 0;
	FILE *ptrFile;
	ptrFile = fopen("user.dat", "a");
	printf("Read user details.\n");
	while(userConformation == 'y')
	{
		printf("Enter user ID: ");
		scanf("%ld", &updateUserDetails.userId);
		scanf("%c", &dummy);
		printf("Enter user name: ");
		fgets(userDetails.userName, STRING_LENGTH, stdin);
		userDetails.userName[strlen(userDetails.userName) - 1] = '\0';
		printf("Enter contact details: ");
		scanf("%ld", &userDetails.contactNumber);
		scanf("%c", &dummy);
		printf("Do you want to continue: (y or n) ");
		scanf("%c", &userConformation);
		fwrite(&userDetails, sizeof(struct details), 1, ptrFile);
		counter++;
	}
	printf("%d details recorded successfully.\n");
	fclose(ptrFile);

}