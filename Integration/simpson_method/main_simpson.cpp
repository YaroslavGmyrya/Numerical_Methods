#include "../includes/header.hpp"

int main(int argc, char *argv[]) {

  double EPS = argc == 2 ? std::stod(argv[1]) : eps;

  simpson_test(func_and_range, EPS);

  return 0;
}