#include "../includes/header.hpp"

void test_uniform_step(
    std::map<double (*)(double), std::pair<double, double>> func_range) {
  double tmp;

  double h;

  std::vector<std::pair<double, double>> points;

  std::vector<std::vector<double>> div_diff;

  std::vector<double> poly_coeff;

  std::vector<double> original_value;

  std::vector<double> interpolation_value;

  std::cout << "\n\n ===== START UNIFORM STEP TEST ===== \n\n";

  int func_num = 1;

  for (auto &[test_function, range] : func_range) {

    std::cout << "===== Function f" << func_num++ << " =====\n";

    points.clear();
    original_value.clear();
    interpolation_value.clear();

    range.second *= multiplier;

    h = compute_uniform_step(range);

    std::cout << "Step: " << h << "\n";

    for (int i = 0; i <= N; ++i) {
      tmp = range.first + i * h;
      points.push_back({tmp, test_function(tmp)});
    }

    std::cout << "Points: ";

    show_point(points);

    div_diff = compute_divided_difference(points);

    poly_coeff = compute_polynom_coeff(div_diff);

    std::cout << "Polynom coefficient: ";

    show_vector(poly_coeff);

    std::cout << "Arguments: ";

    for (double i = range.first; i < range.second; i += 0.1) {
      std::cout << i << " ";
      original_value.push_back(test_function(i));
      interpolation_value.push_back(compute_function(i, poly_coeff, points));
    }

    std::cout << "\nOriginal value: ";

    show_vector(original_value);

    std::cout << "Interpolation value: ";

    show_vector(interpolation_value);
  }

  std::cout << "\n\n ===== END UNIFORM STEP TEST ===== \n\n";
}