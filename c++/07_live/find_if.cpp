#include <chrono>
#include <iostream>
#include <vector>

template <typename I, typename T>
// I is bidirectional iterator
I find(I first, I last, T value) {
  if (first == last)
    return last;

  while (first != last && *first != value)
    ++first;
  return first;

  // sentinel

  --last;
  auto tmp = std::move(*last);
  if (tmp == value)
    return last;
  *last = value;

  while (*first != value)
    ++first;

  *last = std::move(tmp);

  if (first == last)
    return ++last;

  return first;
}

template <typename T>
int bar(T x) {
  return *x + 76;
}

template <typename T>
void foo(T x) {
  std::cout << (bar(x) & 63) << std::endl;
}
int main() {
  std::vector<int> v;
  for (auto i = 0; i < 1'000'000'001; ++i)
    v.emplace_back(i);

  auto t0 = std::chrono::high_resolution_clock::now();
  auto x = find(v.begin(), v.end(), 834'794'723);
  auto t1 = std::chrono::high_resolution_clock::now();

  auto t = std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0);
  std::cout << t.count() << std::endl;

  // foo(x);

  if (x == v.end())
    std::cout << "not found" << std::endl;
  else
    std::cout << "found " << *x << std::endl;
}
