#ifndef _PARALLELMONTECARLO_H_
#define _PARALLELMONTECARLO_H_

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <math.h>

#define NTHREADS 2
#define MAXIT pow(10, 9)

typedef struct{
	int size;
	double result;
}monteCarloStruct;

void parallelMonteCarlo();

void *itself(void *ptr);

#endif