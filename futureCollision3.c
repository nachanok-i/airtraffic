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
#define MAXAREA 20				/* max area of the airport (example as 20)*/
#define SAFEAREA 3				/* safe area around each plane (in coordinate) */
#define MAXHIGH 4				/* max number of altitude level (3000 - 6000) */

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
void movePlane(PLANE_T* plane);
int getCommand();
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
void printTable()
{
	int i=0; /* loop varialbe */
	int j=0; /* loop varialbe */
	int k=0; /* loop varialbe */
	// for(k=0;k<MAXHIGH;k++)
	// 	{
	// 	printf("Table #%d\n", k);
		for(i=0;i<MAXAREA;i++)
			{
			for(j=0;j<MAXAREA;j++)
				{
				if (edges[j][i][k] == 0)
					printf("*");
				else
					printf("%d", edges[j][i][k]);
				}
			printf("\n");
			}
		printf("\n");
		//}
}

void setPosition(PLANE_T* data)
{
	int x = data->position.x;
	int y = data->position.y;
	int z = data->position.z;
	printf("%s position: %d %d %d\n",data->flight,x,y,z );
	printf("ID : %d\n", data->ID);
	edges[x][y][z] = data->ID;
	printf("1\n");
	setRadius(data->position);
}
void setRadius(POSITION_T data)
{
	int i=0;    /* loop varialbe */
	int j=0;    /* loop varialbe */
	int startX; /* start point at x axis */
	int startY; /* start point at y axis */
	int endX;   /* end point at x axis */
	int endY;   /* end point at y axis */
	startX = data.x - SAFEAREA;
	startY = data.y - SAFEAREA;
	endX = data.x + SAFEAREA;
	endY = data.y + SAFEAREA;
	if (startX < 0)
		startX = 0;
	if (startY < 0)
		startY = 0;
	if (endX > 100)
		endX = 100;
	if (endY > 100)
		endX = 100;
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
void movePlane(PLANE_T* airPlane)
{
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