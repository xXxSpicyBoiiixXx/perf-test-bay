#include <stdlib.h>
#include <stdio.h>
#include <math.h> 
#include <string.h>

#define SEED 35791246

main(int argc, char* argv) 
{
	int n = 0,
	    count = 0,
	    i;

	double x,
	       y,
	       z, 
	       pi; 

	printf("Enter the number of iteration used to estimate pi: "); 

	scanf("%d", &n); 

	srand(SEED); 

	count = 0; 
	
	for(i = 0; i < n; i++) {
		x = (double)rand()/RAND_MAX;
		y = (double)rand()/RAND_MAX;
		z = x*x + y*y;
		
		if(z <= 1)
			count++; 
	}

	pi = (double)count/n*4; 
	
	printf("	
