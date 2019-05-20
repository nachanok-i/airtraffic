/* datatype.h
 * datatype structure of airtraffic control program
 * Created by Nachanok Issarapruk (Tap)
 * 		ID 61070503410 26 Mar 2019
 * 
 * Modified Siradanai Sutin (Cartoon)
 *		ID 61070503437 21 April 2019
 * 		Adding PLANENODE_T and PLANETREE_T
 */

/* heading direction have 8 direction

	NW	N 	NE		8	1	2
		^				^
		|				|
	W<-	O ->E   >>  7<-	O ->3
		|				|
	SW	S 	SE 		6	5	4
*/

#ifndef DATATYPE_H
#define DATATYPE_H

enum direction{N,NE,E,SE,S,SW,W,NW};
enum choice{UPDATE,SEARCH,SHOW,COMMAND,HELP};
enum command{LANDING,CIRCLE,TAKEOFF,ALTITUDE,DIRECTION};

typedef struct _position
	{
	int x;				/* x coordinate of the plane */
	int y;				/* y coordinate of the plane */
	}POSITION_T;

typedef struct _plane
	{
	int ID;				/* plane ID for controling (in this program there are possibility that flight code are same) */
	char flight[7];		/* flight code refer to real airline code */
	int order;			/* current order */
	int heading;		/* heading direction (N NE S SE W E) */
	int altitude;
	struct _position position;	/* current position x and y cordinate*/
	}PLANE_T;

typedef struct _planenode
    {
    struct _plane * data;		/* pointer to stucture of plane information*/
    struct _planenode * left;	/* left child of a focused plane */
    struct _planenode * right;	/* right child of a focused plane */
    }PLANENODE_T;

 #endif
