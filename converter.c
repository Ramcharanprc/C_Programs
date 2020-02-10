//Transfer user details from old file to a new file with updated deatails.
#include<stdio.h>
#include<string.h>
#define STRING_LENGTH 100
struct details
{
	long int userId;
	char userName[STRING_LENGTH];
	long int contactNumber;
}userDetails;

struct updateDetails
{
	long int userId;
	char userName[STRING_LENGTH];
	long int contactNumber;
	char job[STRING_LENGTH];
}updateUserDetails;

void main()
{
	int counter = 0;
	FILE *ptrOldFile;
	FILE *ptrNewFile;
	ptrOldFile = fopen("user.dat", "r");
	ptrNewFile = fopen("userUpdate.dat", "w");
	while(fread(&userDetails, sizeof(struct details), 1, ptrOldFile))
	{
		updateUserDetails.userId = userDetails.userId;
		strcpy(updateUserDetails.userName, userDetails.userName);
		updateUserDetails.contactNumber = userDetails.contactNumber;
		printf("Enter %s's job: ", updateUserDetails.userName);
		fgets(updateUserDetails.job, STRING_LENGTH, stdin);
		updateUserDetails.job[strlen(updateUserDetails.job) - 1] = '\0';
		fwrite(&updateUserDetails, sizeof(struct updateDetails), 1, ptrNewFile);
		counter++;
	}
	printf("%d details updated successfully.\n", counter);
	pclose(ptrOldFile);
	pclose(ptrNewFile);
}
