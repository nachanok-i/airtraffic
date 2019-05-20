#ifndef FUTURECOLLISION_H
#define FUTURECOLLISION_H
#include"datatype.h"
void setPosition(PLANE_T* data);
void setRadius(POSITION_T data);
int checkCollision();
void movePlane(PLANENODE_T* node);
int getCommand();
void cleanTable();
void printTable();
#endif