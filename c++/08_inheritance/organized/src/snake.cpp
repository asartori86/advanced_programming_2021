#include "snake.hpp"
#include <iostream>

Snake::Snake(const unsigned int a, const double w, const bool b)
    : Animal{a, w}, dangerous{b} {}

// do not repeat explicit here
Snake::Snake(const bool b) : Animal{}, dangerous{b} {}

void Snake::info() const noexcept {
  Animal::info();
  std::cout << "dangerous:\t" << (dangerous ? "true" : "false") << std::endl;
}

void Snake::speak() const noexcept {
  std::cout << "ssss\n";
}
