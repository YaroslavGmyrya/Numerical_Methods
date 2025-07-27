#include "../includes/header.hpp"

int main(int argc, char *argv[]) {

  double EPS = argc == 2 ? std::stod(argv[1]) : eps;

  central_rect_test(func_and_range, EPS);

  return 0;
}