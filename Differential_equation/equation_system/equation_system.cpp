#include "../includes/header.hpp"
#include <functional>

double runge_kutt(std::function<double(double, std::vector<double>)> f,
                  double t, std::vector<double> values, double h, int num_val) {
  std::vector<double> temp = values;
  double k1 = h * f(t, values);

  temp[num_val] = values[num_val] + k1 / 2;
  double k2 = h * f(t + h / 2, temp);

  temp[num_val] = values[num_val] + k2 / 2;
  double k3 = h * f(t + h / 2, temp);

  temp[num_val] = values[num_val] + k3;
  double k4 = h * f(t + h, temp);

  return (k1 + 2 * k2 + 2 * k3 + k4) / 6;
}

void equation_system(
    std::vector<std::function<double(double, std::vector<double>)>>
        f_collection,
    std::vector<double> &values, std::pair<double, double> range, double h) {
  double start = range.first;
  double end = range.second;

  for (double cur_t = start; cur_t < end; cur_t += h) {
    std::vector<double> prev_values = values;
    for (int i = 0; i < values.size(); ++i) {
      values[i] += runge_kutt(f_collection[i], cur_t, prev_values, h, i);
    }
  }
}