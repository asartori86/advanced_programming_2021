#include <iostream>

extern "C" {
void hello_from_cpp() {
  std::cout << "hello from cpp\n";
}
}
