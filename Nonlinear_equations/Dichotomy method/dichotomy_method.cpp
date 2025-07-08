#include <iostream>
#include <cmath>

#define MAX_N 100 // для случая, если вдруг алгоритм зациклится

double f(double x){
    return (x-1) * (x-10) * (x-20);
}


double dichotomy_method(double a, double b, double eps){

    if(f(a) * f(b) > 0)
        return NAN;

    double c;
    int N = 0;

    while(fabs(a - b) > eps && N < MAX_N){

        std::cout <<"N = "  << N << " " << "C = " << c << std::endl;

        c = (a + b) / 2;

        f(a) * f(c) < 0 ? b = c : a = c;

        N++;
    
    }

    return c;
}

int main(){
    double a, b, eps;

    std::cout << "Enter the left limit of the range: ";
    std::cin >> a;

    std::cout << "Enter the right limit of the range: ";
    std::cin >> b;

    std::cout << "Enter the accuracy: ";
    std::cin >> eps;

    std::cout << "Result: " << dichotomy_method(a, b, eps) << std::endl;

    return 0;
}