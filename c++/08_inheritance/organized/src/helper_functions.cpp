#include "helper_functions.hpp"

void print_animal(const Animal& a) noexcept {
  std::cout << "throught ref\n";
  a.info();
  a.speak();
}
