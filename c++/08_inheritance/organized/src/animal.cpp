#include "animal.hpp"
#include <ap_error.hpp>

Animal::Animal() : Animal{0, 0} {}

Animal::Animal(const unsigned int a, const double w) : age{a}, weight{w} {
  AP_ERROR_GE(w, 0) << "invalid weight";
}

// virtual Animal::info() const noexcept{   would be error: do not repeat
// virtual
void Animal::info() const noexcept {
  std::cout << "age:\t" << age << '\n' << "weight:\t" << weight << '\n';
}
