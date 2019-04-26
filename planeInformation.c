/* planeInformation.c
 * This file is part of airtraffic control. This file is about controling
 * airplane structure from main file
 * Created by Nachanok Issarapruk (Tap) ID 61070503410
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"datatype.h"
#include"flightGenerator.h"


/* This function will print plane information from structure
 * input PLANE_T structure */
void printPlane(PLANE_T* input)
	{
	printf("Flight: %s\n", input->flight);
	printf("Position: x %d y %d z %d\n", input->position.x, input->position.y, input->position.z);
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