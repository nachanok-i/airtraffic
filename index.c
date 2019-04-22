#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"flightGenerator.h"
#include"planeInformation.h"
void test1()
	{
	char flightCode[7] = {0};
	char* direction = NULL;
	int i;
	int x = 0;
	int y = 0;
	int z = 0;
	int altitude = 0;
	for (i=0;i<10;i++)
		{
		memset(flightCode,0,sizeof(flightCode));
		generateFlight(flightCode);
		printf("%s\n", flightCode);
		generatePosition(&x,&y,&z);
		printf("x %d y %d z %d\n",x,y,z);
		}
	
	}
void test2()
	{
	PLANE_T test;
	test = addAirPlane();
	printPlane(test);
	}
int main()
	{
	char input[32];
	int choice = 0;
	srand(time(NULL));
	while(1)
		{
		printf("enter choice \n");
		fgets(input,sizeof(input),stdin);
		sscanf(input,"%d",&choice);
		if (choice == 1)
			test1();
		else if (choice == 2)
			test2();
		else
			break;	
		}
	
	}