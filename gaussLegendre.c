#include "gaussLegendre.h"

#define ITEMAX 100

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
        a = ( a+b )/2.0;

        b = sqrt( a*b );
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

void calculoValores( double *a1, double *b1 )
{
    double a2, b2;

    a2 = ( *a1+*b1 )/2.0;
    b2 = sqrt( *a1*(*b1) );

    *a1 = a2;
    *b1 = b2;
}
