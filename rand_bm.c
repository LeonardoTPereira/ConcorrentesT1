/* Esse gerador de numeros aleatorios gera numeros que seguem uma distribuicao normal com media 0 e desvio padrao 1: N(0,1). */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <sys/time.h>

struct BoxMullerState
{
        double x1, x2, w, y1, y2;
        int useLast;
        struct drand48_data random;
};

void initBoxMullerState(struct BoxMullerState* state)
{
        state->random.__init = 0;
        state->useLast = 0;
        
        struct timeval now;
	gettimeofday(&now, NULL);
	state->random.__x[0] = now.tv_usec;
}

int boxMullerRandom(struct BoxMullerState* state)
{
        drand48_r(&state->random, &state->x1);
        state->x1 = 2.0 * state->x1 - 1.0;
        drand48_r(&state->random, &state->x2);
        state->x2 = 2.0 * state->x2 - 1.0;
        state->w = state->x1 * state->x1 + state->x2 * state->x2;
        if(state->w>1.0)
                return 1;
        else
                return 0;
}