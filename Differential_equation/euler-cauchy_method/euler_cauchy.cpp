#include <functional>
#include <iostream>
#include <vector>

double f1(double x, double y) { return x + y; }

std::vector<std::pair<double, double>>
euler_cauchy_method(std::function<double(double, double)> f,
                    std::pair<double, double> range,
                    std::pair<double, double> start_value, double h) {
  std::vector<std::pair<double, double>> result;

  result.push_back(start_value);
  double prev_x, prev_y, cur_x, cur_y, delta_y;
  for (double i = range.first; i < range.second; i += h) {
    prev_x = result.back().first;
    prev_y = result.back().second;

    cur_x = prev_x + h;
    cur_y = prev_y + h * f(cur_x, prev_y);

    delta_y = h * (f(prev_x, prev_y) + f(cur_x, cur_y)) / 2;

    result.push_back({cur_x, prev_y + delta_y});
  }

  return result;
}

int main() {
  std::vector<std::pair<double, double>> result = euler_cauchy_method(
      f1, std::make_pair(0, 0.2), std::make_pair(0, 1), 0.1);

  for (const std::pair<double, double> el : result) {
    printf("\n{%f, %f}\n", el.first, el.second);
  }
  return 0;
}