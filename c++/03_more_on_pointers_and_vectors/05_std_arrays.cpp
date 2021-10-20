#include <array>
#include <iostream>

// template <class T, std::size_t N>
// struct array;

template <typename T, std::size_t N>
void print_array_two(const std::array<T, N>& a);

template <typename T>
void print_array_one(const T& a);

int main() {
  std::array<int, 4> a{1, 2, 3, 4};
  std::array<int, 4> b{a};  // I can copy element-wise from another std::array
                            // this is not possible with plain built-in arrays
  b = a;
  for (auto x : a)
    std::cout << x << " ";
  std::cout << std::endl;

  for (auto x : b)
    std::cout << x << " ";
  std::cout << std::endl;

  a[0] = 0;  // same subscripting operator without bound checking

  for (const auto x : a)
    std::cout << x << " ";
  std::cout << std::endl;

  for (const auto x : b)
    std::cout << x << " ";
  std::cout << std::endl;

  for (auto& x : a)
    x *= 10;

  for (auto i = 0u; i < a.size(); ++i)
    std::cout << "a[" << i << "] = " << a[i] << std::endl;

  b.at(90);  // bound checking at run-time

  return 0;
}

template <typename T, std::size_t N>
void print_array_two(const std::array<T, N>& a) {
  for (const auto& x : a)
    std::cout << x << " ";
  std::cout << std::endl;
}

template <typename T>
void print_array_one(const T& a) {
  for (const auto& x : a)
    std::cout << x << " ";
  std::cout << std::endl;
}
