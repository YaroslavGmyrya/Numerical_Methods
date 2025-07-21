#include "../includes/header.hpp"

void test_chebyshev_coeff(
    std::map<double (*)(double), std::pair<double, double>> func_range) {
  double tmp;

  std::vector<double> chebyshev_coeff;

  std::vector<std::pair<double, double>> points;

  std::vector<std::vector<double>> div_diff;

  std::vector<double> poly_coeff;

  std::vector<double> original_value;

  std::vector<double> interpolation_value;

  std::cout << "\n\n ===== START CHEBYSHEV COEFFICIENT TEST ===== \n\n";

  int func_num = 1;

  for (auto &[test_function, range] : func_range) {

    std::cout << "\n===== Function f" << func_num++ << " =====\n\n";

    points.clear();
    original_value.clear();
    interpolation_value.clear();

    range.second *= multiplier;

    chebyshev_coeff = compute_chebyshev_coeff(range);

    std::cout << "Chebyshev_coefficient:\n";

    show_vector(chebyshev_coeff);

    for (const double el : chebyshev_coeff) {
      points.push_back({el, test_function(el)});
    }

    std::cout << "Points: ";

    show_point(points);

    div_diff = compute_divided_difference(points);

    poly_coeff = compute_polynom_coeff(div_diff);

    std::cout << "Polynom coefficient: ";

    show_vector(poly_coeff);

    std::cout << "Arguments: ";

    for (double i = range.first; i <= range.second; i += 0.1) {
      std::cout << i << " ";
      original_value.push_back(test_function(i));
      interpolation_value.push_back(compute_function(i, poly_coeff, points));
    }

    std::cout << "\nOriginal value: ";

    show_vector(original_value);

    std::cout << "Interpolation value: ";

    show_vector(interpolation_value);
  }

  std::cout << "\n\n ===== END CHEBYSHEV COEFFICIENT TEST ===== \n\n";
}