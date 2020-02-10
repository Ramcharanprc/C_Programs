#include<stdio.h>
void printHello();
void printName();
void main()
{
	void (*ptrFunction[2])();
	(ptrFunction[0]) = &printHello;
	(ptrFunction[0])();
	(ptrFunction[1]) = &printName;
	(ptrFunction[1])();
}

void printHello()
{
	printf("Hello!\n");
}

void printName()
{
	printf("My name is Ramcharan.\n");
}