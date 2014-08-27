#include "parallelMonteCarlo.h"

void parallelMonteCarlo(){
	pthread_t thread[NTHREADS];

	double result = 0.0;

	int ret[NTHREADS], i;

	monteCarloStruct *mCS[NTHREADS];

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

	for(i = 0; i < NTHREADS; i++)
	{
		pthread_join(thread[i], NULL);
	}

	for(i = 0; i < NTHREADS; i++)
	{
		result+=mCS[i]->result;
	}

	exit(EXIT_SUCCESS);
	printf("oi");

}

void *itself(void *ptr){
	monteCarloStruct *mCS = (monteCarloStruct*) ptr;
	printf("size %d\n", mCS->size);
   	double x,y;
	int i,count=0;
	double z;

	srand(time(NULL));
	count=0;
	for ( i=0; i<mCS->size; i++) {
    	x = (double)rand()/RAND_MAX;
    	y = (double)rand()/RAND_MAX;
    	z = x*x+y*y;
    	if (z<=1) count++;
    }

   	mCS->result = (double)count/(mCS->size)*4;
   	printf("%f\n", mCS->result);
   	return NULL;
}