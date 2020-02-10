// Print numbers of books in a library.
#include<stdio.h>
#include<stdlib.h>
void main()
{
	int noOfRacks, NoOfShelves, counter = 0, *booksRegister, totalBooks = 0, noOfBooksInLibrary = 0;
	printf("Print number books in a library.\n");
	printf("Enter number of racks in the library: ");
	scanf("%d", &noOfRacks);
	printf("Enter number of shelves in a racks: ");
	scanf("%d", &NoOfShelves);
	booksRegister = malloc(sizeof(int) * noOfRacks * NoOfShelves);
	printf("\n");
	for(int racksCounter = 0; racksCounter < noOfRacks; racksCounter++)
	{
		for(int shelvesCounter = 0; shelvesCounter < NoOfShelves; shelvesCounter++)
		{
			printf("Enter rack %d shelf %d books count: ", racksCounter + 1, shelvesCounter + 1);
			scanf("%d", booksRegister + counter);
			counter++;
		}
		printf("\n");
	}
	counter = 0;
	for(int racksIndex = 0; racksIndex < noOfRacks; racksIndex++)
	{
		for(int shelvesIndex = 0; shelvesIndex < NoOfShelves; shelvesIndex++)
		{
			totalBooks = totalBooks + *(booksRegister + counter);
			counter++;
		}
		printf("Total books in rack %d are %d.\n", racksIndex + 1, totalBooks);
		noOfBooksInLibrary = noOfBooksInLibrary + totalBooks;
	}
	printf("\nTotal number of books in the library are %d.\n", noOfBooksInLibrary);
}