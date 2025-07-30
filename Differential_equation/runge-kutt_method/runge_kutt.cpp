#include <functional>
#include <iostream>
#include <vector>

double f1(double x, double y) { return x + y; }

std::vector<std::pair<double, double>>
runge_kutt_method(std::function<double(double, double)> f,
                  std::pair<double, double> range,
                  std::pair<double, double> start_value, double h) {
  std::vector<std::pair<double, double>> result;

  result.push_back(start_value);
  double k1, k2, k3, k4, delta_y;
  double prev_x, prev_y;

  for (double x = range.first + h; x <= range.second; x += h) {
    prev_x = result.back().first;
    prev_y = result.back().second;

    k1 = h * f(prev_x, prev_y);

    k2 = h * f(prev_x + h / 2, prev_y + k1 / 2);

    k3 = h * f(prev_x + h / 2, prev_y + k2 / 2);

    k4 = h * (prev_x + h + prev_y + k3);

    delta_y = (k1 + 2 * k2 + 2 * k3 + k4) / 6;

    result.push_back({x, prev_y + delta_y});
  }

  return result;
}

int main() {
  std::vector<std::pair<double, double>> result =
      runge_kutt_method(f1, std::make_pair(0, 0.2), std::make_pair(0, 1), 0.1);

  for (const std::pair<double, double> el : result) {
    printf("\n{%f, %f}\n", el.first, el.second);
  }
  return 0;
}