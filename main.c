#include "gaussLegendre.h"
#include "borwein.h"
#include "montecarlo.h"
#include "parallelMonteCarlo.h"
#include "parallelBorwein.h"
#include "parallelGaussLegendre.h"
#include "blackscholes.h"
#include "parallelBlackScholes.h"
#include <string.h>
//#define method 6

int main(int argc, char *argv[]){
	
	int method = atoi(argv[1]);

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
		case 7://Parallel Black Scholes
			parallelBlkScholes(100.0, 110.0, 10.0, 1.0, 1.0, 100000);
			break;
	}

	return 0;
}
