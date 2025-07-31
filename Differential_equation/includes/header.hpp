#pragma once

#include <functional>

// coeffs
#define a_E 0.999
#define a_I 0.999
#define k 0.042
#define p 0.952
#define B 0.999
#define u 0.0188
#define c_isol 0
#define tau 2
#define N 1625631
#define gamma 0

enum start_values { S = 0, E, I, R, D };

double a(int t);
double c(int t);

double dS_dt(double t, std::vector<double>);
double dE_dt(double t, std::vector<double>);
double dI_dt(double t, std::vector<double>);
double dR_dt(double t, std::vector<double>);
double dD_dt(double t, std::vector<double>);

void equation_system(
    std::vector<std::function<double(double, std::vector<double>)>>
        f_collection,
    std::vector<double> &values, std::pair<double, double> range, double h);

std::vector<std::pair<double, double>>
euler_method(std::function<double(double, double)> f,
             std::pair<double, double> range,
             std::pair<double, double> start_value, double h);

std::vector<std::pair<double, double>>
euler_cauchy_method(std::function<double(double, double)> f,
                    std::pair<double, double> range,
                    std::pair<double, double> start_value, double h);

std::vector<std::pair<double, double>>
runge_kutt_method(std::function<double(double, double)> f,
                  std::pair<double, double> range,
                  std::pair<double, double> start_value, double h);