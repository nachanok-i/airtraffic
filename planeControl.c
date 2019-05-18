/* planeControl->c
 *
 * control the plane position (moving) in the air and recieve command
 * from user and send it to control specific plane
 * Created by Nachanok Issarapruk (Tap) ID 61070503410
 * Edited by Sahachok Prachaporn (Lion) ID 61070503436
 * 26 Mar 2019 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"futureCollision.h"
#include"planeUtility.h"
#include"flightGenerator.h"
#include"validate.h"

#define MAXSIZE 128

void setup(int* genSpeed,int* maxPlane)
	{
	char input[32];
	*genSpeed = 10;
	*maxPlane = 10;
	printf("Welcome\n");
	printf("1. Generate speed (default 10 percents)\n");
	printf("2. Maximum plane (default 10 planes)\n");
	printf("Do you want to change?\n");
	while(1)
		{
		fgets(input,sizeof(input),stdin);
		if (strncasecmp(input,"y",1) == 0)
			{
			printf("1. Gen Speed\n");
			fgets(input,sizeof(input),stdin);
			sscanf(input,"%d",genSpeed);
			printf("2. Max plane\n");
			fgets(input,sizeof(input),stdin);
			sscanf(input,"%d",maxPlane);
			break;
			}
		else if (strncasecmp(input,"n",1) == 0)
			{
			break;
			}
		else
			{
			printf("Error - invalid answer\n");
			}
		}
	}

int getCommand()
	{
	char input[MAXSIZE];
	int returnVal = 0;
	printf("Enter command (Type \"help\" to see command) : ");
	fgets(input,MAXSIZE,stdin);
	sscanf(input,"%s",input);
	if (strlen(input)==1)
		returnVal = UPDATE;
	else if (strcmp(input,"search")==0)
		returnVal = SEARCH;
	else if (strcmp(input,"command")==0)
		returnVal = COMMAND;
	else if (strcmp(input,"help")==0)
		returnVal = HELP;
	else
		returnVal = -1;
	return returnVal;
	}

void runCycle()
	{
	if(updatePlane())
		{
		callPrintTree();
		}
	}

/* return pointer 
 NULL if not found */
PLANE_T * searchFlight()
	{
	char input[MAXSIZE];
	char target[7];
	int returnVal = 0;
	PLANE_T * plane = NULL;
	while(1)
		{
		printf("Enter flight number : ");
		fgets(input,MAXSIZE,stdin);
		if (strlen(input) > 7)
			{
			printf("Error - maximum digit is 6\n");
			}
		sscanf(input,"%s",target);
		if (checkFlightCode(target) == 0)
			{
			printf("Error - last 4 digits must be number\n");
			}
		else
			break;
		}
	plane = searchPlane(input);
	if (plane == NULL)
		{
		printf("The plane %s was not found\n",input);
		}
	return plane;
	}

int main()
	{
	PLANE_T* plane = NULL;
	int genSpeed = 10;
	int maxPlane = 10;
	int command = 0;
	srand(time(NULL));
	setup(&genSpeed,&maxPlane);
	plane = generateFlight(100);
	command = getCommand();
	switch (command)
		{
		case UPDATE:
			runCycle();
			break;
		case SEARCH:
			{
			PLANE_T * plane = NULL;
			plane = searchFlight();
			if (plane != NULL)
				printPlane(plane);
			}
			break;
		case COMMAND:
			break;
		default:
			printf("Error - invalid command\n");
			break;
		}
	}