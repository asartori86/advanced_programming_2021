#include "stack_pool.hpp"
#include <iostream>

int& foo(int& i) {
  return i;
}

int main() {
  stack_pool<int, std::size_t> pool{22};
  auto s = pool.new_stack();
  auto s2 = pool.new_stack();
  int val = 3;
  s = pool.push(3, s);
  s2 = pool.push(2, s2);
  std::cout << pool.value(s2) << std::endl;
  s2 = pool.push(4, s2);
  std::cout << pool.value(s2) << std::endl;
  std::cout << "free: " << pool.get_free_nodes() << std::endl;
  s2 = pool.pop(s2);
  std::cout << pool.value(s2) << std::endl;
  std::cout << "free: " << pool.get_free_nodes() << std::endl;
  s2 = pool.push(6, s2);
  std::cout << pool.value(s2) << std::endl;
  std::cout << "free: " << pool.get_free_nodes() << std::endl;

  // while (s) {
  // std::cout << pool.value(s) << std::endl;
  // }

  std::cout << "s: " << s << std::endl;
  std::cout << "s2: " << s2 << std::endl;

  return 0;
}