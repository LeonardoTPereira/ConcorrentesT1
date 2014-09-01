#include "gaussLegendre.h"
#include "borwein.h"
#include "montecarlo.h"
#include "parallelMonteCarlo.h"
#include "parallelBorwein.h"
#include "parallelGaussLegendre.h"
#include "blackscholes.h"
#define method 6

int main(int argc, char *argv[]){

	mpf_set_default_prec(20*1024);
	mpf_t a, b, c, d, r, f;
	mpf_set_d(a, 100.0);
	mpf_set_d(b, 110.0);
	mpf_set_d(c, 10.0);
	mpf_set_d(d, 1.0);
	mpf_set_d(r, 1.0);
	mpf_set_d(f, 10.0);
	mpf_init (a);
	mpf_init (b);
	mpf_init (c);
	mpf_init (d);
	mpf_init (r);
	mpf_init (f);

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
			blackScholes(a, b, c, d, r, 100000);
			break;
	}

	return 0;
}
