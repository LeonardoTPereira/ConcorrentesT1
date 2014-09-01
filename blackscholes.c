#include "blackscholes.h"

void stdDev(mpf_t trials[], mpf_t mean, int M, mpf_t *stddev)
{	
	mpf_set_default_prec(20*1024);

	mpf_t aux1, aux2;
	mpf_set_ui (*stddev, 0);
	mpf_init (*stddev);
	mpf_init (aux1);
	int i;

	for(i = 0; i < M; i++)
	{	
		mpf_sub (aux1, trials[i], mean);
		mpf_pow_ui (aux1, aux1, 2);
		mpf_add (*stddev, *stddev, aux1);
		// stddev += pow((trials[i] - mean),2);
	}
	mpf_set_d (aux2, (M-1.0));
	mpf_div(aux1, *stddev, aux2);
	mpf_sqrt (*stddev, aux1);
	// stddev = sqrt(stddev/(double)(M-1.0));
}


void blackScholes(mpf_t S, mpf_t E, mpf_t r, mpf_t sigma, mpf_t T, int M)
{	
	mpf_set_default_prec(20*1024);

	mpf_t powAux, aux1, aux2, aux3, aux4, aux5;
	long int aux2342;

	int i;
	mpf_t t, mean, stddev, confwidth, confmin, confmax;
	mpf_init (t);
	mpf_init (mean);
	mpf_init (stddev);
	mpf_init (confwidth);
	mpf_init (confmin);
	mpf_init (confmax);
	mpf_init (powAux);
	mpf_init (aux1);
	mpf_init (aux2);
	mpf_init (aux3);
	mpf_init (aux4);
	mpf_init (aux5);
	// long double t, mean = 0, stddev, confwidth, confmin, confmax;
	mpf_t trials[M];
	for(i=0; i<M; i++){
		mpf_init(trials[i]);
	}

	// long double trials[M];
	srand(time(NULL));
	for(i = 0; i < M; i++)
	{	
		//printf("parte1 = %lf\n", (r-((1.0/2.0)*pow(sigma, 2)))*T);
		//printf("parte2 = %lf\n", sigma*sqrt(T)*rand());
		//printf("exp = %Lf\n", (long double)exp((r-((1.0/2.0)*pow(sigma, 2)))*T + sigma*sqrt(T)*rand()));

		

		mpf_pow_ui (powAux, sigma, 2);
		mpf_set_d(aux5, (1.0/2.0));
		mpf_mul (aux1, powAux, aux5);
		mpf_sub (aux2, r, aux1);
		mpf_mul (aux1, aux2, T);
		mpf_sqrt (aux2, T);
		mpf_mul (aux3,aux2, sigma);
		mpf_set_ui(aux4, rand());
		mpf_mul (aux2,aux3, aux4);
		mpf_add (aux3, aux1, aux2);
		mpf_set_d(aux5, e);
		aux2342 = mpf_get_ui(aux3);
		mpf_pow_ui(aux2, aux5, aux2342);
		mpf_mul (aux3, aux2, S);

		//t = S*exp((r-((1.0/2.0)*pow(sigma, 2)))*T + sigma*sqrt(T)*rand());
		// printf("t = %Lf\n", t);
		gmp_printf ("t=%.6Ff\n", aux3);

		mpf_sub (aux4, aux3, E);

		if(aux4 > 0){
			mpf_sub (aux1, aux3, E);
			//testar esse -r

			mpf_mul (aux2, r, T);	
			aux2342 = mpf_get_ui(aux2);
			mpf_set_d (aux3, e);
			mpf_pow_ui (aux2, aux3, -aux2342);
			mpf_mul (trials[i], aux2, aux1);
		}else
			mpf_set_ui(trials[i], 0);
			// trials[i] = 0;
		gmp_printf("trial = %.6Ff\n", trials[i]);

		mpf_add (mean, mean, trials[i]);
		//mean += trials[i];
	}

	gmp_printf("mean = %Ff\n", mean);

	//mean = mean/M;
	mpf_set_ui (aux3, M);
	mpf_div (mean, mean, aux3);


	gmp_printf("mean2 = %Ff\n", mean);

	stdDev(trials, mean, M, &stddev);

	gmp_printf("stddev = %Ff\n", stddev);

	mpf_set_ui (aux3, M);
	mpf_sqrt(aux1, aux3);
	mpf_div (aux1, stddev, aux1);
	mpf_set_d(aux3, 1.96);
	mpf_mul (confwidth, aux3, aux1);

	//confwidth = 1.96*stddev/(double)sqrt(M);

	gmp_printf("confwidth = %Ff\n", confwidth);

	mpf_sub(confmin, mean, confwidth);
	mpf_add(confmax, mean, confwidth);

	/*confmin = mean - confwidth;
	confmax = mean + confwidth;*/

	gmp_printf("S \t%Ff\n", S);
	gmp_printf("E \t%Ff\n", E);
	gmp_printf("r \t%Ff\n", r);
	gmp_printf("sigma \t%Ff\n", sigma);
	gmp_printf("T \t%Ff\n", T);
	printf("M \t%d\n", M);
	gmp_printf("Confidence interval: (%Ff, %Ff)\n", confmin, confmax);
}