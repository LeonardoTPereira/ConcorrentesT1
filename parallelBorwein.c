#include "parallelBorwein.h"

void parallelBorwein(){
	pthread_t thread[NTHREADS];

	int ret[NTHREADS], i;

	long double result = 0.0;
	
	borweinStruct *bs[NTHREADS];
	
	/*Allocates structures used in threads and create the threads*/
	for( i = 0; i < NTHREADS; i++)
	{
		bs[i] = (borweinStruct *)calloc(1, sizeof(borweinStruct));
		bs[i]->start = (MAXIT/NTHREADS) * i;
		bs[i]->end = (MAXIT/NTHREADS) * (i+1);
		ret[i] = pthread_create(&thread[i], NULL, borweinItself, (void*) bs[i]);

		if(ret[i]){
			fprintf(stderr,"Error - pthread_create() return code: %d\n",ret[i]);
			exit(EXIT_FAILURE);
		}
	}

	/*Wait for all the threads to finish*/
	for( i = 0; i < NTHREADS; i++)
	{
		pthread_join(thread[i], NULL);
	}

	/*Sums the results from each thread and also free the structure of each trade*/
	for( i = 0; i < NTHREADS; i++)
	{
		result += bs[i]->result;
		free(bs[i]);
	}
	
	printf("PI = %.6Lf\n", result);
	
	pthread_exit(NULL);
	
	exit(EXIT_SUCCESS);

}

void* borweinItself(void *ptr){
    
    int k;
    borweinStruct* bs = (borweinStruct*) ptr;
    long double sum;
    sum = 0.0;
    /*Calculates PI using the Borwein algorithm*/
    for(k=bs->start; k<bs->end;  k++){
        sum +=  (1.0/pow(16.0, k))*((4.0/((8*k)+1))-(2.0/((8*k)+4))-(1.0/((8*k)+5))-(1.0/((8*k)+6)));
    }
	bs->result = sum;
    return NULL;
}