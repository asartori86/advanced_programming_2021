#include <iostream>

struct Foo {
  static double s;  // must be defined outside the class
  // static int si = 0; // error: must be const or constexpr
  static const int sc = 9;  // only integral types are allowed
  // static const double sd = 1.1;  // error
  static constexpr double sd = 1.1;  // error
  int i;
};

double Foo::s;

// double Foo::s = 0;
// double Foo::s = 9;

// int Foo::i = 2; // error, only static members can be defined out of class

int main() {
  Foo::s = 77.88;
  Foo f1;
  Foo f2;
  std::cout << sizeof(f1) << std::endl;
  std::cout << f1.s << '\n' << f2.s << '\n' << Foo::s << std::endl;
  return 0;
}
