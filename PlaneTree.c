/* planeTree.c was made for gathering each plane
 * in binary tree and printing them out
 * Made by Siradanai Sutin (Cartoon) ID 3437
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "flightGenerator.h"

PLANETREE_T * pTree;

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


/* Printing all plane in the tree
 * using in-order traversal
 * @param	- pCurrent : refer to a current plane
 */
void printTree(PLANENODE_T * pCurrent)
	{
	if(pCurrent->left != NULL)
		printTree(pCurrent->left);
	printf("\tFlight Code : '%s'\n", pCurrent->data->flight);
	printf("\tposition %d %d %d\n", pCurrent->data->position.x,pCurrent->data->position.y,pCurrent->data->position.z);
	if(pCurrent->right != NULL)
		printTree(pCurrent->right);
	printf("lol\n");
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
		printf("\tat insert left\n");
		if(pCurrent->left != NULL)
			{
			printf("\tat insert left 2\n");
			insertChild(pCurrent->left, pNode, sortStatus);
			}
		printf("\tat insert left 2.1\n");
		printf("\tnew node is :%s\n", pNode->data->flight);
		if(pCurrent->left == NULL)
			{
			printf("left child is NULL\n");
			pCurrent->left = pNode;
			printf("\tinsert complete\n");
			}
		else
			printf("insert fail\n");
		}
	else if(strcmp(pCurrent->data->flight,pNode->data->flight) < 0)
		{
		printf("\tat insert right\n");
		if(pCurrent->right != NULL)
			{
			printf("\tat insert right 2\n");
			insertChild(pCurrent->right, pNode, sortStatus);
			}
		printf("\tat insert right 2.1\n");
		printf("\tnew node is :%s\n", pNode->data->flight);
		if(pCurrent->right == NULL)
			{
			printf("right child is NULL\n");
			pCurrent->right = pNode;
			printf("\tinsert complete\n");
			}
		else
			printf("insert fail\n");
		}
	else
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
		printf("at Tree root\n");
		pTree = (PLANETREE_T*) calloc(1, sizeof(PLANETREE_T));
		pTree->root = pNode;
		}
	else
		{
		printf("at add node : %s\n", pAPlane->flight);
		if(pTree->root == NULL)
			printf("root is NULL\n");
		else
			{
			// printf("ad here\n");
			printf("\t root id :%s\n", pTree->root->data->flight);
			insertChild(pTree->root, pNode, &sortStatus);
			}
		}
	if(sortStatus == 3)
		{
		return 3;
		}
	return 1;
	}

/* Temporary main function
 * Use for testing running flight number air planes
 * Tree management, etc.
 */
int main()
{
	int i=0;
	int buildStatus = 0;
	srand(time(NULL));
	PLANE_T* pAPlane = NULL;
	for (i=0;i<10;i++)
		{
		pAPlane = generateFlight();
		printf("%d\n", i);
		printf("|%s| pos: %d,%d,%d\n",pAPlane->flight, pAPlane->position.x, pAPlane->position.y, pAPlane->position.z);
		buildStatus = insertNode(pAPlane);
		printf("in\n");
		switch(buildStatus)
			{
		case 0:
			printf("Error to access file\n");
			break;
		case 1:
			//wait for next progressing
			printTree(pTree->root);
			break;
		case 2:
			printf("dynamic allocate error\n");
			break;
		case 3:
			printf("Found the duplicated flight\n");
			break;	
			}
		}
	printf("test\n");
	printTree(pTree->root);
}

// int readFile(char * filename)
// 	{
// 	int i = 0;
// 	int makeTreeStatus = 0;
// 	char input[128];
// 	PLANE_T * pAPlane = NULL;
// 	FILE * pRead = NULL;
	
// 	memset(input, 0, sizeof(input));
// 	printf("%s\n", filename);
// 	pRead = fopen(filename, "r");
// 	if(pRead == NULL)
// 		return 0;
// 	while(fgets(input, sizeof(input), pRead) != NULL)
// 		{
// 		printf("\t%d\n", i+1);
// 		input[strlen(input)-1] = '\0';
// 		pAPlane = (PLANE_T *)calloc(1, sizeof(PLANE_T));
// 		if(pAPlane == NULL)
// 			return 2;
// 		printf("\tat string copy\n");
// 		strcpy(pAPlane->flight, input);
// 		printf("\tat make tree\n");
// 		makeTreeStatus = makeTreePlane(pAPlane);
// 		switch(makeTreeStatus)
// 			{
// 			case 0:
// 				return 0;
// 				break;
// 			case 3:
// 				return 3;
// 				break;
// 			}

// 		printf("%s\n", input);
// 		i++;
// 		}
// 	fclose(pRead);
// 	return 1;
// 	}
// main funtion
// int main(int argc , char * argv[])
// 	{
// 	char filename[32];
// 	char input[128];
// 	int readStatus = 0;
	
// 	if(argc < 2)
// 		{
// 		printf("Not enought Information\n");
// 		return 0;
// 		}
	
	// strcpy(filename,argv[1]);
	//readStatus = readFile(filename);
	// switch(readStatus)
	// 	{
	// 	case 0:
	// 		printf("Error to access file\n");
	// 		break;
	// 	case 1:
	// 		//wait for next progressing
	// 		printTree(pTree->root);
	// 		break;
	// 	case 2:
	// 		printf("dynamic allocate error\n");
	// 		break;
	// 	case 3:
	// 		printf("Found the duplicated flight\n");
	// 		break;
	// 	}	
	//}