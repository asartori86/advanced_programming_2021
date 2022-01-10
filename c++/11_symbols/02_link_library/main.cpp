#include <iostream>
#include "student.hpp"
#include "date.hpp"
#include "greetings.hpp"
#include "conclusion.hpp"

int main()
{
  print_greetings();
  date d {5,12,1986};

  std::cout << d << std::endl;

  student s {"alberto", {4, 5, 1492}, 3.1};
  std::cout << s << std::endl;

  print_conclusion();

  return 0;
}
