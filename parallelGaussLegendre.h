#ifndef _PARALLELGAUSSLEGENDRE_H_
#define _PARALLELGAUSSLEGENDRE_H_

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <math.h>

#define NTHREADS 2
#define NITER pow(10,3)

typedef struct{
	double a;
	double an;
	double b;
	double t;
	long long int p;
}GaussLegStruct;

void parallelGaussLegendre();

void *calcAB(void *ptr);
void *calcTP(void *ptr);

#endif