#include <stdio.h>
#include <math.h>

// random number generator 

/*
 * Generates a random number
 *
 * r0: initial seed 
 * coef: scaling factor 
 * max: value of random number that can be generated is max - 1 
 * offset: offset factor
 */
int rand(int r0, int coef, int max, int offset){
	double r1 = (coef*r0+offset)%max;
	return r1;
}

/*
 * Generates random numbers given a seed, and stores them in an array that is passed as an arguement. 
 *
 * r0: initial seed 
 * coef: scale factor 
 * max: gives the max
 * offset: offeset factor 
 * n: # of random numbers to be generated
 * x[n]: array that stores the random numbers 
 */

void randomNumbers(int r0, int coef, int max, int offset, int n; int x[n]) {
	double r1 = rand(r0, coef, max, offset); 
	int i; 

	for(i=0; i<n; i++){
		x[i] = r1; 
		r1 = rand(r1, coef, max, offset); 
	}	
}

/*
 * Generates random numbers in a given range
 *
 * r: array containt random numbers from 0 to 1
 * x: arrat in which the generated random numbers that will be stored with a range 
 * n: # of random numbers that will be generated 
 * x[n]: array that will store randome numbers: 
 * lower: lower bound for random numbers
 * upper: upper bound for random numebrs 
 */

void randomNumbersRange(int n, double r[n], double x[n], double lower, double upper){ 
	int i;
	double r1; 

	for(i=0; i<n; i++){
		r1 = lower + (upper - lower) * r[i];
		x[i] = r1;
	}
}

main(){
	int min = -1,
	    max = 1,
	    n = 10000,
	    coef = 1093,
	    max = 86436, 
	    offset = 18257;

	int i, j, k, l;

	double x0 = 43; 
	double y0 = 21;

	int xtemp[n];
	int ytemp[n];

	randomNumbers(x0, coef, max, offset, n, xtemp);
	randomNumbers(y0, coef, max, offset, n, ytemp); 

	double xtemp1[n]; 
	double ytemp1[n];

	for(i=0; i<n; i++){
		xtemp1[i] = (double)xtemp[i]/(m-1); 
		ytemp1[i] = (double)ytemp[i]/(m-1);
	}

	double x[n]; 
	double y[n]; 

	randomNumbersRange(n, xtemp1, x, -1, 1);
	randomNumbersRange(n, ytemp1, y, -1, 1); 

	int Naccept = 0; 

	for(i = 0; i < n; i++){
		double s = pow(x[i], 2) + pow(y[i], 2);
		if(s <= 1.0){
			Naccept++;
		}
	}

	double area; 

	area = 4*(double)Naccept/n;

	printf("Value of Pi: %lf", area); 
}



