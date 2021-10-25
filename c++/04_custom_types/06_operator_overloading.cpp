#include <array>
#include <iostream>
#include <vector>

struct Point_s {
  double x;
  double y;
};  // note ; at the end

std::ostream& operator<<(std::ostream& os, const Point_s& p) {
  os << "Struct. x = " << p.x << "; y = " << p.y << std::endl;
  return os;
}

class Point_c {
  double x;
  double y;

  friend std::ostream& operator<<(std::ostream& os, const Point_c& p) {
    os << "Class. x = " << p.x << "; y = " << p.y << std::endl;
    return os;
  }

};  // note ; at the end

int main() {
  Point_s ps;
  ps.x = 9.9;
  ps.y = 3. / 7;

  std::cout << ps;

  Point_c pc;
  // pc.x =7.6; // error
  std::cout << pc;

  Point_s* p = &ps;
  p->x = 0.0;
  std::cout << *p;  // operator overloading does not work with pointers

  return 0;
}
