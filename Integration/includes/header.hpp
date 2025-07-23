#pragma once

#include <cmath>
#include <functional>
#include <iostream>
#include <map>

#define eps 0.01

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
double f24(double x);
double f25(double x);
double f26(double x);
double f27(double x);
double f28(double x);

double left_rect(std::function<double(double)> f, double a, double b, double n);

double central_rect(std::function<double(double)> f, double a, double b,
                    double n);

double right_rect(std::function<double(double)> f, double a, double b,
                  double n);

double trapeze_method(std::function<double(double)> f, double a, double b,
                      double n);

double Runge_rule(
    std::function<double(std::function<double(double)>, double, double, double)>
        method_type,
    std::function<double(double)> f, double a, double b, double epsilon);

void left_rect_test(
    std::map<double (*)(double), std::pair<double, double>> func_and_range,
    double EPS);

void central_rect_test(
    std::map<double (*)(double), std::pair<double, double>> func_and_range,
    double EPS);

void right_rect_test(
    std::map<double (*)(double), std::pair<double, double>> func_and_range,
    double EPS);

void trapeze_test(
    std::map<double (*)(double), std::pair<double, double>> func_and_range,
    double EPS);

extern std::map<double (*)(double), std::pair<double, double>> func_and_range;
