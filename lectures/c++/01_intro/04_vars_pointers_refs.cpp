#include <iostream>

int main() {
  double d = 9.9;
  double& ref = d;
  double* ptr = &d;
  std::cout << "value of   d: " << d << std::endl;
  std::cout << "value of ref: " << ref << std::endl;
  std::cout << "value of ptr: " << ptr << std::endl << std::endl;

  std::cout << "address of   d: " << &d << std::endl;
  std::cout << "address of ref: " << &ref << std::endl;
  std::cout << "address of ptr: " << &ptr << std::endl << std::endl;

  // the value of variable d can be changed through either ref or
  // ptr as follows
  ref = 7.7;
  std::cout << "value of   d: " << d << std::endl;

  *ptr = 5.5;
  std::cout << "value of   d: " << d << std::endl;
}
