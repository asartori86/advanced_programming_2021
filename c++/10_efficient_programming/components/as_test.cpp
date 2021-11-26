#include "as_find_if.hpp"
#include <chrono>
#include <iostream>
#include <numeric>
#include <vector>

template <typename T>
class predicate_template {  // function object
  T value;

 public:
  predicate_template(const T& x) : value{x} {}
  bool operator()(const T& x) const noexcept { return x == value; }
};

template <class T>
class predicate_virtual : public predicate_base<T> {
  T value;

 public:
  predicate_virtual(const T& x) : value{x} {}
  bool operator()(const T& x) const noexcept override { return x == value; }
};

int main() {
  constexpr std::size_t N = 1024 * 1024 * 100;
  constexpr int target = 99'000'000;
  std::vector<int> v(N);
  std::iota(v.begin(), v.end(), 0);

  auto t0 = std::chrono::high_resolution_clock::now();
  auto it = find_if_hardcoded(v.begin(), v.end(), target);
  auto t1 = std::chrono::high_resolution_clock::now();
  std::cout
      << "hardcoded "
      << std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0).count()
      << std::endl;
  if (it != v.end())
    std::cout << "found " << *it << " at position "
              << std::distance(v.begin(), it) << std::endl;

  t0 = std::chrono::high_resolution_clock::now();
  it = find_if_template(v.begin(), v.end(), predicate_template<int>{target});
  t1 = std::chrono::high_resolution_clock::now();
  std::cout
      << "template "
      << std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0).count()
      << std::endl;
  if (it != v.end())
    std::cout << "found " << *it << " at position "
              << std::distance(v.begin(), it) << std::endl;

  t0 = std::chrono::high_resolution_clock::now();
  it = find_if_template(v.begin(), v.end(),

                        [target](auto x) { return x == target; }

  );
  t1 = std::chrono::high_resolution_clock::now();
  std::cout
      << "template - lambda "
      << std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0).count()
      << std::endl;
  if (it != v.end())
    std::cout << "found " << *it << " at position "
              << std::distance(v.begin(), it) << std::endl;

  t0 = std::chrono::high_resolution_clock::now();
  it = find_if_virtual(v.begin(), v.end(),

                       predicate_virtual<int>{target}

  );
  t1 = std::chrono::high_resolution_clock::now();
  std::cout
      << "virtual "
      << std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0).count()
      << std::endl;
  if (it != v.end())
    std::cout << "found " << *it << " at position "
              << std::distance(v.begin(), it) << std::endl;
}
