#include "MonteCarlo.h"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <functional>

using namespace std;

int main(){
	MonteCarlo mc(42);	
	const auto x_square { [](double x){ return x * x; } }; 
	const auto result { mc.integrate(x_square, 0.0, 1.0, 1'000) };

	const double exactValue { 1.0/3.0 };
	const double absoluteError { abs(result.estimate - exactValue) };

	cout << fixed << setprecision(10) << endl;
	cout << "Monte Carlo results" << endl;
	cout << "Samples:         " << result.samples << endl;
	cout << "Estimate:        " << result.estimate << endl;
	cout << "Exact value:     " << exactValue << endl;
	cout << "Absolute error:  " << absoluteError << endl;
	cout << "Standard error:  " << result.standardError << endl;
	cout << "Execution        " << result.executionTimeMs << " ms" << endl;

	return 0;
}
