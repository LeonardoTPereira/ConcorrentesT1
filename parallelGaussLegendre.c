#include "parallelGaussLegendre.h"

pthread_mutex_t mutex;

void parallelGaussLegendre(){
	pthread_t threads[2];

	int ret[2];
	long int i;

	double pi;

	GaussLegStruct *glstruct;

	/*Allocate structure and initialize variables*/
	glstruct = (GaussLegStruct*)calloc(1, sizeof(GaussLegStruct));

	glstruct->a = 1;
	glstruct->an = 1;
	glstruct->b = 1.0/sqrt( 2 );
	glstruct->t = 0.25;
	glstruct->p = 1;

	/*Creates the threads to calculate each part of the algorithm at each iteration, until the algorithm is over*/
	for(i = 0; i < MAXIT; i++)
	{
		pthread_mutex_lock (&mutex);
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

		/*Wait for both threads to finish*/
		pthread_join(threads[0], NULL);
		pthread_join(threads[1], NULL);
	}
	/*Calculates PI using Gauss-Legendre formula*/
	pi = pow( (glstruct->a + glstruct->b), 2.0 )/(4.0*glstruct->t);
    
    printf( "PI: %.6lf\n", pi );

    free(glstruct);

    pthread_exit(NULL);

	exit(EXIT_SUCCESS);	

}

void *calcAB(void *ptr)
{
	/*Locks the structure to calculete A and B values*/
	
	GaussLegStruct *glstr = (GaussLegStruct*)ptr;
	glstr->an = glstr->a;
	glstr->a = (glstr->an+glstr->b)/2.0;
	glstr->b = sqrt( (glstr->an)*(glstr->b) );

	/*Unlocks the structure*/
	pthread_mutex_unlock (&mutex);
	
	return NULL;
}

void *calcTP(void *ptr)
{
	/*Locks the structure to calculate T and P values*/
	pthread_mutex_lock (&mutex);

	GaussLegStruct *glstr = (GaussLegStruct*)ptr;
    glstr->t = (glstr->t) - (glstr->p)*pow( ((glstr->an) - (glstr->a)), 2.0 );
    glstr->p = 2*(glstr->p);
    /*Unlocks the structure*/
	pthread_mutex_unlock (&mutex);

    return NULL;
}
