#include "../includes/header.hpp"

void central_rect_test(
    std::map<double (*)(double), std::pair<double, double>> func_and_range,
    double EPS) {

  int func_num = 1;

  std::cout << "===== START CENTRAL RECT TEST ===== \n";

  for (const auto &[function, range] : func_and_range) {

    std::cout << "f" << func_num++ << " RESULT: "
              << Runge_rule(central_rect, function, range.first, range.second,
                            EPS)
              << "\n";
  }

  std::cout << "===== END CENTRAL RECT TEST ===== \n";
}
