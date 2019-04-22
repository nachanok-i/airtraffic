/* planeControl.c
 *
 * control the plane position (moving) in the air and recieve command
 * from user and send it to control specific plane
 * Created by Nachanok Issarapruk (Tap) ID 61070503410
 * Edited by Sahachok Prachaporn (Lion) ID 61070503436
 * 26 Mar 2019 */
#include<stdio.h>
#include<stdlib.h>

/* this function will move all the plane in continuously to the direction
 * that the plane is heading to */
void movePlane()
	{
	PLANE_T airPlane;
	switch (airPlane.heading)
		{
		case N:
			airPlane.position.y -= 1;
			break;
		case NE:
			airPlane.position.y -= 1;
			airPlane.position.x += 1;
			break;
		case E:
			airPlane.position.x += 1;
			break;
		case SE:
			airPlane.position.x += 1;
			airPlane.position.y += 1;
			break;
		case S:
			airPlane.position.y += 1;
			break;
		case SW:
			airPlane.position.x -= 1;
			airPlane.position.y += 1;
			break;
		case W:
			airPlane.position.x -= 1;
			break;
		case NW:
			airPlane.position.x -= 1;
			airPlane.position.y -= 1;
			break;
		/* normally this would not happen */
		default:
			printf("Heading direction error\n");
			exit(0);
		}
	}