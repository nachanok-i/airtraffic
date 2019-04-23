#ifndef FUTURECOLLISION_H
#define FUTURECOLLISION_H
#include"datatype.h"
void setPosition(PLANE_T* data);
void setRadius(POSITION_T data);
int checkCollision();
void movePlane(PLANE_T* plane);
int getCommand();
void cleanTable();
void printTable();
#endif