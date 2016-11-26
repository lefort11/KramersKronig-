#ifndef INTEGRAL_INTEGRALCALCULATION_H
#define INTEGRAL_INTEGRALCALCULATION_H

#include <cmath>

//#include <omp.h>

#define h 0.00005

#define delta 0.000000001


#define INFINITE 100


/*double CalculateIntegral(double a, double b, std::function<double (double x)> f)
{
	int n = static_cast<int>((b - a) / h);

	double* x = new double[n];

	for(int i = 0; i < n; ++i)
	{
		x[i] = a + h * i;
	}


	double value = 0;
	for(int i = 0; i < n - 1; ++i)
	{
		value += (f(x[i]) + f(x[i+1])) * (x[i+1] - x[i]);
	}

	delete[] x;

	return 0.5 * value;
} */

double CalculateIntegral(double a, double b, std::function<double (double x)> f)
{
	int n = static_cast<int>((b - a) / h);

	double* x = new double[n];

//#pragma omp parallel for
	for(int i = 0; i < n; ++i)
	{
		x[i] = a + h * i;
	}


	double value = 0;

//#pragma omp parallel for
	for(int i = 0; i < n - 1; ++i)
	{
		value += (x[i+1] - x[i]) * (f(x[i]) + 4 * f((x[i] + x[i+1]) / 2) + f(x[i+1]));
	}

	delete[] x;

	return value / 6.0;
}

double CalculateRefractionCoefficient(double lambda, double (*f)(double))
{
/*	double value_minus, value_plus;


	value_minus = CalculateIntegral(-INFINITE, lambda - delta, [f, lambda](double x)
	{
		return 1/M_PI * f(x) / (lambda - x);
	});

	value_plus = CalculateIntegral(lambda + delta, INFINITE, [f, lambda](double x)
	{
		return 1/M_PI * f(x) / (lambda - x);
	});

	return value_minus + value_plus + 1; */

	double value;

	value = CalculateIntegral(delta, +INFINITE, [f, lambda](double x)
	{
		return 1/M_PI * (f(x+lambda)/(-x) + f(-x+lambda)/x);
	});
	return value + 1;
}

#endif //INTEGRAL_INTEGRALCALCULATION_H