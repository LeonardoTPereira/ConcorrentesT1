#ifndef _PARALLELBORWEIN_H_
#define _PARALLELBORWEIN_H_

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <math.h>

#define NTHREADS 2
#define MAXIT pow(10, 9)

typedef struct{
	int start;
	int end;
	long double result;
}borweinStruct;

void parallelBorwein();

void *borweinItself(void *ptr);

#endif