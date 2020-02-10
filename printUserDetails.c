//print user details from the file.
#include<stdio.h>
#include<stdlib.h>
#define STRING_LENGTH 100
struct details
{
	long int userId;
	char userName[STRING_LENGTH];
	long int contactNumber;
}userDetails;
void main()
{
	FILE *ptrFile;
	ptrFile = fopen("user.dat", "r");
	printf("Print user details.\n\n");
	while(fread(&userDetails, sizeof(struct details), 1, ptrFile))
	{
		printf("User ID is %ld.\n", userDetails.userId);
		printf("User name is %s.\n", userDetails.userName);
		printf("User contact number is %ld.\n\n", userDetails.contactNumber);
	}
	fclose(ptrFile);
}