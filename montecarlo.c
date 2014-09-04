#include "montecarlo.h"

void montecarlo() {
	double x,y;
	int count=0;
	long int i;
	double z;
	double pi;

	srand(time(NULL));
	count=0;
  /*Calculates Pi using the Monte Carlo algorithm*/
	for ( i=0; i<MAXIT; i++) {
    	x = (double)rand()/RAND_MAX;
    	y = (double)rand()/RAND_MAX;
    	z = x*x+y*y;
    	if (z<=1) count++;
    }
   	pi=(double)count/MAXIT*4;
   	printf("%.6f\n", pi);
}
