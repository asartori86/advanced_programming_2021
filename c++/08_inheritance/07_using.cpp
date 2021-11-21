#include <iostream>

struct foo {
  void f(int x) { std::cout << "int " << x << std::endl; }
};

struct bar : public foo {
  using foo::f;  // brings all foo::f to this scope
  void f(char x) { std::cout << "char " << x << std::endl; }
};

int main() {
  bar b;
  b.f(33);
}
