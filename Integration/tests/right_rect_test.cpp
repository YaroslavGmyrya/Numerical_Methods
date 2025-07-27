#include "../includes/header.hpp"

void right_rect_test(
    std::map<double (*)(double), std::pair<double, std::pair<double, double>>>
        func_and_range,
    double EPS) {

  std::cout << "===== START RIGHT RECT TEST ===== \n";

  int func_num = 1;

  for (const auto &[function, range] : func_and_range) {

    double result = Runge_rule(right_rect, function, range.second.first,
                               range.second.second, EPS, 2);

    double correct_result = range.first;

    double delta_result = fabs(result - correct_result);

    std::cout << "f" << func_num++ << " RESULT: " << result
              << " CORRECT RESULT: " << correct_result
              << " DELTA RESULT: " << delta_result << "\n";
  }

  std::cout << "===== END RIGHT RECT TEST ===== \n";
}
