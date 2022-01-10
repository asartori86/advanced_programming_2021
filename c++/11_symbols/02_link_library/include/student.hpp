#ifndef STUDENT_H
#define STUDENT_H

#include "date.hpp"
#include <iostream>
#include <string>

struct student {
  std::string name;
  date birth;
  float avg;
};

std::ostream& operator<<(std::ostream&, const student&);
#endif
