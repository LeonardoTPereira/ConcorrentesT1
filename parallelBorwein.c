#include "parallelBorwein.h"

void parallelBorwein(){
	pthread_t thread1, thread2, thread3;

	int ret1, ret2, ret3;
	
	borweinStruct *bs = NULL;
	borweinStruct *bs1 = NULL;
	borweinStruct *bs2 = NULL;


	bs = (borweinStruct *)malloc(1*sizeof(borweinStruct));
	bs1 = (borweinStruct *)malloc(1*sizeof(borweinStruct));
	bs2 = (borweinStruct *)malloc(1*sizeof(borweinStruct));
	
	bs->start = 0;
	bs->end = 300000000;
	bs->position = 2;
	

	bs1->start = 300000001;
	bs1->end = 600000000;
	bs1->position = 1;

	bs2->start = 600000001;
	bs2->end = 1000000000;
	bs2->position = 3;

	ret1 = pthread_create(&thread1, NULL, borweinItself, (void*) bs1);

	if(ret1){
		fprintf(stderr,"Error - pthread_create() return code: %d\n",ret1);
		exit(EXIT_FAILURE);
	}

	ret2 = pthread_create(&thread2, NULL, borweinItself, (void*) bs);
	printf("oi\n");

	if(ret2){
		fprintf(stderr,"Error - pthread_create() return code: %d\n",ret2);
		exit(EXIT_FAILURE);
	}

	ret3 = pthread_create(&thread3, NULL, borweinItself, (void*) bs2);
	printf("oi\n");

	if(ret3){
		fprintf(stderr,"Error - pthread_create() return code: %d\n",ret3);
		exit(EXIT_FAILURE);
	}

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);

	printf("oi");
	printf("result = %Lf\n", bs->result+bs1->result+bs2->result);
	//printf("b = %Lf\n", *(long double*)num2);
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

    printf("PI:\t%.20Lf\t%d\n", sum, bs->position);
    //ptr = (void*)sum;
    return NULL;
}