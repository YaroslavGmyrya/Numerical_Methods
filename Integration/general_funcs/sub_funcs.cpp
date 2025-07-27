#include <cmath>
#include <map>

double f1(double x) { return log(x) - 1.0 / (x * x); }
double f2(double x) { return log(x) - 7.0 / (2 * x + 6); }
double f3(double x) { return 2 * log(x) - x / 2 + 1.0; }
double f4(double x) { return exp(-x) - pow(x - 1, 2); }
double f5(double x) { return (1 - x) / x - M_PI * cos(M_PI * x); }
double f6(double x) { return exp(x) + x * x - 10; }
double f7(double x) { return cos(2 * x) - x * x; }
double f8(double x) { return exp(x) - 2 * pow(x - 2, 2); }
double f9(double x) { return 3 * sin(M_PI * x / 4) - x - 2; }
double f10(double x) { return exp(x) + 2 * x * x - 3; }
double f11(double x) { return sqrt(x) - 2 - sin(M_PI / 2) * x; }
double f12(double x) { return exp(-x) - sqrt(x - 1); }
double f13(double x) { return sqrt(x) - cos(x / 2); }
double f14(double x) { return 2 * sin(3 * x) - 1.5 * x; }
double f15(double x) {
  return 2 * log(x) - 1.0 / (x * (3 - 3 * cos(x) * cos(x)));
}
double f16(double x) { return 2 * exp(-x / 2); }
double f17(double x) { return log(2 * x) - 0.5 * x + 2; }
double f18(double x) { return pow(x, 4) - sqrt(x + 1) - 3; }
double f19(double x) { return x * log(x) - 3.0 / x; }
double f20(double x) { return x * log(x) - 3 / x; }
double f21(double x) { return sin(3 * x / 4) - x * x - 4; }
double f22(double x) { return exp(-x) + 5 * pow(x - 1, 2); }
double f23(double x) { return exp(1 - x) + x * x - 5; }
double f24(double x) { return sqrt(x + 1) - 2 * cos(x / 2); }
double f25(double x) { return 2 * sin(2 * x) - x * x; }
double f26(double x) { return sqrt(2 * x) - cos(x / 3); }
double f27(double x) { return 2 * exp(-x) - pow(x + 1, 2); }
double f28(double x) { return exp(x - 1) + 2 * x * x - 7; }
double f29(double x) { return cos(x) - 2 * (x + 1); }
double f30(double x) { return sin(2.5 * x) - 5 * x; }

std::map<double (*)(double), std::pair<double, std::pair<double, double>>>
    func_and_range = {
        {f1, {4.9172235, {1, 6}}},      {f2, {4.4143535, {1, 7}}},
        {f3, {9.2427421, {1, 7}}},      {f4, {-3.9642501, {-3, 3}}},
        {f5, {-2.3905621, {1, 5}}},     {f6, {-1.9144631, {0, 3}}},
        {f7, {-5.4851511, {0.5, 2.4}}}, {f8, {13.085537, {0, 3}}},
        {f9, {-12.94208, {-0.5, 4.5}}}, {f10, {5.9203875, {-2, 2}}},
        {f11, {-25.868708, {1, 6}}},    {f12, {-6.6540367, {2, 6}}},
        {f13, {16.890734, {1, 8}}},     {f14, {-3.5501085, {-1, 2}}},
        {f15, {9.7093542, {1, 6}}},     {f16, {40.0715, {-3, 3}}},
        {f17, {-4.2228365, {-2, 3}}},   {f18, {13.514176, {1, 10}}},
        {f19, {10.384478, {0.5, 2.5}}}, {f20, {9.2896602, {1, 5}}},
        {f21, {-33.892315, {0.2, 4}}},  {f22, {65.672602, {-2, 3}}},
        {f23, {6.61687, {-2, 3}}},      {f24, {6.7374037, {0, 5}}},
        {f25, {-8.9601703, {0, 3}}},    {f26, {7.5547017, {1.5, 6}}},
        {f27, {-8.9667005, {-3, 2}}},   {f28, {16.0715, {-3, 3}}},
        {f29, {-15.017409, {-1, 3}}},   {f30, {-1050.39527, {-0.2, 20.5}}}};
