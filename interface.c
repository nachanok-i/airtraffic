#include<stdio.h>
#include<stdlib.h>

void displayMatrixPlane()
	{

	}

void displayColumnDetail()
	{
	int i = 0;
	printf("\n");
	for(i = 0; i < 10; i++)
		{
		printf("%5s%2d|", "PLANE", i+1);
		}
	printf("\n");

	for(i = 0; i < 10; i++)
		{
		printf("%8s", "IDEX00|");
		}
	printf("\n");
	
	for(i = 0; i < 10; i++)
		{
		printf("%8s", "AADDDD|");
		}
	printf("\n");

	for(i = 0; i < 10; i++)
		{
		printf("%8s", "X000FT|");
		}
	printf("\n");

	for(i = 0; i < 10; i++)
		{
		printf("%8s", "LANDING|");
		}
	printf("\n");

	for(i = 0; i < 10; i++)
		{
		printf("%8s", "(X,Y)|");
		}
	printf("\n");
	}
int main()
	{
	displayColumnDetail();
	}