/* futureCollision.c
 *
 * checking if planes on the sky is about to collide
 * by their position on x,y,z coordinate 
 * Created by Nachanok Issarapruk (Tap) ID 61070503410
 * 26 Mar 2019 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"datatype.h"
#define WHITE 0
#define GRAY  1
#define BLACK 2
#define MAXAREA 50				/* max area of the airport (example as 20)*/
#define SAFEAREA 2				/* safe area around each plane (in coordinate) */
#define MAXHIGH 4				/* max number of altitude level (3000 - 6000) */

char* colorName[] = {"WHITE", "GRAY", "BLACK"};

typedef struct
	{
	struct _plane* plane;		/* PLANE_T strucuture */
	int color;					/* use for traversal */
	} VERTEX_T;

VERTEX_T vertices[MAXAREA];		/* this is our vertex array */
int lastUsed = -1;				/* this keeps track of the last used 
                                 * item in the vertex array, for adding
                                 */

int edges[MAXAREA][MAXAREA][MAXHIGH];
                            	/* track position of the plane */
								/* the location of the plane and safty area
								 * will be 1, blank space will be 0 */
								/* 100 x 100 x 4(3000-6000) */

void setPosition(PLANE_T* data);
void setRadius(POSITION_T data);
int checkCollision();
void movePlane(PLANENODE_T* node);
int getCommand();

/* This function is use to clean the table */
void cleanTable()
{
	int i=0; /* loop varialbe */
	int j=0; /* loop varialbe */
	int k=0; /* loop varialbe */
	for(k=0;k<MAXHIGH;k++)
		{
		for(j=0;j<MAXAREA;j++)
			{
			for(i=0;i<MAXAREA;i++)
				{
				edges[i][j][k] = 0;
				}
			}
		}
}

/* This function is use to display the table */
void printTable()
{
	int i=0; /* loop varialbe */
	int j=0; /* loop varialbe */
	int k=0; /* loop varialbe */
	// for(k=0;k<MAXHIGH;k++)
	// 	{
	// 	printf("Table #%d\n", k);
	printf("---------------------------------\n");
		for(i=0;i<MAXAREA;i++)
			{
			for(j=0;j<MAXAREA;j++)
				{
				if (edges[j][i][k] == 0)
					printf(" ");
				else
					printf("%d", edges[j][i][k]);
				}
			printf("\n");
			}
		printf("\n");
		//}
}

/* This function is use to set position of a plane that use to 
 * insert in the table */ 
void setPosition(PLANE_T* data)
{
	int x = data->position.x; /* x coordinate of the plane position variable */
	int y = data->position.y; /* y coordinate of the plane position variable */
	int z = data->position.z; /* z coordinate of the plane position variable */
	printf("%s position: %d %d %d\n",data->flight,x,y,z );
	edges[x][y][z] = data->ID;
	setRadius(data->position);
}

/* This function is use to setting the safety area for a plane */
void setRadius(POSITION_T data)
{
	int i=0;    /* loop varialbe */
	int j=0;    /* loop varialbe */
	int startX; /* start point at x axis */
	int startY; /* start point at y axis */
	int endX;   /* end point at x axis */
	int endY;   /* end point at y axis */
	startX = data.x - SAFEAREA;
	printf("startX %d\n",startX);
	startY = data.y - SAFEAREA;
	printf("startY %d\n",startY);
	endX = data.x + SAFEAREA;
	endY = data.y + SAFEAREA;
	if (startX <= 0)
		startX = 1;
	printf("startX %d\n",startX);
	if (startY <= 0)
		startY = 1;
	if (endX > MAXAREA)
		endX = MAXAREA;
	if (endY > MAXAREA)
		endX = MAXAREA;
	for (i=startX;i<=endX;i++)
		{
		for (j=startY;j<=endY;j++)
			{
			if (i == data.x && j == data.y)
				continue;
			else
				{
				edges[i][j][data.z] += 1;
				}
			}
		}
}

/* this function will move all the plane in continuously to the direction
 * that the plane is heading to */
void movePlane(PLANENODE_T* node)
{
	PLANE_T * airPlane = NULL;
	airPlane = node->data;
	switch (airPlane->heading)
		{
		case N:
			airPlane->position.y -= 1;
			break;
		case NE:
			airPlane->position.y -= 1;
			airPlane->position.x += 1;
			break;
		case E:
			airPlane->position.x += 1;
			break;
		case SE:
			airPlane->position.x += 1;
			airPlane->position.y += 1;
			break;
		case S:
			airPlane->position.y += 1;
			break;
		case SW:
			airPlane->position.x -= 1;
			airPlane->position.y += 1;
			break;
		case W:
			airPlane->position.x -= 1;
			break;
		case NW:
			airPlane->position.x -= 1;
			airPlane->position.y -= 1;
			break;
		/* normally this would not happen */
		default:
			printf("Heading direction error\n");
			exit(0);
		}
}

/* this function is use to check collision */
int checkCollision()
{
	int bColli = 0; /* return value */ 
	int i=0; /* loop variable */
	int j=0; /* loop variable */
	int k=0; /* loop variable */
	for(k=0;k<MAXHIGH;k++)
		{
		for(j=0;j<MAXAREA;j++)
			{
			for(i=0;i<MAXAREA;i++)
				{
				if (edges[i][j][k] == 2)
					{
					printf("Collide!!!\n");
					bColli = 0;
					return bColli;
					}
				}
			}
		}
	bColli = 1;
	return bColli;
}