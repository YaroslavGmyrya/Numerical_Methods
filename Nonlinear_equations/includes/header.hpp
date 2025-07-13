#pragma once

#include <cmath>
#include <map>
#include <vector>
#include <functional>
#include <iostream>
#include <string>

#define MAX_ITER 10000

extern double iterations;

//Type 1

double f1(double x);
double f2(double x);
double f3(double x);
double f4(double x);
double f5(double x);
double f6(double x);
double f7(double x);
double f8(double x);
double f9(double x);
double f10(double x);
double f11(double x);
double f12(double x);
double f13(double x);
double f14(double x);
double f15(double x);
double f16(double x);
double f17(double x);
double f18(double x);
double f19(double x);
double f20(double x);
double f21(double x);
double f22(double x);
double f23(double x);

// Type 2

double f24(double x);
double f25(double x);
double f26(double x);
double f27(double x);
double f28(double x);
double f29(double x);
double f30(double x);
double f31(double x);
double f32(double x);
double f33(double x);
double f34(double x);
double f35(double x);
double f36(double x);
double f37(double x);
double f38(double x);
double f39(double x);
double f40(double x);
double f41(double x);
double f42(double x);
double f43(double x);
double f44(double x);
double f45(double x);
double f46(double x);

double second_derivative(std::function<double(double)> f, double x, double h = 1e-5);
double first_derivative(std::function<double(double)> f, double x, double h = 1e-5);

double chord_method(std::function<double(double)> f, double a, double b, double eps);
double dichotomy_method(std::function<double(double)> f, double a, double b, double eps);
double newton_method(std::function<double(double)> f, double a, double b, double eps);

extern std::map<double (*)(double), std::pair<double, double>> func_and_range;
