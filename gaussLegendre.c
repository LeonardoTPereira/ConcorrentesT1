#include "gaussLegendre.h"

#define ITEMAX pow(10, 9)

void gl()
{
    int i;
	double a, an, b, t, pi;
    long long int p;

    /*Initial state of Gauss-Legendre algorithm*/
	a = 1;
	b = 1.0/sqrt( 2 );
	t = 0.25;
	p = 1;

    /*Calculates Pi using Gauss-Legendre algorithm*/
	for( i = 0 ; i <= ITEMAX ; i++ )
    {
        an = a;
        a = ( an+b )/2.0;
        b = sqrt( an*b );
        t = t - p*pow( (an - a), 2.0 );
        p = 2*p;
    }
    
    pi = pow( (a + b), 2.0 )/(4.0*t);
    
    printf( "PI: %.6lf\n", pi );
}