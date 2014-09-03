#ifndef _RAND_BM_H_
#define _RAND_BM_H_

#include <stdlib.h>
#include <math.h>

struct BoxMullerState
{
        double x1, x2, w, y1, y2;
        int useLast;
        struct drand48_data random;
};

void initBoxMullerState(struct BoxMullerState* state);

int boxMullerRandom(struct BoxMullerState* state);

double boxMullerRandom2(struct BoxMullerState* state);

#endif
