#include "instrumented.hpp"
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

template <typename I>
void set_instrumented(const std::size_t n, I first, I last) {
  using value_type = typename std::iterator_traits<I>::value_type;
  value_type::initialize(n);
  std::set<value_type> set{first, last};
  value_type::print_summary();
}

template <typename I>
void vector_instrumented(const std::size_t n, I first, I last) {
  using value_type = typename std::iterator_traits<I>::value_type;
  std::vector<value_type> v{first, last};
  value_type::initialize(n);
  std::sort(v.begin(), v.end());
  auto it = std::unique(v.begin(), v.end());
  value_type::print_summary();
}

int main() {
  using value_type = instrumented<int>;
  value_type::print_header();
  for (std::size_t n = 16; n < (1 << 25); n <<= 1) {
    std::vector<value_type> v(n);
    std::iota(v.begin(), v.end(), value_type(-1024));
    std::random_shuffle(v.begin(), v.end());
    for (std::size_t i = 0; i < n; ++i)
      v[i] = int{v[i]} & 255;

    set_instrumented(n, v.begin(), v.end());
    // vector_instrumented(n, v.begin(), v.end());
  }
}
