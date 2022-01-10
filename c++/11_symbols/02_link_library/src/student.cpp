#include <iostream>
#include "student.hpp"

std::ostream& operator<<(std::ostream& os, const student& s) {
  os << "Student's name: " << s.name << "\n"
     << s.name << "'s date of birth " << s.birth << s.name
     << "'s average: " << s.avg << std::endl;
  return os;
}
