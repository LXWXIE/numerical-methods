#include "MonteCarlo.h"

#include <chrono>
#include <cmath>
#include <random>
#include <stdexcept>

using namespace std;

MonteCarlo::MonteCarlo(uint32_t seed) : rng(seed) {}

IntegrationResult MonteCarlo::integrate(const function<double(double)>& f, double a, double b, uint64_t samples){
  if (samples < 2){
    throw invalid_argument("At least two samples are required.");
  }
  if (!(a < b)){
    throw invalid_argument("The lower bound must be smaller than the upper bound.");
  }

  const auto start {chrono::steady_clock::now()};

  uniform_real_distribution<double> distribution(a, b);

  double sum {0.0};
  double sumSquares {0.0};

  for (uint64_t i {0}; i < samples; ++i){
    const double x {distribution(rng)};
    const double y {f(x)};
    sum += y;
    sumSquares += y * y;
  }

  const double width {b - a};
  const double mean {sum / static_cast<double>(samples)};
  const double estimate {width * mean};
  
  const double variance {(sumSquares - sum*sum / static_cast<double>(samples)) / static_cast<double>(samples - 1)};
  const double standardError {width * sqrt(variance / static_cast<double>(samples))};

  const auto end {chrono::steady_clock::now()};

  const double eslapsedTimeMs {chrono::duration<double, milli>(end - start).count()};

  return IntegrationResult{estimate, standardError, eslapsedTimeMs, samples};
}
