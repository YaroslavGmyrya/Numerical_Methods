#include <cmath>
#include <functional>

double simpson_method(std::function<double(double)> f, double a, double b,
                      int n) {
  if (n % 2 != 0) {
    ++n;
  }

  double h = (b - a) / n;

  double sum = 0;

  int k = 4;

  for (int i = 1; i < n; i++) {
    sum += k * f(a + i * h);
    k = 6 - k;
  }

  return (f(a) + f(b) + sum) * h / 3;
}
