#include <iostream>
#include <cstdio>

#include "IntegralCalculation.h"

#define violetWavelength 0.38
#define redWavelength 0.78
#define N 100

int main()
{
	FILE* file = fopen("data.dat", "w");

	double* lambda_grid = new double[N];
	for(int i = 0; i < N; ++i)
	{
		lambda_grid[i] = violetWavelength + i * (redWavelength - violetWavelength) / N;
	}
	for(int i = 0; i < N; ++i)
	{
		fprintf(file, "%f %f\n", lambda_grid[i], CalculateRefractionCoefficient(lambda_grid[i], [](double x)
		{
			return 1.0 * exp(-350 * M_PI * (x - 0.58) * (x - 0.58));
		}));
	}
	fclose(file);
	delete[] lambda_grid;


	return 0;
}