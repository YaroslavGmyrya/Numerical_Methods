#include <functional>

double trapeze_method(std::function<double(double)> f, double a, double b,
                      int n) {

  double h = (b - a) / n;

  double sum, s = 0;

  for (int i = 1; i < n; ++i) {
    sum += 2 * f(a + i * h);
  }

  sum = sum + f(a) + f(b);

  s = sum * h / 2;

  return s;
}
