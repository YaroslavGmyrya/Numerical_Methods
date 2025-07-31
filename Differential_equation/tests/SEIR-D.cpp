#include "../includes/header.hpp"
#include <functional>
#include <iostream>

int main() {

  double E0 = 100;
  double R0 = 0;
  double I0 = 0;
  double D0 = 0;
  double S0 = N - E0 - R0 - I0 - D0;

  std::vector<std::function<double(double, std::vector<double>)>> f_collection =
      {dS_dt, dE_dt, dI_dt, dR_dt, dD_dt};

  std::vector<double> start_values = {S0, E0, I0, R0, D0};

  equation_system(f_collection, start_values, {0, 90}, 1);

  printf("S = %f\nE = %f\nI = %f\nR = %f\nD = %f\n", start_values[S],
         start_values[E], start_values[I], start_values[R], start_values[D]);

  return 0;
}