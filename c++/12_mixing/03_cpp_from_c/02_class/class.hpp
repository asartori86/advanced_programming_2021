#ifndef _CLASS_HPP_
#define _CLASS_HPP_

#include <iostream>

class Foo {
  int a;

 public:
  Foo(int b) : a{b} {}
  void print();
  int& get_a() { return a; }
};

#endif /* _CLASS_HPP_ */
