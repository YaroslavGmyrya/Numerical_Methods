#include "../includes/header.hpp"

void left_rect_test(
    std::map<double (*)(double), std::pair<double, double>> func_and_range,
    double EPS) {

  int func_num = 1;

  std::cout << "===== START LEFT RECT TEST ===== \n";

  for (const auto &[function, range] : func_and_range) {

    std::cout << "f" << func_num++ << " RESULT: "
              << Runge_rule(left_rect, function, range.first, range.second, EPS)
              << "\n";
  }

  std::cout << "===== END LEFT RECT TEST ===== \n";
}
