#include "../tests/header.hpp"

double chord_method(std::function<double(double)> f, double a, double b, double eps) {
    if (f(a) * f(b) >= 0) 
        return NAN;

    double next_value = a;
    int iter = 0;

    while (fabs(b - a) > eps && iter < MAX_ITER) {
        double fa = f(a), fb = f(b);

        double denom = fb - fa;
        if (fabs(denom) < 1e-14) return NAN;

        next_value = a - fa * (b - a) / denom;

        double f_next = f(next_value);
        if (!std::isfinite(f_next)) return NAN;

        if (fa * f_next < 0)
            b = next_value;
        else
            a = next_value;

        if (fabs(f_next) < eps) break;

        iter++;
    }

    iterations = iter;

    return next_value;
}
