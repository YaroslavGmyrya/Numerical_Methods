#include <cmath>
#include <map>

double f1(double x) { return log(x); }
double f2(double x) { return exp(x); }
double f3(double x) { return 1.0 / x; }
double f4(double x) { return x * x; }
double f5(double x) { return x * x * x; }
double f6(double x) { return x + x * x; }
double f7(double x) { return sin(x); }
double f8(double x) { return pow(sin(x), 2); }
double f9(double x) { return sqrt(x); }
double f10(double x) { return cos(x); }
double f11(double x) { return log(x); }
double f12(double x) { return exp(x); }
double f13(double x) { return 1.0 / x; }
double f14(double x) { return x * x; }
double f15(double x) { return x * x * x; }
double f16(double x) { return x + x * x; }
double f17(double x) { return sin(x); }
double f18(double x) { return pow(sin(x), 2); }
double f19(double x) { return sqrt(x); }
double f20(double x) { return cos(x); }
double f21(double x) { return (1 + x) / pow(2 + 3 * x, 2); }
double f22(double x) { return (1 + x) / (pow(2 + 3 * x, 2) * sqrt(2 + x)); }
double f23(double x) { return pow(1 + x, 2) / (pow(x, 3) * sqrt(2 + x)); }
double f24(double x) { return (1 + sqrt(x)) / (1 + 4 * x + 3 * x * x); }
double f25(double x) { return (2.5 * x * x - 0.1) / (log(x) + 1); }
double f26(double x) { return log(x) / sqrt(1.2 + 0.3 * x); }
double f27(double x) { return pow(x + 1, 2) / sqrt(log(x)); }
double f28(double x) { return sqrt(x) * exp(-x / 2); }

std::map<double (*)(double), std::pair<double, double>> func_and_range = {
    {f1, {1, 10}},
    {f2, {0, 5}},
    {f3, {0.2, 5.2}},
    {f4, {0, 10}},
    {f5, {0, 5}},
    {f6, {0, 5}},
    {f7, {0, M_PI}},
    {f8, {0, M_PI}},
    {f9, {0, 10}},
    {f10, {0, M_PI}},
    {f11, {1, 10}},
    {f12, {0, 5}},
    {f13, {5, 10}},
    {f14, {10, 20}},
    {f15, {5, 10}},
    {f16, {5, 10}},
    {f17, {M_PI, 2 * M_PI}},
    {f18, {M_PI, 2 * M_PI}},
    {f19, {10, 20}},
    {f20, {0, 2 * M_PI}},
    {f21, {0.1, 5}},
    {f22, {0.1, 5}},
    {f23, {0.1, 5}},
    {f24, {0.01, 10}},
    {f25, {0.1, 10}},
    {f26, {0.1, 10}},
    {f27, {1.1, 10}},
    {f28, {0.01, 10}}};
