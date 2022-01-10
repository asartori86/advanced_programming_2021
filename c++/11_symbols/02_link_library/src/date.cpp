#include "date.hpp"
#include <iostream>

std::ostream& operator<<(std::ostream& os, const date& d) {
  os << d.day << "/" << d.month << "/" << d.year << std::endl;
  return os;
}
