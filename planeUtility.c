/* planeUtility.c was made for gathering each plane
 * in binary tree and printing them out
 * Made by Siradanai Sutin (Cartoon) ID 3437
 * Modified by Nachanok Issarapruk (Tap) ID 61070503410
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "flightGenerator.h"
#include "futureCollision.h"

int maxPlane2 = 10;
PLANENODE_T * pTree = NULL;
PLANE_T ** planeArray;

void setMaxPlane(int inputMaxPlane)
	{
	maxPlane2 = inputMaxPlane;
	}

void callocPlaneArray(int maxPlane2)
	{
	planeArray = (PLANE_T**) calloc(maxPlane2, sizeof(PLANE_T*));
	if(planeArray == NULL)
		{
		printf("\t Allocation error\n");
		exit(0);
		}
	printf(">>> Maximum amout is %d\n", maxPlane2);
	}

/* This function will print plane information from structure
 * input PLANE_T structure */
void printPlane(PLANE_T* input)
	{
	printf("Flight: %s\n", input->flight);
	printf("Position: x %d y %d z %d\n", input->position.x, input->position.y, input->position.z);
	switch (input->heading)
		{
		case N:
			printf("Heading: N\n");
			break;
		case NE:
			printf("Heading: NE\n");
			break;
		case E:
			printf("Heading: E\n");
			break;
		case SE:
			printf("Heading: SE\n");
			break;
		case S:
			printf("Heading: S\n");
			break;
		case SW:
			printf("Heading: SW\n");
			break;
		case W:
			printf("Heading: W\n");
			break;
		case NW:
			printf("Heading: NW\n");
			break;
		/* normally this would not happen */
		default:
			printf("Heading direction error\n");
			exit(0);
		}
	}

/* Updating active plane
 * @param	-	PLANENODE_T * pCurrent
 */
void traverseUpdatePlane(PLANENODE_T * pCurrent)
	{
	if(pCurrent->left != NULL)
		traverseUpdatePlane(pCurrent->left);
	movePlane(pCurrent->data);
	if(pCurrent->right != NULL)
		traverseUpdatePlane(pCurrent->right);
	}

/* Updating active plane
 * return 1 for success, 0 there is no plane
 */
int updatePlane()
	{
	if(pTree != NULL)
		{
		traverseUpdatePlane(pTree);
		return 1;
		}
	else
		{
		printf("The sky is clear (there is no plane)\n");
		return 0;
		}
	}

/* This function use to print planes in columns */
void displayColumnDetail()
	{
	int i = 0;
	printf("\n");
	/* sequence of plane */
	printf("%10s :","SEQUENCE");
	for(i = 0; i < maxPlane2; i++)
		{
		printf("%5s%2d|", "PLANE", i+1);
		}
	printf("\n");
	/* plane's flight */
	printf("%10s :","FLIGHT");
	for(i = 0; i < maxPlane2; i++)
		{
		printf("%7s|", planeArray[i]->flight);
		}
	printf("\n");
	/* plane's altitude */
	printf("%10s :","ALTITUDE");
	for(i = 0; i < maxPlane2; i++)
		{
		printf("%5d%2s|", planeArray[i]->position.z, "ft");
		}
	printf("\n");
	/* plane's coordinate */
	printf("%10s :","X-Y COOR");
	for(i = 0; i < maxPlane2; i++)
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
	if (pTree == NULL)
		return NULL;
	if(strcmp(pTree->data->flight, flightName) == 0)
		{	
		foundFlight = pTree;
		return foundFlight;
		}
	else
		{
		doesExist(pTree, flightName, foundFlight);
		return foundFlight;
		}
	}

int count = 0;
/* Printing all plane in the tree
 * using in-order traversal
 * @param	- pCurrent : refer to a current plane
 */
void gatherPlaneInTree(PLANENODE_T * pCurrent)
	{
	if(pCurrent->left != NULL)
		gatherPlaneInTree(pCurrent->left);
	planeArray[count] = pCurrent->data;
	count++;
	if(pCurrent->right != NULL)
		gatherPlaneInTree(pCurrent->right);
	}

/*set counting to zero */
void resetCount()
	{
	count = 0;
	}

/* Removing plane
 * @param	-	pNode : the node wanted to remove
 */
void removePlane(PLANENODE_T * pNode)
	{
	PLANENODE_T * pRemove = NULL; /* removing node */
	PLANENODE_T * pSucc = NULL; /* Successor for deleting node which has 2 child */
	int i = 0;
	if((pNode->left == NULL) && (pNode->right == NULL))
		{
		free(pNode->data);
		free(pNode);
		}
	else if((pNode->left == NULL) && (pNode->right != NULL))
		{
		pRemove = pNode;
		pNode = pNode->right;
		free(pRemove->data);
		free(pRemove);
		}
	else if((pNode->left != NULL) && (pNode->right == NULL))
		{
		pRemove = pNode;
		pNode = pNode->left;
		free(pRemove->data);
		free(pRemove);
		}
	else
		{
		pRemove = pNode;
		pSucc = pNode->right;
		while(pSucc->left != NULL)
			{
			pSucc = pSucc->left;
			}
		pNode = pSucc;
		pSucc = NULL;
		free(pRemove->data);
		free(pRemove);
		}
	}

/* delete plane
 * @param	- flightName : Name of flight from other function
 */
void deletePlane(char * flightName)
	{
	PLANENODE_T * pDelete = NULL;
	pDelete = searchPlane(flightName);
	if(pDelete != NULL)
		removePlane(pDelete);
	else
		printf("/tPlane is not found!\n", );
	}


/* To call printTree function from outside */
void callPrintTree()
	{
	gatherPlaneInTree(pTree);
	displayColumnDetail();
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
		pTree = (PLANENODE_T*) calloc(1, sizeof(PLANENODE_T));
		pTree = pNode;
		}
	else
		{
		if(pTree == NULL)
			printf("root is NULL\n");
		else
			{
			insertChild(pTree, pNode, &sortStatus);
			}
		}
	if(sortStatus == 3)
		{
		return 3;
		}
	return 1;
	}

/* Free all plane in tree
 * 
 */
void freeTree(PLANENODE_T * pCurrent)
	{
	if(pCurrent->left != NULL)
		freeTree(pCurrent->left);
	if(pCurrent->right != NULL)
		freeTree(pCurrent->right);
	free(pCurrent->data);
	free(pCurrent);
	}