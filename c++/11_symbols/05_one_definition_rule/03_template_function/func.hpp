#pragma once

#include <iostream>

template <class T = double>
void dummy() {
  T t{};
  std::cout << t << ": dummy\n";
}
