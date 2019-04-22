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
/* This function will generate flight code in form AA1234 2 alphabets and 4 digits
 * refer to real airline code input flightCode char array of length 7 */
void generateNumber(char flightCode[])
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
 	int side = 0; /* side of the plane arrive information */
 	*x = (rand() % 100 + 1);
 	*y = (rand() % 100 + 1);
	*z = (rand() % (6 - 3 +1) + 3) * 1000;
	side = (rand() % 2);
	if (side == 0)
		{
		if (*x <= 50)
			*x=0;
		else
			*x=100;
		}
	else
		{
		if (*y <= 50)
			{
			*y=0;
			}
		else
			{
			*y=100;
			}
		}
	return E;
 	}
/* This function will generate all require data of the plane
 * and return as PLANE_T structure */
PLANE_T* generateFlight()
{
	PLANE_T* plane = NULL; 
	plane = (PLANE_T*) calloc(1,sizeof(PLANE_T));
	/* This condition is use to check that plane generator work ok or not */
	if (plane == NULL)
		{
		printf("Calloc generated flight error!\n");
		exit(0);
		}
	generateNumber(plane->flight);
	plane->heading = generatePosition(&plane->position.x,&plane->position.y,&plane->position.z);
	plane->order = LANDING;
	return plane;
}