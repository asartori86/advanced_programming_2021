#include "constants.hpp"
#include <iostream>

double area_circle(const double);
double golden_ratio(const double);
extern int circle_counter;

int main() {
  std::cout << area_circle(1) << std::endl;
  std::cout << area_circle(2) << std::endl;

  std::cout << golden_ratio(1) << std::endl;

  std::cout << circle_counter << std::endl;
  std::cout << "[main] pi = " << pi << std::endl;

  return 0;
}
