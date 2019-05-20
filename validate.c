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
 * return 0 - if flight is invalid
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
				break;
				}
			}
		}
	return returnVal;
	}

/* This function use to check direction from user
 * direction must be N,NE,E,SE,S,SW,W,NW
 * return 1 - if it is valid
 * return 0 - if it is invalid
*/
int checkDirection(char direction[])
	{
	int returnVal = -1;
	if (strcasecmp(direction,"N")==0)
		returnVal = N;
	else if (strcasecmp(direction,"NE")==0)
		returnVal = NE;
	else if (strcasecmp(direction,"E")==0)
		returnVal = E;
	else if (strcasecmp(direction,"SE")==0)
		returnVal = SE;
	else if (strcasecmp(direction,"S")==0)
		returnVal = S;
	else if (strcasecmp(direction,"SW")==0)
		returnVal = SW;
	else if (strcasecmp(direction,"W")==0)
		returnVal = W;
	else if (strcasecmp(direction,"NW")==0)
		returnVal = NW;
	else
		return -1;
	}

/* This functionuse to check if user give the correct height
 * height must be between 3000 - 6000
 * return 1 - if input is valid
 * return 0 - if input is invalid
*/
int checkAltitude(int height)
	{
	if ((height >= 3000) && (height <= 6000) && height % 1000 == 0)
		return 1;
	else 
		return 0;
	}

/* This function use to check input command from user
 * commands must be "direction","altitude","order"
 * return command value (emun value)
 * return -1 - if command is invalid
*/
// int checkInputCommand(char input[])
// 	{
// 	if (strcmp(input,"landing") == 0)
// 		{
// 		return LANDING;
// 		}
// 	else if (strcmp(input,"takeoff") == 0)
// 		{
// 		return TAKEOFF;
// 		}
// 	else if (strncmp(input,"cir",3) == 0)
// 		{
// 		return CIRCLE;
// 		}
// 	else if (strncmp(input,"dir",3) == 0)
// 		{
// 		return DIRECTION;
// 		}
// 	else if (strncmp(input,"alt",3) == 0)
// 		{
// 		return ALTITUDE;
// 		}
// 	else
// 		return -1;
// 	}
