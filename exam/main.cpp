#include "stack_pool.hpp"
#include <iostream>

int main() {
  stack_pool<int, std::size_t> pool{22};
  auto s = pool.new_stack();
  pool.value(s);
  std::cout << s << std::endl;
  return 0;
}