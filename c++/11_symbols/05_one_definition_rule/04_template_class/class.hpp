#ifndef __class__
#define __class__

#include <iostream>

template <typename T = double>
struct A {
  T a;
  A();
};

template <typename T>
A<T>::A() {
  std::cout << "A ctor\n";
}

#endif
