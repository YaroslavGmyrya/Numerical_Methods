#include <functional>

double central_rect(std::function<double(double)> f, double a, double b,
                    int n) {

  double h = (b - a) / n;

  double sum_rect_center_y, s = 0;

  for (int i = 0; i < n; ++i) {
    sum_rect_center_y += f(a + (i + 0.5) * h);
  }

  s = sum_rect_center_y * h;

  return s;
}
