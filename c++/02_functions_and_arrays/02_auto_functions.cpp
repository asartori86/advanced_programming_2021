#include <iostream>

auto factorial(unsigned int n) {
  unsigned int ret{1};
  while (n > 1) {
    ret *= n;
    --n;

    // or "simply"
    // ret *= n--;
  }
  return ret;
}

int main() {
  unsigned int f5{factorial(5)};

  auto f6 = factorial(6);

  std::cout << "factorial of 5 is " << f5 << '\n'
            << "factorial of 6 is " << f6 << std::endl;

  // errors
  // factorial(); // too few args
  // factorial(3,4,5,5); // too many args
  // factorial("byobu"); // wrong type
  return 0;
}
