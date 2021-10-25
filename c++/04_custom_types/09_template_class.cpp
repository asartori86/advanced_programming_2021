#include <iostream>
#include <string>

template <typename T>
class Vector {
  T* elem;
  std::size_t _size;

 public:
  Vector(const std::size_t size) : elem{new T[size]}, _size{size} {}

  // automatically release the acquired memory
  ~Vector() { delete[] elem; }

  // try to remove the const and recompile
  std::size_t size() const { return _size; }

  T& operator[](const std::size_t i) {
    // ++i;
    return elem[i];
  }

  // try to comment this line and recompile
  const T& operator[](const std::size_t i) const { return elem[i]; }

  const T* begin() const { return elem; }
  T* begin() { return elem; }

  const T* end() const { return elem + _size; }
  T* end() { return elem + _size; }
};

template <typename T>
void foo(const Vector<T>& x) {
  auto p = x.begin();
  ++p;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& v) {
  for (auto i = 0u; i < v.size(); ++i)
    os << "v[" << i << "] = " << v[i] << std::endl;
  return os;
}

int main() {
  Vector<double> v{10};

  for (auto i = 0u; i < v.size(); ++i)
    v[i] = i;

  std::cout << v << std::endl;

  Vector<double>* pv{&v};

  // first dereference the pointer, then I can use the defined operators
  (*pv)[0] = -99.999;

  pv->operator[](1) = 77777.3333;  // or I call the function by name

  std::cout << *pv << std::endl;

  Vector<double>& rv{v};

  rv[5] = 555;

  std::cout << v << std::endl;

  return 0;
}
