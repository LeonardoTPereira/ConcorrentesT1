#include "borwein.h"

void borwein(){

    int k;
    long double sum=0;
    /*Calculates Pi using Borwein Formula*/
    for(k=0; k<MAXIT;  k++){
        sum +=  (1.0/pow(16.0, k))*((4.0/((8*k)+1))-(2.0/((8*k)+4))-(1.0/((8*k)+5))-(1.0/((8*k)+6)));
    }

    printf("PI:\t%.6Lf\n", sum);
}
