#include "gaussLegendre.h"
#include "borwein.h"
#include "montecarlo.h"
#include "parallelMonteCarlo.h"
#include "parallelBorwein.h"
#include "parallelGaussLegendre.h"
#include "blackscholes.h"
#define method 3

int main(int argc, char *argv[]){
	

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
			parallelGaussLegendre();
			break;
		case 6://Black Scholes
			blackScholes(100.0, 110.0, 10.0, 1.0, 1.0, 100000);
			break;
	}

	return 0;
}
