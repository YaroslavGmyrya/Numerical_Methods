#pragma once

#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <vector>

#define N 10
#define multiplier 20

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
double f29(double x);
double f30(double x);

void show_point(std::vector<std::pair<double, double>> &vector);
void show_vector(std::vector<double> &vector);
std::vector<std::vector<double>>
compute_divided_difference(std::vector<std::pair<double, double>> &points);
std::vector<double>
compute_polynom_coeff(std::vector<std::vector<double>> &dd_table);
double compute_function(double x, std::vector<double> &poly_coeff,
                        std::vector<std::pair<double, double>> &points);
double compute_uniform_step(std::pair<double, double> range);
std::vector<double> compute_chebyshev_coeff(std::pair<double, double> range);
void test_uniform_step(
    std::map<double (*)(double), std::pair<double, double>> func_range);
void test_chebyshev_coeff(
    std::map<double (*)(double), std::pair<double, double>> func_range);

extern std::map<double (*)(double), std::pair<double, double>> func_range;
