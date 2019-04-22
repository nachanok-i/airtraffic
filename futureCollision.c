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
#define MAXAREA 100				/* max area of the airport */
#define SAFEAREA 3				/* safe area around each plane (in coordinate) */
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
int setPosition();
void setRadius();
int checkCollision();
void movePlane();
int getCommand();
void cleanTable()
{
	int i=0;
	int j=0;
	int k=0;
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
	int i=0;
	int j=0;
	int k=0;
	// for(k=0;k<MAXHIGH;k++)
	// 	{
	// 	printf("Table #%d\n", k);
		for(i=0;i<MAXAREA;i++)
			{
			for(j=0;j<MAXAREA;j++)
				{
				printf("%d", edges[j][i][k]);
				}
			printf("\n");
			}
		printf("\n");
		//}
}
int main()
{
	int i=0;
	PLANE_T plane;
	PLANE_T plane2;
	cleanTable();
	plane.ID = 9;
	strcpy(plane.flight,"AA1234");
	plane.order = LANDING;
	plane.heading = E;
	plane.position.x = 0;
	plane.position.y = 50;
	plane.position.z = 0;
	plane2.ID = 9;
	strcpy(plane2.flight,"AA2345");
	plane2.order = LANDING;
	plane2.heading = W;
	plane2.position.x = 10;
	plane2.position.y = 50;
	plane2.position.z = 0;
	for (i=0;i<5;i++)
		{
		setPosition(&plane);
		setPosition(&plane2);
		printTable();
		checkCollision();
		movePlane(&plane);
		movePlane(&plane2);
		cleanTable();
		}
}
int setPosition(PLANE_T* data)
{
	int x = data->position.x;
	int y = data->position.y;
	int z = data->position.z;
	printf("%d %d %d\n",x,y,z );
	edges[x][y][z] = data->ID;
	setRadius(data->position);
}
void setRadius(POSITION_T data)
{
	int i=0;
	int j=0;
	int startX;
	int startY;
	int endX;
	int endY;
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
void movePlane(PLANE_T* plane)
{
	if (plane->heading == E)
		{
		plane->position.x += 1;
		}
	else if (plane->heading == N)
		{
		plane->position.y += 1;
		}
	else if (plane->heading == W)
		{
		plane->position.x -= 1;
		}
	else if (plane->heading == S)
		{
		plane->position.y -= 1;
		}
}
int checkCollision()
{
	int bColli = 0;
	int i=0;
	int j=0;
	int k=0;
	for(k=0;k<MAXHIGH;k++)
		{
		for(j=0;j<MAXAREA;j++)
			{
			for(i=0;i<MAXAREA;i++)
				{
				if (edges[i][j][k] == 2)
					{
					printf("Collide!!!\n");
					exit(1);
					}
				}
			}
		}
	return 1;
}