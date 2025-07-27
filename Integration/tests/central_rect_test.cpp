#include "../includes/header.hpp"

void central_rect_test(
    std::map<double (*)(double), std::pair<double, std::pair<double, double>>>
        func_and_range,
    double EPS) {

  int func_num = 1;

  std::cout << "===== START CENTRAL RECT TEST ===== \n";

  for (const auto &[function, range] : func_and_range) {

    double result = Runge_rule(central_rect, function, range.second.first,
                               range.second.second, EPS, 2);

    double correct_result = range.first;

    double delta_result = fabs(result - correct_result);

    std::cout << "f" << func_num++ << " RESULT: " << result
              << " CORRECT RESULT: " << correct_result
              << " DELTA RESULT: " << delta_result << "\n";
  }

  std::cout << "===== END CENTRAL RECT TEST ===== \n";
}
