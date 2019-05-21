/* futureCollision.c
 *
 * checking if planes on the sky is about to collide
 * by their position on x,y coordinate and altitude.
 * Created by Nachanok Issarapruk (Tap) ID 61070503410
 * 26 Mar 2019 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"datatype.h"
#include"planeUtility.h"
#define WHITE 0
#define GRAY  1
#define BLACK 2
#define MAXAREA 54	/* max area of the airport (example as 20)*/
#define MARGIN 0 	/* display is size */
#define SAFEAREA 2	/* safe area around each plane (in coordinate) */
#define MAXHIGH 4	/* max number of altitude level (3000 - 6000) */

int edges[MAXAREA+(2*MARGIN)][MAXAREA+(2*MARGIN)];
                            	/* track position of the plane */
								/* the location of the plane and safty area
								 * will be 1, blank space will be 0 */
								/* 100 x 100 x 4(3000-6000) */

void setPosition(PLANE_T* data);
void setRadius(POSITION_T data);
int checkCollision();
void movePlane(PLANE_T* airPlane);

/* This function is use to clean the table */
void cleanTable()
{
	int i=0; /* loop varialbe */
	int j=0; /* loop varialbe */
	for(j=0;j<MAXAREA+MARGIN;j++)
		{
		for(i=0;i<MAXAREA+MARGIN;i++)
			{
			edges[i][j] = 0;
			}
		}
}

/* this function is use to check collision 
 * return collision boolean: 
 * 		1 if not collide 
 *		0 if about to collide
 * 		-1 if plane is collide*/
int checkCollision()
{
	printf("in check collide\n");
	int bColli = 1; /* return value */
	int i=0; /* loop variable */
	int j=0; /* loop variable */

	for(j = MARGIN; j < MAXAREA; j++)
			{
			for(i = MARGIN; i < MAXAREA; i++)
				{
				if (edges[i][j] == 10)
					{
					bColli = -1;
					return bColli;
					}
				else if (edges[i][j] == 2)
					{
					bColli = 0;
					}
				}
			}
	return bColli;
}

/* This function is use to display the table 
 * * return collision boolean: 
 * 		1 if not collide 
 *		0 if about to collide
 * 		-1 if plane is collide*/
int printTable()
{
	int count = 0;
	int count2 = 0;
	int i=0; /* x-axis loop varialbe */
	int j=0; /* y-axis loop varialbe */
	for(j = MARGIN; j < MAXAREA; j++)
		{
		for(i = MARGIN; i < MAXAREA; i++)
			{
				// if (edges[i][j] == 0)
				// 	printf("%2d",i);
				// else if (edges[i][j] == 9)
				// 	printf("**");
				// else
				// 	printf("  ");
			printf("%2d", edges[i][j]);
			}
		printf("\n");
		}
	printf("\n");
	return checkCollision();
}

/* This function is use to set position of a plane that use to 
 * insert in the table */ 
void setPosition(PLANE_T* data)
{
	int i,j;
	int x = data->position.x; /* x coordinate of the plane position variable */
	int y = data->position.y; /* y coordinate of the plane position variable */
	printf("%s position: %d %d\n",data->flight,x,y);
	edges[x][y] = 9 /*data->ID*/;
	// for (j=0;j<MAXAREA;j++)
	// 	{
	// 	for (i=0;i<MAXAREA;i++)
	// 		{
	// 		if (edges[i][j][0] == 9)
	// 			printf("9");
	// 		else
	// 			printf("  ");
	// 		}
	// 	printf("\n");
	// 	}
	setRadius(data->position);
}

/* This function is use to setting the safety area for a plane */
void setRadius(POSITION_T data)
{
	int i=0;    /* loop varialbe for x axis */
	int j=0;    /* loop varialbe for y axis*/
	int startX; /* start point at x axis */
	int startY; /* start point at y axis */
	int endX;   /* end point at x axis */
	int endY;   /* end point at y axis */
	printf("setRadius %d %d\n", data.x,data.y);
	if((data.x - SAFEAREA) <= 0)
		{
		startX = data.x;
		printf("startX %d\n",startX);
		endX = data.x + SAFEAREA;
		}
	else if((data.x + SAFEAREA) >= MAXAREA)
		{
		startX = data.x - SAFEAREA;
		printf("startX %d\n",startX);
		endX = data.x;
		}
	else
		{
		startX = data.x - SAFEAREA;
		printf("startX %d\n",startX);
		endX = data.x + SAFEAREA;
		}

	if((data.y - SAFEAREA) <= 0)
		{
		startY = data.y;
		printf("startY %d\n",startY);
		endY = data.y + SAFEAREA;
		}
	else if((data.y + SAFEAREA) >= MAXAREA)
		{
		startY = data.y - SAFEAREA;
		printf("startY %d\n",startY);
		endY = data.y;
		}
	else
		{	
		startY = data.y - SAFEAREA;
		printf("startY %d\n",startY);
		endY = data.y + SAFEAREA;
		}

	
	// if (startX <= 0)
	// 	startX = MARGIN;
	// printf("startX %d\n",startX);
	
	// if (startY <= 0)
	// 	startY = MARGIN;
	// if (endX > MAXAREA)
	// 	endX = MAXAREA;
	// if (endY > MAXAREA)
	// 	endX = MAXAREA;
	
	for(j = startY;j <= endY;j++)
		{
		for(i = startX;i <= endX;i++)
			{
			if(i == data.x && j == data.y)
				continue;
			else
				{
				edges[i][j] += 1;
				}
			}
		}
}

/* this function will move all the plane in continuously to the direction
 * that the plane is heading to */
void movePlane(PLANE_T* airPlane)
{
	// PLANE_T * airPlane = NULL;
	// airPlane = node->data;
	switch (airPlane->heading)
		{
		case N:
			if(airPlane->position.y == 0)
				deletePlane(airPlane->flight);
			else
				airPlane->position.y -= 1;
			break;
		case NE:
			if((airPlane->position.x == (MAXAREA - MARGIN)) || (airPlane->position.y == MARGIN))
				deletePlane(airPlane->flight);
			else
				{
				airPlane->position.y -= 1;
				airPlane->position.x += 1;
				}
			break;
		case E:
			if(airPlane->position.x == (MAXAREA - MARGIN))
				deletePlane(airPlane->flight);
			else
				airPlane->position.x += 1;
			break;
		case SE:
			if((airPlane->position.x == (MAXAREA - MARGIN)) || (airPlane->position.y == (MAXAREA - MARGIN)))
				deletePlane(airPlane->flight);
			else
				{
				airPlane->position.x += 1;
				airPlane->position.y += 1;
				}
			break;
		case S:
			if(airPlane->position.y == (MAXAREA - MARGIN))
				deletePlane(airPlane->flight);
			else
				{
				airPlane->position.y += 1;
				}
			break;
		case SW:
			if((airPlane->position.x == MARGIN) || (airPlane->position.y == (MAXAREA - MARGIN)))
				deletePlane(airPlane->flight);
			else
				{
				airPlane->position.x -= 1;
				airPlane->position.y += 1;
				}
			break;
		case W:
			if(airPlane->position.x == MARGIN)
				deletePlane(airPlane->flight);
			else
				airPlane->position.x -= 1;
			break;
		case NW:
			if((airPlane->position.x == MARGIN) || (airPlane->position.y == MARGIN))
				deletePlane(airPlane->flight);
			else
				{
				airPlane->position.x -= 1;
				airPlane->position.y -= 1;
				}
			break;
		/* normally this would not happen */
		default:
			printf("Heading direction error\n");
			exit(0);
		}
}