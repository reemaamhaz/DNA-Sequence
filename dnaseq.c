#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	This program finds the threonine triples in a given sequence, and prints their location. 

	Author: Reema Amhaz
*/

/*
	This function parses the input to find threonine triples, and prints ints according
	to the triples located. 
	Parameters: array of chars - the sequence, and array of strings that are threons
	Return value: number of threons found
*/
int find_triples(char dna[], char *threons[])
{
	int found = 0;
	for(int i = 0; i < strlen(dna); i+=3)
	{
		char seq[4] = { };
		strncpy(seq, dna + i, 3);
		if(strcmp(threons[0], seq) == 0 ||  strcmp(threons[1], seq) == 0  || 
			strcmp(threons[2], seq) == 0 || strcmp(threons[3], seq) == 0 )
		{
			found = 1;
			printf("%d\n", i);
		}	
	} 

	if (found == 0)
	{
		printf("%d\n", -2);
	}
	return 0;
}

// This function processes the input string and checks for invalid chars
int main() {

	char dna[10000];

	char * threons[4] = {"ACT", "ACC", "ACA", "ACG"};

	printf("Enter the DNA sequecen: ");
	//read up to 9999 characters
	scanf("%9999s", dna);

	for(int i = 0; i < strlen(dna); i++)
	{
		if(dna[i] != 'A' && dna[i] != 'T' &&  dna[i] != 'C' && dna[i] != 'G')
		{
			printf("%d\n", -1);
			return 0;
		}
	}

	find_triples(dna, threons);
	return 0;
}
