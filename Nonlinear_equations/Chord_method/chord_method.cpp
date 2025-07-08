#include <iostream>
#include <cmath>
#include <functional>

#define MAX_ITER 1000

double f(double x) {
    return (x - 1) * (x - 4.26); 
}

double derivative(std::function<double(double)> f, double x, double h = 1e-5) {
    return (f(x + h) - f(x - h)) / (2 * h); 
}

double second_derivative(std::function<double(double)> f, double x, double h = 1e-5) {
    return (f(x + h) - 2 * f(x) + f(x - h)) / (h * h);
}

double chord_method(double a, double b, double eps) {

    if (f(a) * f(b) >= 0) {
        return NAN;
    }

    double tmp;

    if(derivative(f, (b - a) / 2) * second_derivative(f, (b-a) / 2) > 0){
        tmp = b;
        b = a;
        a = tmp;
    }

    double next_value;
    int iter = 0;

    while (fabs(b - a) > eps && iter < MAX_ITER) {
        next_value = a - (f(a) * (b - a)) / (f(b) - f(a));
            
        f(a) * f(next_value) < 0 ?  b = next_value :  a = next_value;

        iter++;
    }

    return next_value;

}

int main() {
   double a, b, eps;

    std::cout << "Enter the left limit of the range: ";
    std::cin >> a;

    std::cout << "Enter the right limit of the range: ";
    std::cin >> b;

    std::cout << "Enter the accuracy: ";
    std::cin >> eps;

    std::cout << "Result: " << chord_method(a, b, eps) << std::endl;

    return 0;
}