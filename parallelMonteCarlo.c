#include "parallelMonteCarlo.h"
#include "rand_bm.c"

void parallelMonteCarlo(){
<<<<<<< HEAD
	
=======
	printf("chamou saporran\n");
>>>>>>> 0a6657175cc535f6a43eec3cf0a6253eba08ada9
	pthread_t thread[NTHREADS];

	double result = 0.0;

	int ret[NTHREADS], i;

	monteCarloStruct *mCS[NTHREADS];

	for(i = 0; i < NTHREADS; i++)
	{	
		printf("adicionado %d thread\n", i);
		mCS[i] = (monteCarloStruct *)calloc(1, sizeof(monteCarloStruct));
		mCS[i]->size = (MAXIT/NTHREADS);
		ret[i] = pthread_create(&thread[i], NULL, itself, (void*) mCS[i]);

		if(ret[i]){
			fprintf(stderr,"Error - pthread_create() return code: %d\n",ret[i]);
			exit(EXIT_FAILURE);
		}
	}

	for(i = 0; i < NTHREADS; i++)
	{
		pthread_join(thread[i], NULL);
	}
	printf("saida\n");
	for(i = 0; i < NTHREADS; i++)
	{
		result+=mCS[i]->result;
	}
	result = result/NTHREADS;
	printf("%f\n", result);
	pthread_exit(NULL);
	exit(EXIT_SUCCESS);

}

void *itself(void *ptr){
	monteCarloStruct *mCS = (monteCarloStruct*) ptr;

	int i,count=0;

	struct BoxMullerState state;

	initBoxMullerState(&state);
	
	count=0;
	for ( i=0; i<mCS->size; i++) {
    	if(!boxMullerRandom(&state))
    		count++;
    }
<<<<<<< HEAD

   	mCS->result = (count/(double)mCS->size)*4;
   	//printf("%f\n", mCS->result);
=======
    printf("exit\n");
   	mCS->result = (double)count/(mCS->size)*4;
   	printf("%f\n", mCS->result);
>>>>>>> 0a6657175cc535f6a43eec3cf0a6253eba08ada9
   	return NULL;
}