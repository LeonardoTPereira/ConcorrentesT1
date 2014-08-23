#include "parallelGaussLegendre.h"

pthread_barrier_t tBarrier;

void parallelGaussLegendre(){
	pthread_t thread1, thread2;

	int ret1, ret2;

	double pi;

	GaussLegStruct *glstruct;

	glstruct = (GaussLegStruct*)calloc(1, sizeof(GaussLegStruct));

	pthread_barrier_init(&tBarrier, NULL, 2);

	glstruct->a = 1;
	glstruct->an = 1;
	glstruct->b = 1.0/sqrt( 2 );
	glstruct->t = 0.25;
	glstruct->p = 1;

	for(int i = 0; i < NITER; i++)
	{

		ret1 = pthread_create(&thread1, NULL, calcAB, (void*) glstruct);

		if(ret1){
			fprintf(stderr,"Error - pthread_create() return code: %d\n",ret1);
			exit(EXIT_FAILURE);
		}

		ret2 = pthread_create(&thread2, NULL, calcTP, (void*) glstruct);

		if(ret2){
			fprintf(stderr,"Error - pthread_create() return code: %d\n",ret2);
			exit(EXIT_FAILURE);
		}

		pthread_join(thread1, NULL);
		pthread_join(thread2, NULL);

		pi = pow( (glstruct->a + glstruct->b), 2.0 )/(4.0*glstruct->t);
		printf( "a: %lf\n", glstruct->a );
		printf( "b: %lf\n", glstruct->b );
		printf( "t: %lf\n", glstruct->t );
		printf( "p: %lld\n", glstruct->p );
		printf( "PI: %lf\n\n", pi );
	}
	
	pi = pow( (glstruct->a + glstruct->b), 2.0 )/(4.0*glstruct->t);
    
    printf( "PI: %lf\n", pi );

	exit(EXIT_SUCCESS);
	
	printf("oi");
	

}

void *calcAB(void *ptr)
{
	GaussLegStruct *glstr = (GaussLegStruct*)ptr;

	glstr->an = glstr->a;
	glstr->a = (glstr->a+glstr->b)/2.0;
	glstr->b = sqrt( (glstr->a)*(glstr->b) );

	pthread_barrier_wait(&tBarrier);

	return NULL;
}

void *calcTP(void *ptr)
{
	GaussLegStruct *glstr = (GaussLegStruct*)ptr;

    glstr->t = (glstr->t) - (glstr->p)*pow( ((glstr->an) - (glstr->a)), 2.0 );
    glstr->p = 2*(glstr->p);

    pthread_barrier_wait(&tBarrier);

    return NULL;
}