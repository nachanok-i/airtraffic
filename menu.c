/*This function is use to display menu and allow user to choose menu they want to do*
 * Created by Sahachok Prachaporn (Lion) ID 61070503436
 * Modified by Sutinan Tadalimavad (Lion) ID 61070503443 on 22/04/2019
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"planeInformation.h"
#include"futureCollision.h"
#include"planeUtility.h"

int main()
	{
	char stringInput[128]; /* input variable */
	int choice=0; /* choices for the user variable */
	int i=0; /* loop variable */
	srand(time(NULL));
	printf("------------------------------------------------------------------------>\n\n");
	printf("\tWelcome to Air Traffic Control System simulation Program\t\t\n\n");
	printf("------------------------------------------------------------------------>\n");
	while(1)
		{
		printf("[MENU]\n");
		printf("\t[1] – Information and status of available runway (Not available)\n");
		printf("\t[2] – Plane information generator (Functional)\n");
		printf("\t[3] – Plane movement simulator (Functional)\n");
		printf("\t[4] – Display information of currenly active planes (Functional)\n");
		printf("\t[5] – Potential future plane collision detector display (Functional)\n");
		printf("\t[6] – Send command to specific plane (Not available)\n");
		printf("\t[7] – Exit the program\n");
		choice = 0;
		printf("\nWhat do you want to do? ");
		fgets(stringInput,sizeof(stringInput),stdin);
		sscanf(stringInput,"%d",&choice);
		
		switch (choice)
			{
			case 1:
				printf("This function is currently unavailable\n");
				break;
			case 2:
				{
				PLANE_T* plane;
				plane = addAirPlane();
				printPlane(plane);
				break;
				}
			case 3:
				{
				PLANE_T* plane;
				int i=0;
				plane = addAirPlane();
				for (i=0;i<5;i++)
					{
					printPlane(plane);
					movePlane(plane);
					}
				}
				break;
			case 4:
				{
				int i=0;
				int buildStatus = 0;
				srand(time(NULL));
				PLANE_T* pAPlane = NULL;
				for (i=0;i<10;i++)
					{
					pAPlane = generateFlight();
					//printf("|%s| pos: %d,%d,%d\n",pAPlane->flight, pAPlane->position.x, pAPlane->position.y, pAPlane->position.z);
					buildStatus = insertNode(pAPlane);
					switch(buildStatus)
						{
					case 0:
						printf("Error to access file\n");
						break;
					case 1:
						//wait for next progressing
						printf("Success add %s\n", pAPlane->flight);
						break;
					case 2:
						printf("dynamic allocate error\n");
						break;
					case 3:
						printf("Found the duplicated flight\n");
						break;	
						}
					}
				resetCount();
				callPrintTree();
				displayColumnDetail();
				}
				break;
			case 5:
				{
				int i=0;
				PLANE_T plane;
				PLANE_T plane2;
				cleanTable();
				plane.ID = 9;
				strcpy(plane.flight,"AA1234");
				plane.order = LANDING;
				plane.heading = E;
				plane.position.x = 0;
				plane.position.y = 10;
				plane.position.z = 0;
				plane2.ID = 9;
				strcpy(plane2.flight,"AA2345");
				plane2.order = LANDING;
				plane2.heading = W;
				plane2.position.x = 10;
				plane2.position.y = 10;
				plane2.position.z = 0;
				for (i=0;i<5;i++)
					{
					setPosition(&plane);
					setPosition(&plane2);
					printTable();
					if (checkCollision() == 0)
						break;
					movePlane(&plane);
					movePlane(&plane2);
					cleanTable();
					}
				break;
				}
			case 6:
				printf("This function is currently unavailable\n");
				break;
			case 7:
				return 0;
			default:
				printf("\n\tInvalid - The program doesn't have this menu\n");
				break;
			}
		}	
	}
