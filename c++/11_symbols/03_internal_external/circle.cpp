#include "constants.hpp"
#include <iostream>

int circle_counter{0};

double area_circle(const double r) {
  std::cout << "[circle] pi = " << pi << std::endl;
  ++circle_counter;
  return pi * r * r;
}
