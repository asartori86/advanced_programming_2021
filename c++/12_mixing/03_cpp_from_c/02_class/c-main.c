#include "class_c_interface.h"
#include <stdio.h>

int main() {
  Foo_c f = create_foo(11);
  print_foo(f);
  set_a(f, 7);
  print_foo(f);
  set_a(f, 9);
  printf("hello from c! a is %d\n", get_a(f));
  free_foo(f);
  return 0;
}
