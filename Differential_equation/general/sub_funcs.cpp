#include "../includes/header.hpp"

double a(int t) { return 2.5; }

double c(int t) { return 1 + c_isol * (1 - ((2 * a(t)) / 5)); }

double dS_dt(double t, std::vector<double> values) {
  return -c(t - tau) * (a_I * values[S] * values[I] / N +
                        a_E * values[S] * values[E] / N) +
         gamma * values[R];
}

double dE_dt(double t, std::vector<double> values) {
  return c(t - tau) * (a_I * values[S] * values[I] / N +
                       a_E * values[S] * values[E] / N) -
         (k + p) * values[E];
}
double dI_dt(double t, std::vector<double> values) {
  return k * values[E] - B * values[I] - u * values[I];
}

double dR_dt(double t, std::vector<double> values) {
  return B * values[I] + p * values[E] - gamma * values[R];
}
double dD_dt(double t, std::vector<double> values) { return u * values[I]; }