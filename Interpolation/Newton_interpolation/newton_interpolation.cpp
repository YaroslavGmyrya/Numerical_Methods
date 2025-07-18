#include "../includes/header.hpp"

std::vector<std::vector<double>>
compute_divided_difference(std::vector<std::pair<double, double>> &points) {

  const int n = points.size();

  std::vector<std::vector<double>> dd_table(n, std::vector<double>(n));
  std::vector<double> result;
  result.reserve(n - 1);

  for (int i = 0; i < n; ++i) {
    dd_table[i][0] = points[i].second;
  }

  for (int j = 1; j < n; ++j) {
    for (int i = 0; i < n - j; ++i) {
      dd_table[i][j] = (dd_table[i + 1][j - 1] - dd_table[i][j - 1]) /
                       (points[i + j].first - points[i].first);
    }
  }

  return dd_table;
}

std::vector<double>
compute_polynom_coeff(std::vector<std::vector<double>> &dd_table) {

  std::vector<double> poly_coeff;
  poly_coeff.reserve(dd_table[0].size());

  for (int i = 0; i < dd_table[0].size(); ++i) {
    poly_coeff.push_back(dd_table[0][i]);
  }

  return poly_coeff;
}

double compute_function(double x, std::vector<double> &poly_coeff,
                        std::vector<std::pair<double, double>> &points) {
  double result = 0;
  double coeff;

  for (int i = 1; i < poly_coeff.size(); ++i) {
    coeff = 1;
    for (int j = 0; j < i; ++j) {
      coeff *= x - points[j].first;
    }

    result += poly_coeff[i] * coeff;
  }

  result += poly_coeff[0];

  return result;
}
