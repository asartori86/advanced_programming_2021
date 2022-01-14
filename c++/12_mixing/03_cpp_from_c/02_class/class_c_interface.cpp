#include "class_c_interface.h"
#include "class.hpp"

extern "C" {

Foo_c create_foo(int b) {
  return new Foo(b);
}
void free_foo(Foo_c f) {
  delete static_cast<Foo*>(f);
}
void print_foo(Foo_c f) {
  static_cast<Foo*>(f)->print();
}
void set_a(Foo_c f, int v) {
  static_cast<Foo*>(f)->get_a() = v;
};
int get_a(Foo_c f) {
  return static_cast<Foo*>(f)->get_a();
}
}
