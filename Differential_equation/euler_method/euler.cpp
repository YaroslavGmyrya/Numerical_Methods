#include <functional>
#include <iostream>
#include <vector>

double f1(double x, double y) { return x + y; }

std::vector<std::pair<double, double>>
euler_method(std::function<double(double, double)> f,
             std::pair<double, double> range,
             std::pair<double, double> start_value, double h) {
  std::vector<std::pair<double, double>> result;

  result.push_back(start_value);
  double prev_y, delta_y, cur_x;

  for (double i = range.first; i < range.second; i += h) {
    prev_y = result.back().second;
    cur_x = result.back().first + h;
    delta_y = h * f(cur_x, prev_y);

    result.push_back({cur_x, prev_y + delta_y});
  }

  return result;
}

// int main() {
//   std::vector<std::pair<double, double>> result =
//       euler_method(f1, std::make_pair(0, 0.2), std::make_pair(0, 1), 0.1);

//   for (const std::pair<double, double> el : result) {
//     printf("\n{%f, %f}\n", el.first, el.second);
//   }
//   return 0;
// }