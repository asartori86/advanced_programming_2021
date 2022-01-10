#ifndef DATE_H
#define DATE_H

#include <iostream>

struct date {
  unsigned int day;
  unsigned int month;
  unsigned int year;
};

std::ostream& operator<<(std::ostream&, const date&);

#endif
