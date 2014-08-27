#include "parallelBorwein.h"

void parallelBorwein(){
	pthread_t thread[NTHREADS];

	int ret[NTHREADS], i;

	long double result = 0.0;
	
	borweinStruct *bs[NTHREADS];
	
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

	for( i = 0; i < NTHREADS; i++)
	{
		pthread_join(thread[i], NULL);
	}
	for( i = 0; i < NTHREADS; i++)
	{
		result += bs[i]->result;
	}
	printf("oi");
	printf("result = %Lf\n", result);
	exit(EXIT_SUCCESS);
	printf("oi");

}

void* borweinItself(void *ptr){
    
    int k;
    borweinStruct* bs = (borweinStruct*) ptr;
    printf("start = %d\n", bs->start);
    printf("end = %d\n", bs->end);
    long double sum;
    sum = 0.0;
    for(k=bs->start; k<bs->end;  k++){
        sum +=  (1.0/pow(16.0, k))*((4.0/((8*k)+1))-(2.0/((8*k)+4))-(1.0/((8*k)+5))-(1.0/((8*k)+6)));
    }
	((borweinStruct*)ptr)->result = sum;
    //bs->result = sum;

    printf("PI:\t%.20Lf\n", sum);
    //ptr = (void*)sum;
    return NULL;
}