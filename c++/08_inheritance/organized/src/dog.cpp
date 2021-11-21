#include "dog.hpp"
#include <iostream>

// void Dog::speak() const noexcept override{  don't repeat override
void Dog::speak() const noexcept {
  std::cout << "Bau\n";
}

Dog::Dog(const unsigned int a, const double d) : Animal{a, d} {}
