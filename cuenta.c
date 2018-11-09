#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h> 

#define MAXCHAR 2500000

/* COMPILO CON gcc cuenta.c -o cuenta.x -lm Y ./cuenta.x Pi_2500000.txt cuenta.txt tiempo.txt */

int contador(char* filename, char* cuenta, char* tiempo)
{

	char comb[5];
	comb[0] = '1';
	comb[1] = "12";
	comb[2] = "123";
	comb[3] = "1234";
	comb[4] = "12345";

	clock_t clock(void);
	clock_t start_t, end_t;

	FILE *fp;
	char str[MAXCHAR];
	

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("Could not open file %s",filename);
		return 0;
	}
	while (fgets(str, MAXCHAR, fp) != NULL)
		/*printf("%s", str);*/
		printf("Could open file %s",filename);


	int count[5];
	double time[5];
	int j;
	for( j = 0; j < 5; j++ )
	{

		start_t = clock();

		int counter = 0;
		int i; 
		for( i = 0; str[i] != '\0'; i++)
		{
			if(comb[j] == str[i])
			{
				count[j] = ++counter;
			}
		} 

		end_t = clock();
		double total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
		time[j] = total_t;

		/*printf("Count[%d] = %d\n", j, count[j] );
		printf("Time[%d] = %f\n", j, time[j] );*/

	}

	FILE *c = fopen(cuenta, "w");
	FILE *t = fopen(tiempo, "w");

	for( j = 0; j < 5; j++ )
	{
		
		fprintf(c,"%d\n", count[j]);
		fprintf(t,"%f\n", time[j]);

	}
	
	fclose(c);
	fclose(t); 
	
	return 0;
}

void divideString(char *filename, int n) 
{ 

	FILE *fp;
	char str[MAXCHAR];
	fp = fopen(filename, "r");

	if (fp == NULL)
	{
		printf("Could not open file %s",filename);
	}

	while (fgets(str, MAXCHAR, fp) != NULL)
		/*printf("%s", str);*/
		printf("Could open file %s",filename);

	int str_size = strlen(str); 
	int i; 
	int part_size; 
	  
	/*Check if string can be divided in n equal parts*/ 
	if (str_size % n != 0) 
	{ 
	    printf("Invalid Input: String size"); 
	    printf(" is not divisible by n"); 
	} 
	  
	/*Calculate the size of parts to find the division points*/ 
	part_size = str_size / n; 

	char files[n];

	for (i = 0; i < str_size; i++) 
	{ 
	    if (i % part_size == 0)   
	    	printf("%c", str[i]);
	} 
	
} 

int main(int argc, char *argv[])
{
	char* filename = argv[1];
	char* cuenta = argv[2];
	char* tiempo = argv[3];

	contador(filename, cuenta, tiempo);
	divideString(filename, 10);
	
}


 	
