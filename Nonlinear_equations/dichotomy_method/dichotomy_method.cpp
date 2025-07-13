#include "../includes/header.hpp"

double dichotomy_method(std::function<double(double)> f, double a, double b, double eps){

    if(f(a) * f(b) > 0)
        return NAN;

    double x_next;
    double x_prev = a;
    int iter = 0;

    do{ 

        x_next = (a + b) / 2;

        if (x_next < a || x_next > b) {
            return NAN;
        }
        
        if (fabs(x_next - x_prev) < eps) {
            break;
        }

        f(a) * f(x_next) < 0 ? b = x_next : a = x_next;

        ++iter;

        x_prev = x_next;
    
    } while(iter < MAX_ITER);
   
    iterations = iter;

    return x_next;
}
