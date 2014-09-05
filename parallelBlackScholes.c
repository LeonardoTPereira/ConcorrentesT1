#include "parallelBlackScholes.h"
#include "blackscholes.h"

void parallelBlkScholes(double S, double E, double r, double sigma, double T, int M)
{
	pthread_t thread[NTHREADS];

	double result = 0.0, trials[M], mean, stddev, confwidth, confmin, confmax;

	int ret[NTHREADS], i, j, count;

	blkScholesStruct *blkSS[NTHREADS];

	/*Creates the structures which will be passed to the threads, initialize their variables, and create the threads*/
	for(i = 0; i < NTHREADS; i++)
	{	
		blkSS[i] = (blkScholesStruct *)calloc(1, sizeof(blkScholesStruct));
		
		blkSS[i]->S = S;
		blkSS[i]->E = E;
		blkSS[i]->r = r;
		blkSS[i]->sigma = sigma;
		blkSS[i]->T = T;
		blkSS[i]->size = (M/(double)NTHREADS);
		blkSS[i]->trials = (double*)calloc(blkSS[i]->size, sizeof(double));

		ret[i] = pthread_create(&thread[i], NULL, blkScholesItself, (void*) blkSS[i]);

		if(ret[i]){
			fprintf(stderr,"Error - pthread_create() return code: %d\n",ret[i]);
			exit(EXIT_FAILURE);
		}
	}

	/*Wait for all the threads to finish*/
	for(i = 0; i < NTHREADS; i++)
	{
		pthread_join(thread[i], NULL);
	}

	count = 0;
	
	/*sums up all the results from the threads, and also place all the trials result in a static vector, 
	releasing the memory from the structures*/
	for(i = 0; i < NTHREADS; i++)
	{
		result+=blkSS[i]->sum;
		for(j = 0; j < blkSS[i]->size; j++)
		{
			trials[count++] = blkSS[i]->trials[j];
		}
		free(blkSS[i]->trials);
		free(blkSS[i]);
	}
	
	/*Does the final calculations and gives the result*/
	mean = result/(double)M;
	stddev = stdDev(trials, mean, M);
	confwidth = 1.96*stddev/sqrt(M);
	confmin = mean - confwidth;
	confmax = mean + confwidth;
	printf("S \t%lf\n", S);
	printf("E \t%lf\n", E);
	printf("r \t%lf\n", r);
	printf("sigma \t%lf\n", sigma);
	printf("T \t%lf\n", T);
	printf("M \t%d\n", M);
	printf("Confidence interval: (%lf, %lf)\n", confmin, confmax);
	
	/*end the threads*/
	pthread_exit(NULL);
	exit(EXIT_SUCCESS);
}

void *blkScholesItself(void *ptr){
	/*Cast the received pointer*/
	blkScholesStruct *blkSS = (blkScholesStruct*) ptr;

	int i;
	double t;
	struct BoxMullerState state;

	initBoxMullerState(&state);

	blkSS->sum = 0;

	/*Does the calculations from the Black Scholes method*/
	for(i = 0; i < blkSS->size; i++)
	{
		t = blkSS->S*exp((blkSS->r-((1.0/2.0)*pow(blkSS->sigma, 2.0)))*blkSS->T + blkSS->sigma*sqrt(blkSS->T)*boxMullerRandom2(&state));

		if((t-blkSS->E) > 0.0)
			blkSS->trials[i] = exp((-blkSS->r)*blkSS->T)*(t-blkSS->E);
		else
			blkSS->trials[i] = 0.0;
		blkSS->sum += blkSS->trials[i];
	}
   	return NULL;
}

