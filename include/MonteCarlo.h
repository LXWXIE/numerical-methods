#pragma once

#include <random>
#include <functional>
#include <cstdint>

using namespace std;

struct IntegrationResult{
  double estimate;
  double standardError;
  double executionTimeMs;
  uint64_t samples;
};

class MonteCarlo{
  private:
    mt19937 rng;
  public:
    MonteCarlo(uint32_t seed=1);

    IntegrationResult integrate(const function<double(double)>& f, double a, double b, uint64_t samples);

};
