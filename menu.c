/* lion */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"flightGenerator.h"
#include"planeInformation.h"
/*This function is use to display menu and allow user to choose menu they want to do*/
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
		printf("\t[1] – Information and status of available runway (not yet)\n");
		printf("\t[2] – Plane information generator (functional)\n");
		printf("\t[3] – Plane movement simulator (Testing)\n");
		printf("\t[4] – Display information of currenly active planes\n");
		printf("\t[5] – Potential future plane collision detector (Testing)\n");
		printf("\t[6] – Send command to specific plane\n");
		printf("\t[7] – Exit the program\n");
		choice = 0;
		printf("\nWhat do you want to do? ");
		fgets(stringInput,sizeof(stringInput),stdin);
		sscanf(stringInput,"%d",&choice);
		
		switch (choice)
			{
			case 1:
				//
				break;
			case 2:
				//
				break;
			case 3:
				//
				break;
			case 4:
				//
				break;
			case 5:
				//
			case 6:
				//
			case 7:
				return 0;
			default:
			printf("\n\tInvalid - The program doesn't have this menu\n");
			}
		}	
	}
