#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"validate.h"

#define MAXSIZE 128

void setup(int* genSpeed,int* maxPlane)
	{
	char input[32];
	*genSpeed = 10;
	*maxPlane = 10;
	printf("Welcome\n");
	printf("1. Generate speed (default 10 percents)\n");
	printf("2. Maximum plane (default 10 planes)\n");
	printf("Do you want to change?\n");
	while(1)
		{
		fgets(input,sizeof(input),stdin);
		if (strncasecmp(input,"y",1) == 0)
			{
			printf("1. Gen Speed\n");
			fgets(input,sizeof(input),stdin);
			sscanf(input,"%d",genSpeed);
			printf("2. Max plane\n");
			fgets(input,sizeof(input),stdin);
			sscanf(input,"%d",maxPlane);
			break;
			}
		else if (strncasecmp(input,"n",1) == 0)
			{
			break;
			}
		else
			{
			printf("Error - invalid answer\n");
			}
		}
	}

/* return pointer 
 NULL if not found */
int searchPlane()
	{
	char input[MAXSIZE];
	char target[7];
	int returnVal = 0;
	while(1)
		{
		printf("Enter flight number : ");
		fgets(input,MAXSIZE,stdin);
		if (strlen(input) > 7)
			{
			printf("Error - maximum digit is 6\n");
			}
		sscanf(input,"%s",target);
		if (checkFlightCode(target) == 0)
			{
			printf("Error - flight doesn't exist\n");
			}
		else
			break;
		}
	return returnVal;
	}

int main()
	{
	int maxPlane,genSpeed = 0;
	setup(&genSpeed,&maxPlane);
	printf("gen %d max %d\n", genSpeed, maxPlane);
	searchPlane();
	}