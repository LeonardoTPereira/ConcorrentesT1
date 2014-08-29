#ifndef _BLACKSCHOLES_H_
#define _BLACKSCHOLES_H_

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <gmp.h>

#define e 2.71828

mpf_t stdDev(mpf_t trials[], mpf_t mean, int M);

void blackScholes(mpf_t S, mpf_t E, mpf_t r, mpf_t sigma, mpf_t T, int M);

#endif