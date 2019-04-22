/* flightGenerator.h
 *
 * Defines the necessary functions for a flightGenerator
 *
 * Created by Nachanok Issarapruk (Tap) ID 61070503410
 * 26 Mar 2019 */
#include"datatype.h"
/* This function will generate flight code in form AA1234 2 alphabets and 4 digits
 * refer to real airline code input flightCode char array of length 7 */
void generateNumber(char flightCode[]);

/* This function will generate position on x,y cordinate
 * return in function argument */
void generatePosition(int* x, int* y,int* z);

/* This function will generate all require data of the plane
 * and return as PLANE_T structure */
PLANE_T* generateFlight();
