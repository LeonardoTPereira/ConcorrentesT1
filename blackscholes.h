#ifndef _BLACKSCHOLES_H_
#define _BLACKSCHOLES_H_
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "rand_bm.h"
double stdDev(double trials[], double mean, int M);
void blackScholes(double S, double E, double r, double sigma, double T, int M);
#endif