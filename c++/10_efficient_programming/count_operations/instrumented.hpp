// adapted from Alexander Stepanov: Efficient Programming with Components

#ifndef INSTRUMENTED_H
#define INSTRUMENTED_H
#include <algorithm>
#include <utility>

struct instrumented_base {
  enum operations {
    n,
    copy_ctor,
    copy_assign,
    move_ctor,
    move_assign,
    default_ctor,
    dtor,
    equality,
    comparison
  };

  static constexpr std::size_t n_ops = 9;
  static double counts[n_ops];
  static const char* counter_names[n_ops];
  static void initialize(std::size_t i) {
    std::fill(counts, counts + n_ops, 0.0);
    counts[n] = i;
  }
  static void print_summary();
  static void print_header();
};

template <typename T>
// T is Semiregualr or Regular or TotallyOrdered
struct instrumented : instrumented_base {
  using base = instrumented_base;
  T value;
  // Conversions from T and to T:
  instrumented(const T& x) : value{x} {}
  explicit operator T() const { return value; }

  template <typename U>
  instrumented(const instrumented<U>& x) : value{x.value} {}

  // Semiregular:
  instrumented(const instrumented& x) : value{x.value} { ++counts[copy_ctor]; }
  instrumented(instrumented&& x) : value{std::move(x)} { ++counts[move_ctor]; }
  instrumented() { ++counts[default_ctor]; }
  ~instrumented() { ++counts[dtor]; }

  instrumented& operator=(const instrumented& x) {
    ++counts[copy_assign];
    value = x.value;
    return *this;
  }

  instrumented& operator=(instrumented&& x) {
    ++counts[move_assign];
    value = std::move(x.value);
    return *this;
  }

  // Regular
  friend bool operator==(const instrumented& x, const instrumented& y) {
    ++counts[equality];
    return x.value == y.value;
  }
  friend bool operator!=(const instrumented& x, const instrumented& y) {
    return !(x == y);
  }
  // TotallyOrdered
  friend bool operator<(const instrumented& x, const instrumented& y) {
    ++counts[comparison];
    return x.value < y.value;
  }
  friend bool operator>(const instrumented& x, const instrumented& y) {
    return y < x;
  }
  friend bool operator<=(const instrumented& x, const instrumented& y) {
    return !(y < x);
  }
  friend bool operator>=(const instrumented& x, const instrumented& y) {
    return !(x < y);
  }

  // needed by std::iota
  instrumented& operator++() {
    ++value;
    return *this;
  }
};

#endif
