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

/* This function use to check flight code if it is valid code 
 * return 1 - if flight code is correct
 * return 0 - if flight is unvalid
*/
int checkCode(void* flight)
	{
	char flightSource[61][3] = {"AA", "AC", "AZ", "AF", "SB", "NZ", "AI", "AM", "NH", "TN",
								"OS", "FJ", "LD", "SU", "PX", "EL", "OZ", "CA", "BA", "CO",
								"CX", "CV", "CI", "MU", "CZ", "DL", "H8", "MS", "EK", "BR",
								"FX", "AY", "GA", "KA", "IR", "JL", "EG", "KL", "KE", "LH",
								"MH", "OM", "NW", "KZ", "PR", "PK", "PO", "QF", "RA", "SK",
								"UL", "SQ", "LX", "FM", "TG", "TK", "UA", "HY", "5X", "VN", "VS"};
	char flightCode[7];
	int i = 0;
	PLANE_T* input = (PLANE_T*) flight;

	strcpy(input->ID,flightCode);
	for (i = 0; i < 61; i++)
		{
		if (flightCode[0] == flightSource[i][0])
			{
			if (flightCode[1] == flightSource[i][1])
				return 1;
			else
				{
				printf("ERROR - unknown flight code\n");
				exit (0);
				}
			}
		else
			{
			printf("ERROR - unknown flight code\n");
			exit (1);
			}
		}
	}

/* This function use to check flight number if it is number or not
 * return 1 - if flight number is in correct form
 * return 0 - if flight number is invalid
 *
*/
int checkNumber(void* flight)
	{
	char flightCode[7];
	PLANE_T* input = (PLANE_T*) flight;

	strcpy(input->ID,flightCode);
	if (isdigit(flightCode[2]) == 1)
		{
		if (isdigit(flightCode[3]) == 1)
			{
			if (isdigit(flightCode[4]) == 1)
				{
				if (isdigit(flightCode[5]) == 1)
					return 1;
				else 
					return 0;
				}
			else
				return 0;
			}
		else
			return 0;
		}
	else 
		return 0;
	}

/* This fucntion use to check flight code if it is correct
 * return 1 - if code is valid
 * return 0 - if code is invalid
 *
*/
int checkFlightCode(void* flight)
	{
	PLANE_T* input = (PLANE_T*) flight;
	if ((checkCode(input) == 1) && (checkNumber(input) == 1))
		return 1;
	else
		return 0;
	}