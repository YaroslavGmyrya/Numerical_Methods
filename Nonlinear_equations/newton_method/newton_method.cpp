#include "../tests/header.hpp"

double newton_method(std::function<double(double)> f, double a, double b, double eps) {
    double x0, x_next, iter = 0;
    
    x0 = a;

    if (f(x0) * second_derivative(f, x0) <= 0) {
        x0 = b;
    }

   do {
        x_next = x0 - f(x0) / first_derivative(f, x0);
        
        if (fabs(x_next - x0) < eps) {
            break;
        }

         if (x_next < a || x_next > b) {
            return NAN;
        }
        
        x0 = x_next;
        iter++;

    } while (iter < MAX_ITER);
    
    iterations = iter;

    return x_next;
}
