#include <cmath>    // M_PI
#include <iomanip>  // std::setprecision
#include <iostream>
#include <string>

int main() {
  // built-in types
  int a{-1};  // long long int, unsigned int
  // int a = -1; //  is fine
  std::cout << a << std::endl;

  double b{2.2};  // long double, float
  std::cout << b << std::endl;

  char c{'r'};  // unsigned char, signed char, wchar_t
  std::cout << c << std::endl;

  bool t{true};  // false,0,1,...
  std::cout << t << std::endl;

  // check the size of a variable type
  std::cout << "on my machine the size of an int is " << sizeof(int)
            << " bytes\n";
  std::cout << "on my machine the size of an double is " << sizeof(double)
            << " bytes\n";
  std::cout << "on my machine the size of a char is " << sizeof(char)
            << " bytes\n";
  std::cout << "on my machine the size of a bool is " << sizeof(bool)
            << " bytes\n";

  // if you want to make sure an int is e.g. 2 bytes use special
  // variables names
  int16_t small_int{};
  std::cout << "on every machine the size of variable small_int is "
            << sizeof(small_int) << " bytes\n";

  // not built-in but useful :)
  std::string s{"Hello, World!\n"};
  std::cout << s;

  // narrowing effect
  int var = 6.9;  // try to initialize var with the universal and
                  // uniform initialization
  // int v_narrow {6.9}; // compiler error or warning with variables
  // int v_narrow_w {int(a+b)}; // suppress error/warning with a cast

  std::cout << var << "\n";

  var += 7;
  var -= 7;
  var *= 7;
  var /= 7;
  var %= 7;
  var++;
  ++var;

  var = a + b;  // works also for strings
  var = a - b;
  var = a * b;
  var = a % var;  // modulus operator just between integers

  bool test;
  test = a == b;
  test = a < b;
  test = a > b;
  test = a <= b;
  test = a >= b;
  test = a != b;

  if (test) {
    std::cout << "test is true\n";
  } else {
    std::cout << "test is false\n";
  }

  // constants

  const int cc{7};
  // cc = 9;			// error

  constexpr double ce{cc * 8.1234 / M_PI};  // evaluated at compile-time

  int ve{int(ce * a)};  // ok create a variable from constexpr

  // constexpr int  n_ce {ve*8.1234/M_PI}; // error

  // cast to void to suppress warning of unused variable
  (void)ve;
  long double lpi = 3.141592653589793238462L;
  std::cout << std::setprecision(50) << M_PI << std::endl;
  std::cout << std::hex << 43 << std::endl;
  std::cout << std::oct << 43 << std::endl;
  std::cout << std::dec << 43 << std::endl;

  (void)lpi;

  return 0;
}
