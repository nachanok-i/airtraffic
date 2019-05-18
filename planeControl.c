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
#include"planeInformation.h"
#include"futureCollision.h"
#include"planeUtility.h"
#include"flightGenerator.h"

int main()
	{
	PLANE_T* plane = NULL;
	int genSpeed = 10;
	int maxPlane = 10;
	srand(time(NULL));
	// setup(&genSpeed,maxPlane);
	plane = generateFlight(100);
	printPlane(plane);
	// if (plane != NULL)
	// 	{

	// 	}
	}