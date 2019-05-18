/*
 * validate.h
 * this program use to check validate of user input
 * Created by Sutinan Tadalimavad (Lion) on 22/04/2019
 * ID 61070503443
 *
*/
#ifndef VALIDATE_H
#define VALIDATE_H

#include"datatype.h"
/* This function use to check input from menu
 * return 1 - if input is correct
 * return 0 - if input is invalid
*/
int checkNumber(int choice);

/* This fucntion use to check flight code if it is correct
 * return 1 - if code is valid
 * return 0 - if code is invalid
*/
int checkFlightCode(char input[]);

/* This function use to check direction from user
 * direction must be N,NE,E,SE,S,SW,W,NW
 * return 1 - if it is valid
 * return 0 - if it is invalid
*/
int checkDirection(int direction);


/* This functionuse to check if user give the correct height
 * height must be between 3000 - 6000
 * return 1 - if input is valid
 * return 0 - if input is invalid
*/
int checkAltitude(int height);


/* This function use to check if user give valid command for
 * "order" command
 * commands could be "landing","circle","takeoff"
 * return 1 - if it is valid
 * return 0 - if it is invalid
*/
int checkOrder(char command[]);


/* This function use to check command from user
 * commands must be "direction","altitude","order"
 * return 1 - if command is correct
 * return 0 - if command is invalid
*/
int checkCommand(char input[]);


/* This function use to check command from user
 * return 1 - if it is "status"
 * return 2 - if it is "command"
 * return 0 - if it is no match
*/
int checkAgru(char input[]);
	
#endif