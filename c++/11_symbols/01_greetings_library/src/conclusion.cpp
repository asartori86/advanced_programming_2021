#include "conclusion.hpp"
#include <iostream>

void print_conclusion() {
#ifdef ITALIANO
  std::cout << "Ci vediamo giovedì\n";
#endif

#ifdef ENGLISH
  std::cout << "See you on Thursday\n";
#endif
}
