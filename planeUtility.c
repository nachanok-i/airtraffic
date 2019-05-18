/* planeUtility.c was made for gathering each plane
 * in binary tree and printing them out
 * Made by Siradanai Sutin (Cartoon) ID 3437
 * 	Modified 18 MAY 2019
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "flightGenerator.h"

PLANETREE_T * pTree;
PLANE_T * planeArray[10];

/* Free all plane in tree
 * 
 */
void freeTree(PLANENODE_T * pCurrent)
	{
	if(pCurrent->left != NULL)
		printTree(pCurrent->left);
	if(pCurrent->right != NULL)
		printTree(pCurrent->right);
	free(pCurrent);
	}


/* This function use to print planes 10 in 10 columns */
void displayColumnDetail()
	{
	int i = 0;
	printf("\n");
	/* sequence of plane */
	printf("%10s :","SEQUENCE");
	for(i = 0; i < 10; i++)
		{
		printf("%5s%2d|", "PLANE", i+1);
		}
	printf("\n");
	/* plane's flight */
	printf("%10s :","FLIGHT");
	for(i = 0; i < 10; i++)
		{
		printf("%7s|", planeArray[i]->flight);
		}
	printf("\n");
	/* plane's altitude */
	printf("%10s :","ALTITUDE");
	for(i = 0; i < 10; i++)
		{
		printf("%5d%2s|", planeArray[i]->position.z, "ft");
		}
	printf("\n");
	/* plane's coordinate */
	printf("%10s :","X-Y COOR");
	for(i = 0; i < 10; i++)
		{
		printf("%3d,%3d|", planeArray[i]->position.x, planeArray[i]->position.y);
		}
	printf("\n");
	}

/* Traverse a tree (pre order traversal)
 * for find(Plane) and comparing the node
 * Argument
 *    pCurrent     -   current node
 *    flightName   -   a string for comparing
 *    foundFlight  -   for checking found node
 */
void doesExist(PLANENODE_T * pCurrent, char * flightName, PLANENODE_T * foundFlight)
	{
	if(pCurrent->left != NULL)
		{
		if(strcmp(pCurrent->left->data->flight, flightName) == 0)
			foundFlight = pCurrent->left;
		doesExist(pCurrent->left, flightName, foundFlight);
		}
	if(pCurrent->right != NULL)
		{
		if(strcmp(pCurrent->right->data->flight, flightName) == 0)
			foundFlight = pCurrent->right;
		doesExist(pCurrent->right, flightName, foundFlight);
		}
	}

/* Searching plane
 * @param	- flightName : Name of flight user type in
 * return found flight (can be NULL if not found)
 */
PLANENODE_T * searchPlane(char * flightName)
	{
	PLANENODE_T * foundFlight = NULL;
	doesExist(pTree->root, flightName, foundFlight);
	return foundFlight;
	}

int count = 0;
/* Printing all plane in the tree
 * using in-order traversal
 * @param	- pCurrent : refer to a current plane
 */
void printTree(PLANENODE_T * pCurrent)
	{
	if(pCurrent->left != NULL)
		printTree(pCurrent->left);
	planeArray[count] = pCurrent->data;
	count++;
	if(pCurrent->right != NULL)
		printTree(pCurrent->right);
	}

/* use to call printTree function from outside */
void callPrintTree()
	{
	printTree(pTree->root);
	}

/* insert each plane in the tree
 * @param	- pCurrent	 : refer to a current plane
 *			- pAPlane 	 : a plane that wanted to insert
 *			- sortStatus : status of inserting(fail for find duplicated plane) 
 */
void insertChild(PLANENODE_T * pCurrent, PLANENODE_T * pNode, int * sortStatus)
	{
	if(strcmp(pCurrent->data->flight,pNode->data->flight) > 0)
		{
		if(pCurrent->left == NULL)
			{
			pCurrent->left = pNode;
			}
		else
			insertChild(pCurrent->left, pNode, sortStatus);
		}
	else if(strcmp(pCurrent->data->flight,pNode->data->flight) < 0)
		{
		if(pCurrent->right == NULL)
			{
			pCurrent->right = pNode;
			}
		else
			insertChild(pCurrent->right, pNode, sortStatus);
		}
	if(strcmp(pCurrent->data->flight,pNode->data->flight) == 0)
		*sortStatus = 3;
	}

/* Inserting each plane into a tree
 * @param	pAPlane - represent to a plane
 * return 0 : allocation error
 * return 1 : insertion complete
 * return 3 : found duplicate flight
 */
int insertNode(PLANE_T * pAPlane)
	{
	int sortStatus = 1;
	PLANENODE_T * pNode = NULL;
	pNode = (PLANENODE_T*) calloc(1, sizeof(PLANENODE_T));
	if(pNode == NULL)
		return 0;
	pNode->data = pAPlane;
	
	if(pTree == NULL)
		{
		pTree = (PLANETREE_T*) calloc(1, sizeof(PLANETREE_T));
		pTree->root = pNode;
		}
	else
		{
		if(pTree->root == NULL)
			printf("root is NULL\n");
		else
			{
			insertChild(pTree->root, pNode, &sortStatus);
			}
		}
	if(sortStatus == 3)
		{
		return 3;
		}
	return 1;
	}

void resetCount()
	{
	count = 0;
	}
