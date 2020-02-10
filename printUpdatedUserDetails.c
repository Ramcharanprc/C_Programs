//Print updated user details.
#include<stdio.h>
#include<stdlib.h>
#define STRING_LENGTH 100
struct updateDetails
{
	long int userId;
	char userName[STRING_LENGTH];
	long int contactNumber;
	char job[STRING_LENGTH];
}updateUserDetails;

void main()
{
	FILE *ptrFile;
	ptrFile = fopen("userUpdate.dat", "r");
	printf("Print user details.\n\n");
	while(fread(&updateUserDetails, sizeof(struct updateDetails), 1, ptrFile))
	{
		printf("User ID is %ld.\n", updateUserDetails.userId);
		printf("User name is %s.\n", updateUserDetails.userName);
		printf("User contact number is %ld.\n", updateUserDetails.contactNumber);
		printf("User designation is %s.\n\n", updateUserDetails.job);
	}
	fclose(ptrFile);
}  