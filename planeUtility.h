#ifndef PLANEUTILITY_H
#define PLANEUTILITY_H

/* This function will print plane information from structure
 * input PLANE_T structure */
void printPlane(PLANE_T* input);

/* This function use to print planes 10 in 10 columns */
void displayColumnDetail();

/* Printing all plane in the tree
 * using in-order traversal
 * @param	- pCurrent : refer to a current plane
 */
void printTree(PLANENODE_T * pCurrent);

/* insert each plane in the tree
 * @param	- pCurrent	 : refer to a current plane
 *			- pAPlane 	 : a plane that wanted to insert
 *			- sortStatus : status of inserting(fail for find duplicated plane) 
 */
void insertChild(PLANENODE_T * pCurrent, PLANENODE_T * pNode, int * sortStatus);

/* Inserting each plane into a tree
 * @param	pAPlane - represent to a plane
 * return 0 : allocation error
 * return 1 : insertion complete
 * return 3 : found duplicate flight
 */
int insertNode(PLANE_T * pAPlane);

/* use to reset count variable to 0 */
void resetCount();

/* use to call printTree function from outside */
void callPrintTree();
#endif