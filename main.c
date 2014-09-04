#include "gaussLegendre.h"
#include "borwein.h"
#include "montecarlo.h"
#include "parallelMonteCarlo.h"
#include "parallelBorwein.h"
#include "parallelGaussLegendre.h"
#include "blackscholes.h"
#include "parallelBlackScholes.h"
#include <string.h>

int main(int argc, char *argv[]){

	double S, E, r, sigma, T;
	int M;
	int method = atoi(argv[1]);
	
	scanf("%lf", &S);
	scanf("%lf", &E);
	scanf("%lf", &r);
	scanf("%lf", &sigma);
	scanf("%lf", &T);
	scanf("%d", &M);

	switch(method){
		case 0://Gauss-Legendre
			gl();
			break;
		case 1://Borwein
			borwein();
			break;
		case 2://Monte Carlo
			montecarlo();
			break;
		case 3://Parallel Monte Carlo
			parallelMonteCarlo();
			break;
		case 4://Parallel Borwein
			parallelBorwein();
			break;
		case 5://Parallel Gauss-Legendre
			printf("Gauss-Legendre\n");
			parallelGaussLegendre();
			break;
		case 6://Black Scholes
			blackScholes(S, E, r, sigma, T, M);
			break;
		case 7://Parallel Black Scholes
			parallelBlkScholes(S, E, r, sigma, T, M);
			break;
	}

	return 0;
}
