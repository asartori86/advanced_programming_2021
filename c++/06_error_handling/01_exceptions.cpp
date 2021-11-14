#include <cmath>
#include <iostream>

// implment a square root function that "deals with" negative
// numbers. Moreover according to the logic of the program, d should
// never be greater than 50
double square_root(const double d);

struct Negative_number {};

struct Bigger_than_expected {};

int main() {
  try {
    std::cout << "please insert a number\n";
    double number;
    std::cin >> number;
    auto d = square_root(number);
    std::cout << "square root of " << number << " is " << d << '\n';
    return 0;
  } catch (const Negative_number) {
    std::cerr << "The square root of a negative number is a complex number.\n"
                 "square_root() is "
              << "limited to handle positive double numbers.\n";
    return 1;
  } catch (const Bigger_than_expected) {
    std::cerr << "The function square_root has been called with a parameter "
                 "greater than 50.\n"
              << "This means there is a bug in the algorithm that generated "
                 "this number.\n";
    return 2;
  } catch (...) {
    std::cerr << "Unknown exception. Aborting.\n";
    return 3;
  }
}

double square_root(const double d) {
  // test the pre-conditions
  if (d < 0)
    throw Negative_number{};
  if (d > 50)
    throw Bigger_than_expected{};
  return std::sqrt(d);
}
