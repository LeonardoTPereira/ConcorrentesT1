#include "blackscholes.h"
double stdDev(long double trials[], long double mean, int M)
{
	/*double stddev = 0;
	int i;

	for(i = 0; i < M; i++)
	{
		stddev += pow((trials[i] - mean),2);
	}
	stddev = sqrt(stddev/(double)(M-1.0));

	return stddev;*/
}


void blackScholes(/*mpf_t S, mpf_t E, mpf_t r, mpf_t sigma, mpf_t T, int M*/)
{	
	/*mpf_set_default_prec(20*1024);

	int i;
	mpf_t t, mean, stddev, confwidth, confmin, confmax
	mpf_init (t);
	mpf_init (mean);
	mpf_init (stddev);
	mpf_init (confwidth);
	mpf_init (confmin);
	mpf_init (confmax);
	// long double t, mean = 0, stddev, confwidth, confmin, confmax;
	mpf_t trials[M];
	for(i=0; i<M; i++){
		mpf_init(trials[i]);
	}

	// long double trials[M];
	srand(time(NULL));
	for(i = 0; i < M; i++)
	{	
		printf("parte1 = %lf\n", (r-((1.0/2.0)*pow(sigma, 2)))*T);
		printf("parte2 = %lf\n", sigma*sqrt(T)*rand());
		printf("exp = %Lf\n", (long double)exp((r-((1.0/2.0)*pow(sigma, 2)))*T + sigma*sqrt(T)*rand()));

		mpf_t powAux, aux1, aux2, aux3, aux4;

		mpf_pow_ui (powAux, sigma, 2);
		mpf_mul (aux1, powAux, (mpf_t) (1.0/2.0));
		mpf_sub (aux2, r, aux1);
		mpf_mul (aux3, aux2, T);
		mpf_sqrt (aux4, T);
		mpf_mul (aux5,aux4, sigma);
		mpf_mul (aux6,aux5, (mpf_t) rand());
		mpf_add (aux7, aux3, aux6);
		mpf_pow_ui(aux8, e, aux7);
		mpf_mul (aux9, aux8, S);

		t = aux9;

		//t = S*exp((r-((1.0/2.0)*pow(sigma, 2)))*T + sigma*sqrt(T)*rand());
		// printf("t = %Lf\n", t);
		gmp_printf ("t=%.6Ff\n", t);

		mpf_sub (aux10, t, E);

		if(aux10 > 0){
			trials[i] = exp((-r)*T)*(t-E);
		}else
			trials[i] = 0;
		printf("trial = %Lf\n", trials[i]);

		mean += trials[i];
	}

	printf("mean = %Lf\n", mean);

	mean = mean/M;


	printf("mean2 = %Lf\n", mean);

	stddev = stdDev(trials, mean, M);

	printf("stddev = %Lf\n", stddev);

	confwidth = 1.96*stddev/(double)sqrt(M);

	printf("confwidth = %Lf\n", confwidth);

	confmin = mean - confwidth;
	confmax = mean + confwidth;

	printf("S \t%lf\n", S);
	printf("E \t%lf\n", E);
	printf("r \t%lf\n", r);
	printf("sigma \t%lf\n", sigma);
	printf("T \t%lf\n", T);
	printf("M \t%d\n", M);
	printf("Confidence interval: (%Lf, %Lf)\n", confmin, confmax);
*/}