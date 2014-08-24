#include "blackscholes.h"
double stdDev(long double trials[], long double mean, int M)
{
	double stddev = 0;
	int i;

	for(i = 0; i < M; i++)
	{
		stddev += pow((trials[i] - mean),2);
	}
	stddev = sqrt(stddev/(double)(M-1.0));

	return stddev;
}


void blackScholes(double S, double E, double r, double sigma, double T, int M)
{
	int i;
	long double t, mean = 0, stddev, confwidth, confmin, confmax;
	long double trials[M];
	srand(time(NULL));
	for(i = 0; i < M; i++)
	{
		printf("parte1 = %lf\n", (r-((1.0/2.0)*pow(sigma, 2)))*T);
		printf("parte2 = %lf\n", sigma*sqrt(T)*rand());
		printf("exp = %Lf\n", (long double)exp((r-((1.0/2.0)*pow(sigma, 2)))*T + sigma*sqrt(T)*rand()));
		t = S*exp((r-((1.0/2.0)*pow(sigma, 2)))*T + sigma*sqrt(T)*rand());
		printf("t = %Lf\n", t);

		if(t-E > 0)
			trials[i] = exp((-r)*T)*(t-E);
		else
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
}