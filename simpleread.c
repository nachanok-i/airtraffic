/* This is a simple demo program showing how
 * to read a text file in C.
 *
 *  Created 13 October 2015 by Sally Goldin for CPE100
 */
#include <stdio.h>
#include <stdlib.h> /* for exit fn */
#include <string.h>

int main()
   {
   FILE* pIn = NULL;
   FILE* pOut = NULL;
   char filename[256];
   char inputline[256];
   char response;
   int count;
   char country[3] = {"AA"};
   char first[2] = {'A'};

   pIn = fopen("flightCode.txt","r");
   if (pIn == NULL)
      {
      printf("Error opening file: %s\n", filename);
      exit(1);
      } 
   
   pOut = fopen("flightCode2.txt","w");
	printf("C %c\n",country[0]);
	printf("F %c\n",first[0]);
	count = 0;
   while (fgets(inputline,sizeof(inputline),pIn) != NULL)
      {
      sscanf(inputline,"%s",country);
      printf("Country: %s\n",country);
	if (strncmp(country,first,1))
		{
		//fprintf(pOut,"\t%d",count);
		//count = 0;
		//fprintf(pOut,"\n%c ",country[0]);
		//fprintf(pOut,"},\n {");
		strncpy(first,country,1);
		printf("F %c\n",first[0]);
		}
      fprintf(pOut,"\"%s\", ",country);
	count++;
      
      }
   fclose(pIn);
   if (fclose(pOut) != 0)
        {
        printf("File close failed. Is your disk full?\n");
	exit(2);
	}
   }

