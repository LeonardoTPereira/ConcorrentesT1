#include "parallelMonteCarlo.h"

void parallelMonteCarlo(){


	pthread_t thread[NTHREADS];

	double result = 0.0;

	int ret[NTHREADS], i;

	monteCarloStruct *mCS[NTHREADS];

	/*Allocates structures to be passed on threads and sets their size of iteractions*/
	for(i = 0; i < NTHREADS; i++)
	{	
		mCS[i] = (monteCarloStruct *)calloc(1, sizeof(monteCarloStruct));
		mCS[i]->size = (MAXIT/NTHREADS);
		ret[i] = pthread_create(&thread[i], NULL, itself, (void*) mCS[i]);

		if(ret[i]){
			fprintf(stderr,"Error - pthread_create() return code: %d\n",ret[i]);
			exit(EXIT_FAILURE);
		}
	}

	/*Wait for all threads to finish*/
	for(i = 0; i < NTHREADS; i++)
	{
		pthread_join(thread[i], NULL);
	}

	/*Sums the results and free the structures*/
	for(i = 0; i < NTHREADS; i++)
	{
		result+=mCS[i]->result;
		free(mCS[i]);
	}
	
	/*Gives the result by the mean of the sum of the result of each thread*/
	result = result/NTHREADS;
	printf("PI: %.6f\n", result);
	pthread_exit(NULL);
	exit(EXIT_SUCCESS);

}

void *itself(void *ptr){
	monteCarloStruct *mCS = (monteCarloStruct*) ptr;

	int i,count=0;

	struct BoxMullerState state;

	initBoxMullerState(&state);
	/*Calculates PI using the Monte Carlo method*/
	count=0;
	for ( i=0; i<mCS->size; i++) {
    	if(!boxMullerRandom(&state))
    		count++;
    }
   	
   	mCS->result = (count/(double)mCS->size)*4;

   	return NULL;
}