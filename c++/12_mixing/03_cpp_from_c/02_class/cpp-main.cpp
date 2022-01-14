#include "class.hpp"

#include <iostream>

int main() {
  Foo f(10);
  f.print();
  f.get_a() = 7;
  f.print();
  return 0;
}
