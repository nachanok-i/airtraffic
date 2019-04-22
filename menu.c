/*This function is use to display menu and allow user to choose menu they want to do*
 * Created by Sahachok Prachaporn (Lion) ID 61070503436
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"planeInformation.h"
#include"futureCollision.h"

int main()
	{
	char stringInput[128];
	int choice=0;
	int i=0;
	srand(time(NULL));
	printf("------------------------------------------------------------------------>\n\n");
	printf("\tWelcome to Air Traffic Control System simulation Program\t\t\n\n");
	printf("------------------------------------------------------------------------>\n");
	while(1)
		{
		printf("[MENU]\n");
		printf("\t[1] – Information and status of available runway\n");
		printf("\t[2] – Plane information generator\n");
		printf("\t[3] – Plane movement simulator\n");
		printf("\t[4] – Display information of currenly active planes\n");
		printf("\t[5] – Potential future plane collision detector\n");
		printf("\t[6] – Send command to specific plane\n");
		printf("\t[7] – Exit the program\n");
		choice = 0;
		printf("\nWhat do you want to do? ");
		fgets(stringInput,sizeof(stringInput),stdin);
		sscanf(stringInput,"%d",&choice);
		
		switch (choice)
			{
			case 1:
				printf("This section is not currently available\n");
				break;
			case 2:
				{
				PLANE_T* plane;
				plane = addAirPlane();
				printPlane(plane);
				break;
				}
			case 3:
				//
				break;
			case 4:
				//
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
				plane.position.y = 50;
				plane.position.z = 0;
				plane2.ID = 9;
				strcpy(plane2.flight,"AA2345");
				plane2.order = LANDING;
				plane2.heading = W;
				plane2.position.x = 10;
				plane2.position.y = 50;
				plane2.position.z = 0;
				for (i=0;i<5;i++)
					{
					setPosition(&plane);
					setPosition(&plane2);
					printTable();
					checkCollision();
					movePlane(&plane);
					movePlane(&plane2);
					cleanTable();
					}
				}
			case 6:
				printf("This fuction is not currently available\n");
			case 7:
				return 0;
			default:
			printf("\n\tInvalid - The program doesn't have this menu\n");
			}
		}	
	}
