#include <iostream>

struct foo {
  int a;

  // should we add explicit?
  foo(const int a, const double d = 9) : a{a} {
    std::cout << "custom ctor" << std::endl;
  }

  foo(const int a, const double d, std::string s);  // no need to add explicit
};

void bar(const foo& x) {
  std::cout << x.a << std::endl;
}

int main() {
  int a{5};
  foo f{a};

  bar(7);  // should this compile?
}
