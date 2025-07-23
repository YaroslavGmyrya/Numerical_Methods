#include <functional>

double left_rect(std::function<double(double)> f, double a, double b,
                 double n) {

  double h = (b - a) / n;

  double sum_rect_center_y, s = 0;

  for (int i = 0; i < n; ++i) {
    sum_rect_center_y += f(a + i * h);
  }

  s = sum_rect_center_y * h;

  return s;
}