#include "greetings.hpp"
#include <iostream>

void print_greetings() {
#ifdef ITALIANO
  std::cout << "Benvenuti al corso di Advanced Programming\n";
#endif

#ifdef ENGLISH
  std::cout << "Welcome to the Advanced Programming course\n";
#endif
}
