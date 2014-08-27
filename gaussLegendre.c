#include "gaussLegendre.h"

#define ITEMAX pow(10, 5)

void gl()
{
    int i;
	double a, an, b, t, pi;
    long long int p;

	a = 1;
	b = 1.0/sqrt( 2 );
	t = 0.25;
	p = 1;

	for( i = 0 ; i <= ITEMAX ; i++ )
    {
        an = a;
        //printf("an = %f  ", an);
        a = ( an+b )/2.0;

        b = sqrt( an*b );
        //calculoValores( &a, &b );
        //printf("a = %f  b = %f  ", a, b);
        t = t - p*pow( (an - a), 2.0 );
        //printf("t = %f  ", t);
        p = 2*p;
        //printf("p = %f\n", p);
        pi = pow( (a + b), 2.0 )/(4.0*t);
        printf( "a: %lf\n", a );
        printf( "b: %lf\n", b );
        printf( "t: %lf\n", t );
        printf( "p: %lld\n", p );
        printf( "PI: %lf\n\n", pi );

    }
    
    pi = pow( (a + b), 2.0 )/(4.0*t);
    
    printf( "PI: %lf\n", pi );
}