//Print temperature of the city.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define STRING_LENGTH 10000
#define File "weatherMap.dat"
#define TEMPERATURE "temp"
#define INITIAL_COUNT 0
void concatCommand(char command[STRING_LENGTH], char link[STRING_LENGTH])
{
	strcat(command, link);
}
void main()
{
	int counter = INITIAL_COUNT;
	float temperature;
	char command[STRING_LENGTH], weatherDetailsString[STRING_LENGTH];
	char cityName[STRING_LENGTH], delimiter[] = "{},[]";
	printf("Print temperature of a city.\n");
	printf("Enter the city name: ");
	fgets(cityName, STRING_LENGTH, stdin);
	cityName[strlen(cityName) - 1] = '\0';
	char splitWeatherDetails[100][STRING_LENGTH];
	sprintf(command, "curl 'https://api.openweathermap.org/data/2.5/find?q=%s&units=metric&appid=60113b36f0a83502fe59ba9e512b76d4' > %s -s", cityName, File);
	system(command);
	FILE *ptrWeatherDetails = fopen(File, "r");
	fgets(weatherDetailsString, STRING_LENGTH, ptrWeatherDetails);
	char *stringToken = strtok(weatherDetailsString, delimiter);
	while(stringToken != NULL)
	{
		if(strstr(stringToken, TEMPERATURE) != NULL)
		{
			strcpy(splitWeatherDetails[counter], stringToken);
			counter++;  
		}
		stringToken = strtok(NULL, delimiter);
	}
	// strcpy(delimiter, ":");
	printf("Temperature in %s is %s*c.\n", cityName, &splitWeatherDetails[INITIAL_COUNT][7]);
	fclose(ptrWeatherDetails);
}