#ifndef _PARALLELMONTECARLO_H_
#define _PARALLELMONTECARLO_H_

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <math.h>

void parallelMonteCarlo();

void *itself(void *ptr);

#endif