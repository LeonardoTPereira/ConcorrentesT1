#include "parallelGaussLegendre.h"

pthread_mutex_t mutex;

void parallelGaussLegendre(){
	pthread_t threads[NTHREADS];

	int ret[NTHREADS], i;

	double pi;

	GaussLegStruct *glstruct;

	glstruct = (GaussLegStruct*)calloc(1, sizeof(GaussLegStruct));

	glstruct->a = 1;
	glstruct->an = 1;
	glstruct->b = 1.0/sqrt( 2 );
	glstruct->t = 0.25;
	glstruct->p = 1;

	for(i = 0; i < NITER; i++)
	{

		ret[0] = pthread_create(&threads[0], NULL, calcAB, (void*) glstruct);

		if(ret[0]){
			fprintf(stderr,"Error - pthread_create() return code: %d\n",ret[0]);
			exit(EXIT_FAILURE);
		}

		ret[1] = pthread_create(&threads[1], NULL, calcTP, (void*) glstruct);

		if(ret[1]){
			fprintf(stderr,"Error - pthread_create() return code: %d\n",ret[1]);
			exit(EXIT_FAILURE);
		}

		pthread_join(threads[0], NULL);
		pthread_join(threads[1], NULL);

		pi = pow( (glstruct->a + glstruct->b), 2.0 )/(4.0*glstruct->t);

	}
	
	pi = pow( (glstruct->a + glstruct->b), 2.0 )/(4.0*glstruct->t);
    
    printf( "PI: %.6lf\n", pi );

    pthread_exit(NULL);

	exit(EXIT_SUCCESS);	

}

void *calcAB(void *ptr)
{
	pthread_mutex_lock (&mutex);

	GaussLegStruct *glstr = (GaussLegStruct*)ptr;
	glstr->an = glstr->a;
	glstr->a = (glstr->an+glstr->b)/2.0;
	glstr->b = sqrt( (glstr->an)*(glstr->b) );

	pthread_mutex_unlock (&mutex);
	
	return NULL;
}

void *calcTP(void *ptr)
{
	pthread_mutex_lock (&mutex);
	
	GaussLegStruct *glstr = (GaussLegStruct*)ptr;
    glstr->t = (glstr->t) - (glstr->p)*pow( ((glstr->an) - (glstr->a)), 2.0 );
    glstr->p = 2*(glstr->p);

	pthread_mutex_unlock (&mutex);

    return NULL;
}