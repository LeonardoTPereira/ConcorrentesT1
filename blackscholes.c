#include "blackscholes.h"
/*Calculates the standard deviation from the results given by the Black Scholes trials*/
double stdDev(double trials[], double mean, int M)
{
	double stddev = 0.0;
	int i;
	for(i = 0; i < M; i++)
	{
		stddev += pow((trials[i] - mean),2);
	}
	stddev = sqrt(stddev/((double)M-1));
	return stddev;
}

void blackScholes(double S, double E, double r, double sigma, double T, int M)
{
	int i;
	double t, mean = 0.0, stddev, confwidth, confmin, confmax;
	double trials[M];

	struct BoxMullerState state;
	initBoxMullerState(&state);
	
	/*Calculates the trials from Black Scholes*/
	for(i = 0; i < M; i++)
	{
		t = S*exp((r-((1.0/2.0)*pow(sigma, 2.0)))*T + sigma*sqrt(T)*boxMullerRandom2(&state));

		if((t-E) > 0.0)
			trials[i] = exp((-r)*T)*(t-E);
		else
			trials[i] = 0.0;
		mean += trials[i];
	}
	/*Calculates mean, standard deviation and the confidence of Black Scholes trials*/
	mean = mean/(double)M;
	stddev = stdDev(trials, mean, M);
	confwidth = 1.96*stddev/sqrt(M);
	confmin = mean - confwidth;
	confmax = mean + confwidth;
	printf("S \t%lf\n", S);
	printf("E \t%lf\n", E);
	printf("r \t%lf\n", r);
	printf("sigma \t%lf\n", sigma);
	printf("T \t%lf\n", T);
	printf("M \t%d\n", M);
	printf("Confidence interval: (%lf, %lf)\n", confmin, confmax);
}