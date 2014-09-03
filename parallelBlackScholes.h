#ifndef _PARALLELBLACKSCHOLES_H_
#define _PARALLELBLACKSCHOLES_H_
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "rand_bm.h"
double stdDev(long double trials[], long double mean, int M);
void parallelBlackScholes(double S, double E, double r, double sigma, double T, int M);
#endif