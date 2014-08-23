#ifndef _PARALLELGAUSSLEGENDRE_H_
#define _PARALLELGAUSSLEGENDRE_H_

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <math.h>
#define NITER 100

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