/*
 * validate.c
 * this program use to check validate of user input
 * Created by Sutinan Tadalimavad (Lion) on 20/04/2019
 * ID 61070503443
 *
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include"datatype.h"

/* This function use to check input from menu
 * return 1 - if input is correct
 * return 0 - if input is invalid
*/
int checkNumber(int choice)
	{
	if (isdigit(choice) == 1)
		return 1;
	else
		return 0;
	}

/* This function use to check flight code if it is valid code 
 * return 1 - if flight code is correct
 * return 0 - if flight is unvalid
*/
int checkFlightCode(char input[])
	{
	char flightSource[61][3] = {"AA", "AC", "AZ", "AF", "SB", "NZ", "AI", "AM", "NH", "TN",
								"OS", "FJ", "LD", "SU", "PX", "EL", "OZ", "CA", "BA", "CO",
								"CX", "CV", "CI", "MU", "CZ", "DL", "H8", "MS", "EK", "BR",
								"FX", "AY", "GA", "KA", "IR", "JL", "EG", "KL", "KE", "LH",
								"MH", "OM", "NW", "KZ", "PR", "PK", "PO", "QF", "RA", "SK",
								"UL", "SQ", "LX", "FM", "TG", "TK", "UA", "HY", "5X", "VN", "VS"};
	int returnVal = 0;
	int i = 0;
	for (i = 0; i < 61; i++)
		{
		if (strncmp(input,flightSource[i],2) == 0)
			{
			returnVal = 1;
			break;
			}
		}
	if (returnVal == 1)
		{
		for (i = 2; i < 6; i++)
			{
			if (isdigit(input[i]) == 0)
				{
				returnVal = 0;
				printf("number %c\n",input[i]);
				break;
				}
			}
		}
	else
		printf("code not valid\n");
	return returnVal;
	}

/* This function use to check direction from user
 * direction must be N,NE,E,SE,S,SW,W,NW
 * return 1 - if it is valid
 * return 0 - if it is invalid
*/
int checkDirection(int direction)
	{
	if ((direction >= 1) && (direction <=8))
		return 1;
	else
		return 0;
	}

/* This functionuse to check if user give the correct height
 * height must be between 3000 - 6000
 * return 1 - if input is valid
 * return 0 - if input is invalid
*/
int checkAltitude(int height)
	{
	if ((height >= 3000) && (height <= 6000))
		return 1;
	else 
		return 0;
	}

/* This function use to check if user give valid command for
 * "order" command
 * commands could be "landing","circle","takeoff"
 * return 1 - if it is valid
 * return 0 - if it is invalid
*/
int checkOrder(char command[])
	{
	if (strcmp(command,"landing") == 1)
		return 1;
	else if (strcmp(command,"circle") == 1)
		return 1;
	else if (strcmp(command,"takeoff") == 1)
		return 1;
	else 
		return 0;
	}

/* This function use to check command from user
 * commands must be "direction","altitude","order"
 * return 1 - if command is correct
 * return 0 - if command is invalid
*/
int checkCommand(char input[])
	{
	if (strcmp(input,"direction") == 1)
		return 1;
	else if (strcmp(input,"altitude") == 1)
		return 1;
	else if (strcmp(input,"order") == 1)
		return 1;
	else
		return 0;
	}

/* This function use to check command from user
 * return 1 - if it is "status"
 * return 2 - if it is "command"
 * return 0 - if it is no match
*/
int checkAgru(char input[])
	{
	if (strcmp(input,"status") == 0)
		return 1;
	else if (strcmp(input,"command") == 0)
		return 2;
	else 
		return 0;
	}
