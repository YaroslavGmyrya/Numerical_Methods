#include "../includes/header.hpp"

void right_rect_test(
    std::map<double (*)(double), std::pair<double, double>> func_and_range,
    double EPS) {

  std::cout << "===== START RIGHT RECT TEST ===== \n";

  int func_num = 1;

  for (const auto &[function, range] : func_and_range) {

    std::cout << "f" << func_num++ << " RESULT: "
              << Runge_rule(right_rect, function, range.first, range.second,
                            EPS)
              << "\n";
  }

  std::cout << "===== END RIGHT RECT TEST ===== \n";
}
