#include "montecarlo.h"

void montecarlo()
{
	int niter = pow(10, 9);
  double x,y;
	int i,count=0;
	double z;
	double pi;

	srand(time(NULL));
	count=0;
	for ( i=0; i<niter; i++) {
    	x = (double)rand()/RAND_MAX;
    	y = (double)rand()/RAND_MAX;
    	z = x*x+y*y;
    	if (z<=1) count++;
    }
   	pi=(double)count/niter*4;
   	printf("%f\n", pi);
}