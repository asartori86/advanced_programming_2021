#include <chrono>
#include <iostream>
constexpr std::size_t fib(const unsigned int x) {
  return (x < 2) ? x : fib(x - 1) + fib(x - 2);
  // if (x < 2) return x;
  // else {
  //   return fib(x-1) + fib(x-2);
  // }
}

std::size_t fib_rt(const std::size_t x) {
  if (x < 2)
    return x;
  return fib(x - 1) + fib(x - 2);
}

template <unsigned i>
constexpr std::size_t fib_t() {
  return fib_t<i - 1>() + fib_t<i - 2>();
}

template <>
constexpr std::size_t fib_t<0>() {
  return 0;
}

template <>
constexpr std::size_t fib_t<1>() {
  return 1;
}

#if __cplusplus > 201700L

template <unsigned i>
constexpr std::size_t fib_t17() {
  if constexpr (i < 2)
    return i;
  else {  // very important
    return fib_t17<i - 1>() + fib_t17<i - 2>();
  }
}
#endif

constexpr unsigned int num{24};

int main() {
  {
    auto t0 = std::chrono::high_resolution_clock::now();
    constexpr auto x = fib(num);
    auto t1 = std::chrono::high_resolution_clock::now();
    auto elapsed =
        std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0);
    std::cout << "constexpr: " << x << " [" << elapsed.count() << " us]"
              << std::endl;
  }

  {
    auto t0 = std::chrono::high_resolution_clock::now();
    auto x = fib_rt(num);
    auto t1 = std::chrono::high_resolution_clock::now();
    auto elapsed =
        std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0);
    std::cout << "run time: " << x << " [" << elapsed.count() << " us]"
              << std::endl;
  }

  {
    auto t0 = std::chrono::high_resolution_clock::now();
    auto x = fib_t<num>();
    auto t1 = std::chrono::high_resolution_clock::now();
    auto elapsed =
        std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0);
    std::cout << "template: " << x << " [" << elapsed.count() << " us]"
              << std::endl;
  }

#if __cplusplus > 201700L
  {
    auto t0 = std::chrono::high_resolution_clock::now();
    auto x = fib_t17<num>();
    auto t1 = std::chrono::high_resolution_clock::now();
    auto elapsed =
        std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0);
    std::cout << "c++17: " << x << " [" << elapsed.count() << " us]"
              << std::endl;
  }

#endif

  return 0;
}
