#include "parallelMonteCarlo.h"

void parallelMonteCarlo(){
	pthread_t thread1, thread2;

	int ret1, ret2;

	int num1[2];

	num1[0] = 0;
	num1[1] = 500;
	
	int num2[2];

	num2[0] = 500;
	num2[1] = 1000;

	ret1 = pthread_create(&thread1, NULL, itself, (void*) num1);

	if(ret1){
		fprintf(stderr,"Error - pthread_create() return code: %d\n",ret1);
		exit(EXIT_FAILURE);
	}

	ret2 = pthread_create(&thread2, NULL, itself, (void*) num2);

	if(ret2){
		fprintf(stderr,"Error - pthread_create() return code: %d\n",ret2);
		exit(EXIT_FAILURE);
	}

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	printf("oi");

	exit(EXIT_SUCCESS);
	printf("oi");

}

void *itself(void *ptr){
	//int niter = pow(10, 4);
	const int* start = (const int*) ptr;
	printf("start %d\n", start[0]);
	printf("finish %d\n", start[1]);
   	double x,y;
	int i,count=0;
	double z;
	double pi;

	srand(time(NULL));
	count=0;
	for ( i=start[0]; i<start[1]; i++) {
    	x = (double)rand()/RAND_MAX;
    	y = (double)rand()/RAND_MAX;
    	z = x*x+y*y;
    	if (z<=1) count++;
    }
   	pi=(double)count/(start[1]-start[0])*4;
   	printf("%f\n", pi);
   	return NULL;
}