#ifndef FUTURECOLLISION_H
#define FUTURECOLLISION_H
#include"datatype.h"
#include"planeUtility.h"
#define WHITE 0
#define GRAY  1
#define BLACK 2
#define MAXAREA 54	/* max area of the airport (example as 20)*/
#define MARGIN 0	/* start area for generating and displaying plane */
#define SAFEAREA 2	/* safe area around each plane (in coordinate) */
#define MAXHIGH 4	/* max number of altitude level (3000 - 6000) */

void setPosition(PLANE_T* data);
void setRadius(POSITION_T data);
int checkCollision();
void movePlane(PLANE_T* airPlane);
void cleanTable();
int printTable();
#endif