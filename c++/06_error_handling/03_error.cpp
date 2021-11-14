#include <cmath>
#include <iostream>

#include "ap_error.hpp"

// implment a square root function that "deals with" negative
// numbers. Moreover according to the logic of the program, d should
// never be greater than 50
double square_root(const double d);

struct Square_root_invalid {
  std::string message;
  Square_root_invalid(std::string s) : message{std::move(s)} {}
  const char* what() const { return message.c_str(); }
};

int main() {
  try {
    std::cout << "please insert a number\n";
    double number;
    std::cin >> number;
    double d = square_root(number);
    std::cout << "square root of " << number << " is " << d << '\n';
    return 0;
  } catch (const Square_root_invalid& e) {
    std::cerr << e.what() << std::endl;
    return 2;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  } catch (...) {
    std::cerr << "Unknown exception. Aborting.\n";
    return 3;
  }
}

double square_root(const double d) {
  // test the pre-conditions

  AP_ERROR(d >= 0 && d <= 50, Square_root_invalid)
      << "In our library the argument must be positive and less or equal than "
         "50.\n\nYou passed "
      << d << ".\n";

  // AP_ERROR(d >= 0 && d <= 50) << "In our library the argument must be
  // positive "
  //                                "and less or equal than 50.\n";

  // AP_ERROR_GE(d, 0) << "Cannot handle negative numbers.\n";

  // AP_ERROR_LE(d, 50) << "According to the implemented algorithm, the argument
  // "
  //                       "must be less than 50.\n";

  // AP_ERROR_IN_RANGE(d,0,50);

  return sqrt(d);
}
