#include <functional>
#include <iostream>
#include <cmath>
#include <map>

double first_derivative(std::function<double(double)> f, double x, double h = 1e-5) {
    return (f(x + h) - f(x - h)) / (2 * h); 
}

double second_derivative(std::function<double(double)> f, double x, double h = 1e-5) {
    return (f(x + h) - 2 * f(x) + f(x - h)) / (h * h);
}

double f1(double x) { return  pow(x,4) - 2*x - 4; }
double f2(double x) { return  pow(x,3) - 3* pow(x,2) + 6*x + 3; }
double f3(double x) { return  pow(x,3) - 0.1* pow(x,2) + 0.4*x - 1.5; }
double f4(double x) { return  pow(x,3) - 3* pow(x,2) + 12*x - 9; }
double f5(double x) { return  pow(x,3) - 0.2* pow(x,2) - 0.2*x - 1.2; }
double f6(double x) { return pow(x,5) - x - 0.2; }
double f7(double x) { return  pow(x,3) - 2*x - 5; }
double f8(double x) { return  pow(x,3) - 2* pow(x,2) - 4*x - 7; }
double f9(double x) { return  pow(x,3) + 2*x - 7; }
double f10(double x) { return  pow(x,4) + 3*x - 20; }
double f11(double x) { return  pow(x,3) - x + 1; }
double f12(double x) { return  pow(x,3) -  pow(x,2) - 9*x + 9; }
double f13(double x) { return  pow(x,2) - 2*x + 1; }
double f14(double x) { return  pow(x,3) - 3* pow(x,2) + 9*x - 8; }
double f15(double x) { return  pow(x,3) - 6*x - 8; }
double f16(double x) { return  pow(x,3) + 3* pow(x,2) + 6*x - 1; }
double f17(double x) { return  pow(x,3) + 4*x - 6; }
double f18(double x) { return  pow(x,3) + 3* pow(x,2) + 12*x + 3; }
double f19(double x) { return  pow(x,4) - 4*x - 1; }
double f20(double x) { return  pow(x,3) + x - 5; }
double f21(double x) { return  pow(x,3) + 2* pow(x,2) + 2; }
double f22(double x) { return  pow(x,3) - 3* pow(x,2) + 9*x - 10; }
double f23(double x) { return  pow(x,4) - 3* pow(x,2) + 75*x - 10000; }

// Type 2

double f24(double x) { return 2 - log10(x) - x; }
double f25(double x) { return tan(1.9*x) - 2.8*x; }
double f26(double x) { return sin(2.2*x) - x; }
double f27(double x) { return log(8*x) - (9*x - 3); }
double f28(double x) { return 0.7*exp(-0.59*x) - x; }
double f29(double x) { return 5.6*sin(4.8*x) - 4.5*x; }
double f30(double x) { return tan(x) - x; }
double f31(double x) { return x - sin(x) - 0.25; }
double f32(double x) { return tan(0.58*x + 0.1) -  pow(x,2); }
double f33(double x) { return sqrt(x - cos(0.387*x)); }
double f34(double x) { return 3*x - cos(x) - 1; }
double f35(double x) { return x + log10(x) - 0.5; }
double f36(double x) { return  pow(x,2) + 4*sin(x); }
double f37(double x) { return tan(0.5*x + 0.2) -  pow(x,2); }
double f38(double x) { return 1/tan(x) - x/4; } 
double f39(double x) { return 1/tan(x) - x/5; }
double f40(double x) { return 2*log10(x) - x/2 + 1; }
double f41(double x) { return  pow(x,2) - 20*sin(x); }
double f42(double x) { return  pow(x,2) - sin(x); }
double f43(double x) { return  pow(x,3) - sin(x); }
double f44(double x) { return log(x) + pow(x+1, 3); }
double f45(double x) { return x * pow(2,x) - 1; }
double f46(double x) { return (2-x)*exp(x) - 0.5; }

std::map<double (*)(double), std::pair<double, double>> func_and_range = {
    {f1, {-0.5, 10}},{f2, {-20, 50}},{f3, {-20, 50}},{f4, {-20, 50}},{f5, {-20, 50}},{f6, {0, 2}},
    {f7, {-20, 50}},{f8, {-20, 50}},{f9, {-20, 50}},{f10, {0, 2.5}},{f11, {-20, 50}},{f12, {1.5, 50}},
    {f13, {0, 1}},{f14, {0, 3}},{f15, {0, 3}},{f16, {-20, 50}},{f17, {-20, 50}},{f18, {-20, 50}},
    {f19, {0, 2}},{f20, {-20, 50}},{f21, {-20, 50}},{f22, {-20, 50}},{f23, {-5, 150}},
    {f24, {0.5, 5}}, {f25, {0.2, 0.6}}, {f26, {0.5, 150}}, {f27, {0.5, 1}}, {f28, {-5, 20}}, {f29, {0.2, 150}},
    {f30, {-1.25, 1.25}}, {f31, {-20, 50}}, {f32, {0, 1}}, {f33, {0, 1}}, {f34, {0, 5}}, {f35, {0.25, 5}},
    {f36, {1, 150}}, {f37, {0, 100}}, {f38, {1, 3}}, {f39, {0, 100}}, {f40, {2, 150}}, {f41, {1, 150}}, 
    {f42, {0.5, 150}}, {f43, {0.5, 2.5}}, {f44, {0.1, 1}}, {f45, {-20, 2.5}}, {f46, {-1, 2}}, 
};