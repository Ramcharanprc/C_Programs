//print underline.
#include<stdio.h>
void underline(char printUnderline)
{
	printf("\e[4m%s\e[0m\n", printUnderline);
}
