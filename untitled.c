#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	int randm = (rand() % 100000) + 1;
	printf("%d\n", randm);
}