//Print welcome to Hyderabad.
#include<stdio.h>
#include<string.h>
void main()
{
	char message[] = "Enter welcome note: ";
	char welcomeNote[100];
	printf("Print welcome note\n");
	printf("%s", message);
	fgets(welcomeNote, sizeof(welcomeNote), stdin);
	if(welcomeNote[strlen(welcomeNote) - 1] == '\n')
	{
		welcomeNote[strlen(welcomeNote) - 1] = '\0';
	}	
	// printf("%d", strlen(welcomeNote));
	printf("%s\n", welcomeNote);
	printf("%s", message);
	scanf("%s", welcomeNote);
	printf("%s\n", welcomeNote);
}