/* flightGenerator.c
 *
 * This program will generate the flight information of the plane
 * incoming to the airport using random funtion to generate values
 *
 * Created by Nachanok Issarapruk (Tap) ID 61070503410
 * Edited by Sahachok Prachaporn (Lion) ID 61070503436
 * 26 Mar 2019 */

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include"datatype.h"
#include"validate.h"

int IDCount = 0;

/* This function will generate flight code in form AA1234 2 alphabets and 4 digits
 * refer to real airline code input flightCode char array of length 7 */
void generateFlightCode(char flightCode[])
	{
	char airline[61][3] = {"AA", "AC", "AZ", "AF", "SB", "NZ", "AI", "AM", "NH", "TN", "OS", "FJ", "LD", 
							"SU", "PX", "EL", "OZ", "CA", "BA", "CO", "CX", "CV", "CI", "MU", "CZ", "DL", 
							"H8", "MS", "EK", "BR", "FX", "AY", "GA", "KA", "IR", "JL", "EG", "KL", "KE", 
							"LH", "MH", "OM", "NW", "KZ", "PR", "PK", "PO", "QF", "RA", "SK", "UL", "SQ", 
							"LX", "FM", "TG", "TK", "UA", "HY", "5X", "VN", "VS"};
	char flightNumber[5] = {0};
	int temp = 0; 
	int i=0;
	time_t random = 0;
	random = rand()%100;
	strncpy(flightCode,airline[rand() % 61],2);
	/* random number in range 1000 - 9999 */
	temp = (rand() % (9999 - 1000 + 1) + 1000);
	sprintf(flightNumber,"%d",temp);
	strcat(flightCode,flightNumber);
	}

/* This function will generate position on x,y cordinate
 * return direction of the plane */
int generatePosition(int* x, int* y,int* z)
 	{
 	int heading = 0;
 	/* assume this airport have incoming plane only from wast */
 	/**x = (rand() % 100 + 1);*/
 	*x = 0;
 	*y = (rand() % 54 + 1);
	*z = (rand() % (6 - 3 +1) + 3) * 1000;
	if (*x == 0)
		{
		if (*y < (54)/3)
			heading = SE;
		else if (*y > (2*54)/3)
			heading = NE;
		else
			heading = E;
		}
	// else if (*x == 100)
	// 	{
	// 	if (*y < 20)
	// 		heading = SW;
	// 	else if (*y > 70)
	// 		heading = NW;
	// 	else
	// 		heading = W;
	// 	}
	// else if (*y == 0)
	// 	{
	// 	if (*x < 20)
	// 		heading = SE;
	// 	else if (*x > 70)
	// 		heading = SW;
	// 	else
	// 		heading = S;
	// 	}
	// else if (*y == 100)
	// 	{
	// 	if (*x < 20)
	// 		heading = NW;
	// 	else if (*x > 70)
	// 		heading = NE;
	// 	else
	// 		heading = N;
	// 	}
	return heading;
 	}

/* This function will generate all require data of the plane
 * and return as PLANE_T structure */
PLANE_T* generateFlight(int genSpeed)
	{
	printf("generate\n");
	PLANE_T* plane = NULL;
	int x;
	x = (rand() % 100 + 1);
	if (x < genSpeed)
		{
		plane = (PLANE_T*) calloc(1,sizeof(PLANE_T));
		/* This condition is use to check that plane generator work ok or not */
		if (plane == NULL)
			{
			printf("Calloc generated flight error!\n");
			exit(0);
			}
		while(1)
		{
		printf("flight code\n");
		generateFlightCode(plane->flight);
		if(checkFlightCode(plane->flight))
			break;
		}
		while(1)
			{
			plane->heading = generatePosition(&plane->position.x,&plane->position.y,&plane->position.z);
			if(checkDirection(plane->heading))
				break;
			}
		plane->order = LANDING;
		}
	plane->ID = IDCount;
	printf("ID: %d\n", plane->ID);
	IDCount += 1;
	return plane;
	}
