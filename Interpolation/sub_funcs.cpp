#include "includes/header.hpp"

double f1(double x) { return log(x) - 1.0 / (x * x); }

double f2(double x) { return log(x) - (7.0 / (2 * x + 6)); }

double f3(double x) { return 2 * log(x) - x / 2 + 1; }

double f4(double x) { return exp(-x) - pow(x - 1, 2); }

double f5(double x) { return (1 - x) / x - M_PI * cos(M_PI * x); }

double f6(double x) { return exp(x) + x * x - 10; }

double f7(double x) { return cos(2 * x) - x * x; }

double f8(double x) { return exp(x) - 2 * pow(x - 2, 2); }

double f9(double x) { return 3 * sin(M_PI / 4 * x) - x - 2; }

double f10(double x) { return exp(x) + 2 * x * x - 3; }

double f11(double x) { return sqrt(x - 2) - sin(M_PI / 2 * x); }

double f12(double x) { return exp(-x) - sqrt(x - 1); }

double f13(double x) { return sqrt(x) - cos(x / 2); }

double f14(double x) { return 2 * sin(3 * x) - 1.5 * x; }

double f15(double x) { return 2 * log(x) - 1.0 / x; }

double f16(double x) { return 2 * exp(-x) - x / 2; }

double f17(double x) { return (x - 3 * cos(x * x)) / (x * x); }

double f18(double x) { return log(2 * x) - 0.5 * x + 2; }

double f19(double x) { return pow(x, 4) - sqrt(x) + 1 - 3; }

double f20(double x) { return x * log(x) - 3.0 / x; }

double f21(double x) { return sin(3.0 / 4 * x) - pow(x, 2) - 4; }

double f22(double x) { return exp(-x) + 5 * pow(x - 1, 2); }

double f23(double x) { return exp(-x) + x * x - 5; }

double f24(double x) { return sqrt(x + 1) - 2 * cos(x / 2); }

double f25(double x) { return 2 * sin(2 * x) - x * x; }

double f26(double x) { return sqrt(2 * x) - cos(x / 3); }

double f27(double x) { return exp(x - 1) + 2 * x * x - 7; }

double f28(double x) { return 2 * exp(-x) - pow(x + 1, 2); }

double f29(double x) { return cos(x) - 2 - (x + 1); }

double f30(double x) { return sin(2.5 * x) - 5 * x; }

void show_point(std::vector<std::pair<double, double>> &vector) {
  for (const std::pair<double, double> el : vector) {
    std::cout << "(" << el.first << "," << el.second << ") ";
  }

  std::cout << "\n";
}

void show_vector(std::vector<double> &vector) {
  for (const double el : vector) {
    std::cout << el << " ";
  }

  std::cout << "\n";
}

double compute_uniform_step(std::pair<double, double> range) {
  return (range.second - range.first) / N;
}

std::vector<double> compute_chebyshev_coeff(std::pair<double, double> range) {
  std::vector<double> chebyshev_coeff;

  chebyshev_coeff.reserve(N - 1);

  double a = range.first, b = range.second;

  for (int i = 0; i < N; ++i) {

    chebyshev_coeff.push_back(
        (a + b) / 2 + (b - a) / 2 * cos(((2 * i + 1) * M_PI) / (2 * N)));
  }

  return chebyshev_coeff;
}