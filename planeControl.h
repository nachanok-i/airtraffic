#ifndef PLANECONTROL_H
#define PLANECONTROL_H

#include<time.h>
#include"futureCollision.h"
#include"planeUtility.h"
#include"flightGenerator.h"
#include"validate.h"

#define MAXSIZE 128
#define STOP 10

int genSpeed = 10;
void setup();
int getCommand();

void runCycle();

/* return pointer 
 NULL if not found */
PLANE_T * searchFlight();

void inputCommand(PLANE_T * plane,int choice);
void helpMenu();
int main();


#endif