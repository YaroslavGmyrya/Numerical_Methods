#include <iostream>
#include <cmath>
#include <functional>
#include <vector>

#define MAX_ITER 1000

double iterations;

double f0(double x) {
    return (x - 1) * (x - 4.26); 
}

double f1(double x) {
    return 2*x - 5;  
}

double f2(double x) {
    return x*x - 4;  
}

double f3(double x) {
    return x*x*x - 8; 
}

double f4(double x) {
    return sin(x) - 0.5;  
}

double f5(double x) {
    return exp(x) - 10;  
}

double f6(double x) {
    return log(x + 1) - 1;  
}

double f7(double x) {
    return x*x - cos(x);  
}

double f8(double x) {
    return 1/x + 2;  
}

double f9(double x) {
    return tanh(x) - 0.5;  
}

double f10(double x) {
    return fabs(x) - 1;  
}

double f11(double x) {
    return x*x*x*x - 5*x*x + 4;  
}

double f12(double x) {
    return (x-3)*(x-3)*(x+2); 
}

double f13(double x) {
    return x*x*x - x - 2;  
}

double f14(double x) {
    return exp(-x) - x*x;  
}

double f15(double x) {
    return log(x+2) - x + 1;  
}

double f16(double x) {
    return tanh(x) - x/3;  
}

double f17(double x) {
    return sin(10*x) - x; 
}

double f18(double x) {
    return cos(x) - exp(-x);  
}

double f19(double x) {
    return tan(x) - 1;  
}

double f20(double x) {
    return exp(-x/3) * sin(x) - 0.2;  
}

double f21(double x) {
    return log(fabs(x)+1) - sqrt(x+1) + 1;  
}

double f22(double x) {
    return sin(x*x) * exp(-x) + log(x+1) - 1;  
}

double first_derivative(std::function<double(double)> f, double x, double h = 1e-5) {
    return (f(x + h) - f(x - h)) / (2 * h); 
}

double second_derivative(std::function<double(double)> f, double x, double h = 1e-5) {
    return (f(x + h) - 2 * f(x) + f(x - h)) / (h * h);
}

double newton_method(std::function<double(double)> f, double a, double b, double eps) {
    double x0, x_next, iter = 0;
    
    x0 = a;

    if (f(x0) * second_derivative(f, x0) <= 0) {
        x0 = b;
    }

   do {
        x_next = x0 - f(x0) / first_derivative(f, x0);
        
        if (x_next < a || x_next > b) {
            return NAN;
        }
        
        if (fabs(x_next - x0) < eps) {
            break;
        }
        
        x0 = x_next;
        iter++;

    } while (iter < MAX_ITER);
    
    iterations = iter;

    return x_next;
}

int main() {
    double a, b, eps;

    std::vector<std::function<double(double)>> func_collection = {
        f0, 
        f1, 
        f2, 
        f3, 
        f4, 
        f5, 
        f6, 
        f7, 
        f8, 
        f9, 
        f10, 
        f11, 
        f12, 
        f13, 
        f14, 
        f15, 
        f16, 
        f17, 
        f18, 
        f19, 
        f20, 
        f21, 
        f22
    };

    std::vector<double> left_limit = {
        1.5,   
        2.0,   
        1.0,   
        1.0,   
        0.0,   
        2.0,   
        1.5,   
        0.5,   
        -1.0,  
        0.0,   
        -2.0,  
        1.0,   
        2.5,   
        1.0,   
        0.5,   
        2.0,   
        -1.0,  
        0.0,   
        0.5,   
        0.5,   
        0.5,   
        1.0,   
        0.5    
    };

    std::vector<double> right_limit = {
        6,   
        3.0,   
        3.0,   
        3.0,   
        1.5,   
        3.0,   
        2.0,  
        1.0,   
        -0.1,  
        1.5,   
        0.5,   
        1.5,   
        3.5,   
        2.0,   
        1.0,   
        3.0,   
        1.0,   
        0.5,   
        1.0,   
        1.0,   
        1.5,   
        1.5,   
        1.5    
    };
    
    std::cout << "Enter the accuracy: ";
    std::cin >> eps;

    double result;

    for(int i = 0; i < func_collection.size(); ++i){
        result = newton_method(func_collection[i],left_limit[i], right_limit[i], eps);
        if(!std::isnan(result))
            std::cout << "Result f" << i << ": " << result << " iterations: "<< iterations << std::endl;
    }

    return 0;
}