/* planeControl->c
 *
 * control the plane position (moving) in the air and recieve command
 * from user and send it to control specific plane
 * Created by Nachanok Issarapruk (Tap) ID 61070503410 on 26 Mar 2019
 * Edited by Sahachok Prachaporn (Lion) ID 61070503436
 * Edited by Sutinan Tadalimavad (Lion) ID 61070503443 on 20 May 2019
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"futureCollision.h"
#include"planeUtility.h"
#include"flightGenerator.h"
#include"validate.h"

#define MAXSIZE 128
#define STOP 10

int genSpeed = 10; /* plane generation speed */
int maxPlane = 10; /* maximum amount of plane that can have */

void setup()
	{
	char input[32];  /* input variable */
	printf("------------------------------------------------------------------------>\n\n");
	printf("\t\tWelcome to Air Traffic Control System Simulation\t\t\n\n");
	printf("------------------------------------------------------------------------>\n\n");	
	printf("SETUP MENU\n");
	printf("1. Plane Generate Speed (default 10%)\n");
	printf("2. Maximum Plane in the sky (default 10 planes)\n");
	printf("Do you want to change setup? (Y/N) : ");
	fgets(input,sizeof(input),stdin);
	if (strncasecmp(input,"Y",1)==0)
		{
		printf("\n");
		while(1)
			{
			printf("1. Generate speed (default 10 percents)\n");
			fgets(input,sizeof(input),stdin);
			sscanf(input,"%d",&genSpeed);
			if (genSpeed > 0 && genSpeed <= 100)
				break;
			else
				printf("\tError - Gen speed have to be 1-100\n");
			}
		while(2)
			{
			printf("2. Number of plane (Maximum of 10 planes)\n");
			fgets(input,sizeof(input),stdin);
			sscanf(input,"%d",&maxPlane);
			if ((maxPlane > 0) && (maxPlane <= 10))
				{
				setMaxPlane(maxPlane);
				break;
				}
			else
				printf("\tError - Number of plane have to be 1-10\n");
			}
		}
	printf("\n");
	}

int getCommand()
	{
	char input[MAXSIZE]; /* input variable */
	int returnVal = 0;   /* return value */
	
	printf("Enter command (Type \"help\" to see command) : ");
	fgets(input,MAXSIZE,stdin);
	sscanf(input,"%s",input);
	if (strlen(input)==1)
		returnVal = UPDATE;
	else if (strcmp(input,"search")==0)
		returnVal = SEARCH;
	else if (strcmp(input,"show")==0)
		returnVal = SHOW;
	else if (strcmp(input,"command")==0)
		returnVal = COMMAND;
	else if (strcmp(input,"help")==0)
		returnVal = HELP;
	else if (strcmp(input,"stop")==0)
		returnVal = STOP;
	else
		returnVal = -1;
	return returnVal;
	}

/* this function is use to start cycle 
 when user don't want to enter command */
void runCycle()
	{
	int currentAmount = getCurrentAmount();
	PLANE_T * plane = NULL;
	if(currentAmount < maxPlane)
		plane = generateFlight(genSpeed);
	if (plane != NULL)
		insertNode(plane);
	updatePlane();
	callPrintTree();
	}

/* return pointer 
 NULL if not found */
PLANE_T * searchFlight()
	{
	char input[MAXSIZE];
	char target[7];
	int returnVal = 0;
	PLANE_T * plane = NULL;
	PLANENODE_T * node = NULL;
	while(1)
		{
		printf("Enter flight number : ");
		fgets(input,MAXSIZE,stdin);
		sscanf(input,"%s",input);
		if (strlen(input) > 7)
			{
			printf("\tError - maximum digit is 6\n");
			}
		sscanf(input,"%s",target);
		if (checkFlightCode(target) == 0)
			{
			printf("\tError - invalid flight number\n");
			}
		else
			break;
		}
	node = searchPlane(input);
	plane = node->data;
	if (plane == NULL)
		{
		printf("\tThe plane %s was not found\n",input);
		}
	return plane;
	}

void inputCommand(PLANE_T * plane,int choice)
	{
	switch (choice)
		{
		
		}
	}

void helpMenu()
	{
	printf("How to use command\n");
	printf("\t- hit enter to update current plane (without any command).\n");
	printf("\t- \"search\" to search specific plane and print out the data.\n");
	printf("\t- \"show\" to show current plane active on the sky.\n");
	printf("\t- \"command [flight number] [input command]\" to enter command to specific plane.\n");
	printf("\t\tCommand list:\n");
	printf("\t\t1.\"landing\" to command the plane to land.\n");
	printf("\t\t2.\"cir:[radius]\" to command plane to fly in circle.\n");
	printf("\t\t3.\"takeoff\" to command the plane to takeoff.\n");
	printf("\t\t4.\"alt:[altitude]\" to command the plane to change altitude.\n");
	printf("\t\t5.\"dir:[direction]\" to change the direction of the plane (N,NE,S,W,etc).\n");
	printf("\t\"setup\" to set plane's generation speed and maximum plane in the sky.\n");
	printf("\t- \"help\" to print help menu.\n");
	printf("\t- \"stop\" to stop the program.\n");

	}

int main()
	{
	PLANE_T* plane = NULL;
	int command = 0;
	srand(time(NULL));
	setup();
	plane = generateFlight(100);
	while(1)
		{
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
			case SHOW:
				callPrintTree();
			case COMMAND:
				break;
			case HELP:
				helpMenu();
				break;
			case STOP:
				exit(1);
			default:
				printf("\tError - invalid command\n");
				break;
			}
		}
	}