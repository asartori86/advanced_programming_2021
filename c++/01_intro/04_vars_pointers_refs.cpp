#include <iostream>

int main() {
  double d {9.9};
  double& ref {d};  //this is references
  double* ptr {&d}; //this is a pointer, is an adress of another variable
  double* ptr {nullptr}; //not NULL and not 0!!! NULL != nullptr
  double* x {&d};

  std::cout << "value of   d: " << d << std::endl;
  std::cout << "value of ref: " << ref << std::endl;
  //reference is a pointer that automatically refers to itself
  std::cout << "value of (*x): " << (*x) << std::endl;
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
