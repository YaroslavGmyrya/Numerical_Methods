#include <functional>

double Runge_rule(
    std::function<double(std::function<double(double)>, double, double, double)>
        method_type,
    std::function<double(double)> f, double a, double b, double epsilon) {

  double n = 1;
  double s1, s2 = 0;
  double k = 2;
  double delta = __INT_MAX__;

  do {

    s1 = method_type(f, a, b, n);

    n *= 2;

    s2 = method_type(f, a, b, n);

    delta = abs(s2 - s1) / 2;

  } while (delta >= epsilon);

  return s2;
}