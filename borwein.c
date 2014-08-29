#include "borwein.h"

#define ITEMAX pow(10, 9)

void borwein(){
    int k;

    long double sum=0;
    for(k=0; k<ITEMAX;  k++){
        sum +=  (1.0/pow(16.0, k))*((4.0/((8*k)+1))-(2.0/((8*k)+4))-(1.0/((8*k)+5))-(1.0/((8*k)+6)));
    }

    printf("PI:\t%Lf\n", sum);
}