#include "../includes/header.hpp"

void simpson_test(
    std::map<double (*)(double), std::pair<double, double>> func_and_range,
    double EPS) {

  std::cout << "===== START SIMPSON TEST ===== \n";

  int func_num = 1;

  for (const auto &[function, range] : func_and_range) {

    std::cout << "f" << func_num++ << " RESULT: "
              << Runge_rule(simpson_method, function, range.first, range.second,
                            EPS)
              << "\n";
  }

  std::cout << "===== END SIMPSON TEST ===== \n";
}
