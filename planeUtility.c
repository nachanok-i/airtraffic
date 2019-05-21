/* planeUtility.c was made for gathering each plane
 * in binary tree and printing them out
 * Created by Siradanai Sutin (Cartoon) ID 61070503437
 * Modified by Nachanok Issarapruk (Tap) ID 61070503410
 * Modified by Sahachok Prachaporn (Lion) ID 61070503436
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "flightGenerator.h"
#include "futureCollision.h"

int maxPlane2 = 10;    /* maximum amount of plane*/
int currentAmount = 0; /* number of plane */
PLANENODE_T * pTree = NULL;
PLANE_T ** planeArray;

/* this function is use to get plane informtion 
 * from planeControl.c to planeUtility.c */
void setMaxPlane(int inputMaxPlane)
	{
	maxPlane2 = inputMaxPlane;
	}

/* this function is use to check the current amount 
 * of plane in the systmem */
int getCurrentAmount()
	{
	return currentAmount;
	}

/*set currentAmount to zero */
void resetCurrentAmount()
	{
	currentAmount = 0;
	}

/* this function is use to stored the plane information for display */
void makePlaneArray()
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
	printf("Position: x %d y %d\n", input->position.x, input->position.y);
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
			printf("Heading direction error '%d'\n",input->heading);
			exit(0);
		}
	}

/* Traverse a tree (in order traversal) and execute the
 * function 'nodeFunction' on each element
 * Argument
 *    pCurrent     -   current node
 *    nodeFunction -   function to execute on each node
 * Code from lab 6
 */
void traverseInOrder(PLANENODE_T* pCurrent,void (*nodeFunction)(PLANENODE_T* pNode))
{
    if (pCurrent->left != NULL)
       {
       traverseInOrder(pCurrent->left,nodeFunction);
       }
    (*nodeFunction)(pCurrent);
    if (pCurrent->right != NULL)
       {
       traverseInOrder(pCurrent->right,nodeFunction); 
       }
}

/* Updating active plane
 */
void updatePlane()
	{
	if(pTree != NULL)
		printf("\tRoot is %s\n",pTree->data->flight);
	int i = 0;
	if(planeArray == NULL)
		{
		makePlaneArray();
		}
	if(pTree != NULL)
		{
		printf("\tnew update\n");
		clearPlaneArray();
		resetCurrentAmount();
		printf("\t Plane gathered\n");
		traverseInOrder(pTree,&gatherPlaneInTree);
		for(i = 0; i < currentAmount; i++)
			{
			printf("move plane %d\n",i+1);
			movePlane(planeArray[i]);
			}
		}
	}

/* Printing all plane in the tree
 * using in-order traversal
 * @param	- pCurrent : refer to a current plane
 */
void gatherPlaneInTree(PLANENODE_T * pCurrent)
	{
	planeArray[currentAmount] = pCurrent->data;
	currentAmount += 1;
	}

/* This function use to print planes in columns */
void displayColumnDetail()
	{
	printf("\t currentAmount : %d\n", currentAmount);
	int i = 0;
	printf("\n");
	/* sequence of plane */
	printf("%10s :","SEQUENCE");
	for(i = 0; i < currentAmount; i++)
		{
		printf("%5s%2d|", "PLANE", i+1);
		}
	printf("\n");
	/* plane's flight */
	printf("%10s :","FLIGHT");
	for(i = 0; i < currentAmount; i++)
		{
		printf("%7s|", planeArray[i]->flight);
		}
	printf("\n");
	/* plane's altitude */
	printf("%10s :","ALTITUDE");
	for(i = 0; i < currentAmount; i++)
		{
		printf("%5d%2s|", planeArray[i]->altitude, "ft");
		}
	printf("\n");
	/* plane's coordinate */
	printf("%10s :","X-Y COOR");
	for(i = 0; i < currentAmount; i++)
		{
		printf("%3d,%3d|", planeArray[i]->position.x, planeArray[i]->position.y);
		}
	printf("\n");
	}
PLANENODE_T * foundFlight = NULL;


/* Traverse a tree (pre order traversal)
 * for find(Plane) and comparing the node
 * Argument
 *    pCurrent     -   current node
 *    flightName   -   a string for comparing
 *    foundFlight  -   for checking found node
 */
void doesExist(PLANENODE_T * pCurrent, char * flightName)
	{
	if(strcmp(pCurrent->data->flight, flightName) < 0)
		{
		if(pCurrent->right != NULL)
			doesExist(pCurrent->right, flightName);
		}
	else if(strcmp(pCurrent->data->flight, flightName) > 0)
		{
		if(pCurrent->left != NULL)
			doesExist(pCurrent->left, flightName);
		}
	else
		{
		printf("\tFound Node %s \n", pCurrent->data->flight);
		foundFlight = pCurrent;
		}
	}





	// if(pCurrent->left != NULL)
	// 	{
	// 	if(strcmp(pCurrent->left->data->flight, flightName) == 0)
	// 		foundFlight = pCurrent->left;
	// 	doesExist(pCurrent->left, flightName, foundFlight);
	// 	}
	// if(pCurrent->right != NULL)
	// 	{
	// 	if(strcmp(pCurrent->right->data->flight, flightName) == 0)
	// 		foundFlight = pCurrent->right;
	// 	doesExist(pCurrent->right, flightName, foundFlight);
	// 	}
	// }

/* Searching plane
 * @param	- flightName : Name of flight user type in
 * return found flight (can be NULL if not found)
 */
PLANENODE_T * searchPlane(char * flightName)
	{
	// PLANENODE_T * foundFlight = NULL;
	foundFlight = NULL;
	if (pTree == NULL)
		{
		printf("\tRoot is NULL\n");
		return NULL;
		}
	if(strcmp(pTree->data->flight, flightName) == 0)
		{	
		foundFlight = pTree;
		return foundFlight;
		}
	else
		{
		doesExist(pTree, flightName);
		return foundFlight;
		}
	}

/* Removing plane
 * @param	-	pNode : the node wanted to remove
 */
void removeNode(PLANENODE_T ** ppNode, PLANENODE_T * pNode)
	{
	PLANENODE_T * pRemove = NULL; /* removing node */
	PLANENODE_T * pSucc = NULL; /* Successor for deleting node which has 2 child */
	PLANENODE_T * pParentSucc = NULL; /* Parent Successor for deleting node which has 2 child */
	int i = 0;
	printf("\t Remove plane %s\n", pNode->data->flight);
	if((pNode->left == NULL) && (pNode->right == NULL))
		{
		free(pNode->data);
		free(pNode);
		//*ppNode = NULL;
		//pTree = NULL;
		}
	else if((pNode->left != NULL) && (pNode->right == NULL))
		{
		pRemove = *ppNode;
		*ppNode = pNode->left;
		free(pRemove->data);
		free(pRemove);
		}	
	else if((pNode->left == NULL) && (pNode->right != NULL))
		{
		pRemove = *ppNode;
		*ppNode = pNode->right;
		free(pRemove->data);
		free(pRemove);
		}
	else
		{
		printf("at remove root\n");
		pRemove = *ppNode;
		pSucc = pNode->right;
		while(pSucc->left != NULL)
			{
			pParentSucc = pSucc;
			pSucc = pSucc->left;
			}
		if(pNode->right == pSucc)
			{
			pNode->right = pSucc;
			}
		else
			{
			pSucc->right = pNode->right;
			pNode = pSucc;
			}
		if(pParentSucc != NULL)
			pParentSucc->left = NULL;
		pSucc = NULL;
		free(pRemove->data);
		free(pRemove);
		}
	currentAmount -= 1;
	printf("remove finish\n");
	if(pTree != NULL)
		printf("Now %s is root\n",pTree->data->flight);
	}


void printPlaneArray()
	{
	printf("print plane array\n");
	printf("currentAmount %d\n", currentAmount);
	int i=0;
	for (i=0;i<currentAmount;i++)
		{
		printf("#%d %s,",i, planeArray[i]->flight);
		}
	printf("\n");
	}

/*Tap*/
// void removePlane(char remove[])
// 	{
// 	printf("in remove plane\n");
// 	int i=0;
// 	int j=0;
// 	if (currentAmount == 0)
// 		{
// 		planeArray[0] = NULL;
// 		pTree = NULL;
// 		}
// 	else
// 		{
// 		for (i=0;i<currentAmount;i++)
// 			{
// 			printf("i %d\n",i);
// 			if (strcmp(planeArray[i]->flight,remove) == 0)
// 				printf("2\n");
// 				planeArray[i] = NULL;
// 				break;
// 			}
// 		for (j=i;j<currentAmount;j++)
// 			{
// 			if (i+1 < currentAmount)
// 				planeArray[i] = planeArray[i+1];
// 			else
// 				planeArray[i] = NULL;
// 			}
// 		printf("current amount %d\n", currentAmount);
// 		currentAmount = currentAmount - 1;
// 		printPlaneArray();
// 		for (i=0;i<currentAmount;i++)
// 			{
// 			insertNode(planeArray[i]);
// 			}
// 		}
		
// 	}


PLANENODE_T * getParent(PLANENODE_T * pCurrent, PLANENODE_T * pNode)
	{
    if(pCurrent == NULL)
    	return NULL;
    else if (pCurrent->right == pNode || pCurrent->left == pNode)
    	return pCurrent;
    else if (strcmp(pCurrent->data->flight, pNode->data->flight) > 0)
    	getParent(pCurrent->left, pNode);
    else
    	getParent(pCurrent->right, pNode);
    return pCurrent;
	}


void removePlane(PLANENODE_T * pNode)
	{
	printf("\tin remove plane\n");
	PLANENODE_T * pRemove = NULL;
	PLANENODE_T * pParent = NULL;
	PLANENODE_T * pParentSucc = NULL;
	PLANENODE_T * pSucc = NULL;
	if(pNode == NULL)
		{
		printf("\tPlane is not found!!!\n");
		return;
		}
	if(pNode->left == NULL && pNode ->right == NULL)
		{
		printf("\tclear there is no child\n");
		if(pTree == pNode)
			{
			pTree = NULL;
			free(pNode->data);
			free(pNode);
			pNode = NULL;
			return;
			}
		if(pTree->left == pNode)
			{
			pParent = pTree;
			pParent->left = NULL;
			}	
		else if(pTree->right == pNode)
			{
			pParent = pTree;
			pParent->right = NULL;
			}
		else if(pParent == NULL)
			{
			pParent = getParent(pTree, pNode);
			if(pParent->left == pNode)
				pParent->left = NULL;
			if(pParent->right == pNode)
				pParent->right = NULL;
			}
		free(pNode->data);
		free(pNode);
		pNode = NULL;
		}
	else if(pNode->left != NULL && pNode->right == NULL)
		{
		printf("\tHas only left child\n");
		if(pTree == pNode)
			pTree = pTree->left;
		else
			{
			printf("Before get parent\n");
			pParent = getParent(pTree, pNode);
			printf("After get parent\n");
			if(pParent->left == pNode)
				pParent->left = pNode->left;
			if(pParent->right == pNode)
				pParent->right = pNode->left;
			}
		free(pNode->data);
		free(pNode);
		}
	else if(pNode->left == NULL && pNode->right != NULL)
		{
		printf("\tHas only right child\n");
		if(pTree == pNode)
			pTree = pTree->right;
		else
			{	
			printf("Before get parent\n");
			pParent = getParent(pTree, pNode);
			printf("After get parent\n");
			if(pParent->left == pNode)
				pParent->left = pNode->right;
			if(pParent->right == pNode)
				pParent->right = pNode->right;
			}
		free(pNode->data);
		free(pNode);
		}
	else
		{
		printf("\tHas Both\n");
		pSucc = pNode->right;
		while(pSucc->left != NULL)
			{
			pParentSucc = pSucc;
			pSucc = pSucc->left;
			}

		if(pTree == pNode)
			{
			pRemove = pTree;
			pTree = pSucc;
			if(pParentSucc == NULL)
				{
				pTree->left = pRemove->left;
				}
			else
				{
				pTree->left = pRemove->left;
				pTree->right = pRemove->right;
				pParentSucc->left = NULL;
				}
			}
		else
			{
			pRemove = pNode;
			pNode = pSucc;
			if(pParentSucc == NULL)
				{
				pNode->left = pRemove->left;
				}
			else
				{
				pNode->left = pRemove->left;
				pNode->right = pRemove->right;
				pParentSucc->left = NULL;
				}
			}
		free(pRemove->data);
		free(pRemove);
		currentAmount -= 1;
		}
	}

/* delete plane
 * @param	- flightName : Name of flight from other function
 */
void deletePlane(char * flightName)
	{
	printf("in delete\n");
	PLANENODE_T * pDelete = NULL;
	pDelete = searchPlane(flightName);
	if(pDelete != NULL)
		{
		removePlane(pDelete);
		printf("\tdelete plane finish\n");
		// resetCurrentAmount();
		// traverseInOrder(pTree,&gatherPlaneInTree);
		// removePlane(flightName);
		}
	else
		printf("\tPlane is not found!\n");
	}

/* this function use to clear the plane array */
void clearPlaneArray()
	{
	int i = 0;
	printf("\tclear plane array\n");
	for(i = 0; i < maxPlane2 ;i++)
		{
		planeArray[i] = NULL;
		}
	}

/* this function is use to set plane data to matrix */
void setPlaneMatrix()
	{
	printf("inSetPlaneMatrix\n");
	int i=0;
	for (i = 0; i < currentAmount; i++)
		{
		setPosition(planeArray[i]);
		}
	}

/* To call printTree function from outside */
void printDetail()
	{
	if(pTree != NULL)
		{
		clearPlaneArray();
		resetCurrentAmount();
		traverseInOrder(pTree,&gatherPlaneInTree);
		printf("\t Plane gathered\n");
		setPlaneMatrix();
		cleanTable();
		printTable();
		displayColumnDetail();
		}
	else
		{
		printf("The sky is clear (there is no plane)\n");
		}
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
		printf("add root\n");
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
	printf("insert %s complete\n", pAPlane->flight);
	return 1;
	}

/* This function is use to 
 * free all plane in tree 
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