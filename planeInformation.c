/* planeInformation.c
 * This file is part of airtraffic control. This file is about controling
 * airplane structure from main file
 * Created by Nachanok Issarapruk (Tap) ID 61070503410
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"flightGenerator.h"

PLANE_T* addAirPlane()
	{
	int x=0;
	int y=0;
	int z=0;
	PLANE_T* airPlane;
	airPlane = generateFlight();
	generatePosition(&x,&y,&z);
	airPlane->position.x = x;
	airPlane->position.y = y;
	airPlane->position.z = z;
	if (x == 0)
		{
		if (y < 20)
			airPlane->heading = SE;
		else if (y > 70)
			airPlane->heading = NE;
		else
			airPlane->heading = E;
		}
	else if (x == 100)
		{
		if (y < 20)
			airPlane->heading = SW;
		else if (y > 70)
			airPlane->heading = NW;
		else
			airPlane->heading = W;
		}
	else if (y == 0)
		{
		if (x < 20)
			airPlane->heading = SE;
		else if (x > 70)
			airPlane->heading = SW;
		else
			airPlane->heading = S;
		}
	else if (y == 100)
		{
		if (x < 20)
			airPlane->heading = NW;
		else if (x > 70)
			airPlane->heading = NE;
		else
			airPlane->heading = N;
		}
	return airPlane;
	}
/* This function will print plane information from structure
 * input PLANE_T structure */
void printPlane(PLANE_T* input)
	{
	printf("Flight: %s\n", input->flight);
	printf("Position: x %d y %d z %d\n", input->position.x, input->position.y, input->position.z);
	printf("Direction: %d\n", input->heading);
	switch (input->heading)
		{
		case N:
			printf("Heading: N\n");
			break;
		case NE:
			printf("Heading: NE\n");
			break;
		case E:
			printf("Heading: E\n");
			break;
		case SE:
			printf("Heading: SE\n");
			break;
		case S:
			printf("Heading: S\n");
			break;
		case SW:
			printf("Heading: SW\n");
			break;
		case W:
			printf("Heading: W\n");
			break;
		case NW:
			printf("Heading: NW\n");
			break;
		/* normally this would not happen */
		default:
			printf("Heading direction error\n");
			exit(0);
		}
	}
// int addGroundPlane()
// 	{

// 	}