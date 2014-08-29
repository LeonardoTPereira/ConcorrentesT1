#ifndef _PARALLELMONTECARLO_H_
#define _PARALLELMONTECARLO_H_

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "utils.h"

typedef struct{
	int size;
	double result;
}monteCarloStruct;

void parallelMonteCarlo();

void *itself(void *ptr);

#endif