#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void setup(int* genSpeed,int* maxPlane)
	{
	char input[32];
	&genSpeed = 10;
	&maxPlane = 10;
	printf("Welcome\n");
	printf("1. Generate speed (default 10 %)\n");
	printf("2. Maximum plane (default 10 planes)\n");
	printf("Do you want to change?\n");
	fgets(input,sizeof(input),stdin);
	if (strncasecmp(input,"y",1) == 0)
		{
		printf("1. genSpeed\n");
		fgets(input,sizeof(input),stdin);
		sscanf(input,"%d",&genSpeed);
		printf("2. Max plane\n");
		fgets(input,sizeof(input),stdin);
		sscanf(input,"%d",&maxPlane);
		}
	}