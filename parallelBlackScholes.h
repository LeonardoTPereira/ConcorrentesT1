#ifndef _PARALLELBLACKSCHOLES_H_
#define _PARALLELBLACKSCHOLES_H_
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "rand_bm.h"
#include "utils.h"

typedef struct{
	int size;
	double S, E, r, sigma, T;
	double *trials;
	double sum;
}blkScholesStruct;

void parallelBlackScholes(double S, double E, double r, double sigma, double T, int M);


void parallelBlkScholes();

void *blkScholesItself(void *ptr);

#endif