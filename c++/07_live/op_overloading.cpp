#include "ap_error.hpp"
#include <chrono>
#include <iostream>
#include <memory>

#ifndef NDEBUG
#  define AP_NOEXCEPT
#else
#  define AP_NOEXCEPT noexcept
#endif

template <typename T>
class Matrix {
  std::size_t _rows;
  std::size_t _cols;
  std::unique_ptr<T[]> elem;

 public:
  Matrix(const std::size_t r, const std::size_t c)
      : _rows{r}, _cols{c}, elem{new T[_rows * _cols]} {
    std::cout << "custom ctor" << std::endl;
  }

  explicit Matrix(const std::size_t n) : Matrix{n, n} {}  // delegating ctor

  Matrix(const Matrix& x) : Matrix{x._rows, x._cols} {
    std::cout << "copy ctor" << std::endl;
    std::copy(x.elem.get(), x.elem.get() + _rows * _cols, elem.get());
  }

  Matrix& operator=(const Matrix& x) {
    elem.reset();              // release memory
    auto tmp = x;              // copy ctor
    (*this) = std::move(tmp);  // move assign.
    return *this;
  }

  Matrix(Matrix&& x) noexcept
      : _rows{x._rows}, _cols{x._cols}, elem{std::move(x.elem)} {
    std::cout << "move ctor" << std::endl;
  }

  Matrix& operator=(Matrix&&) noexcept = default;

  // Matrix& operator=(Matrix&& x) noexcept{
  //   _rows = x._rows;
  //   _cols = y._cols;
  //   elem = std::move(x.elem);
  // }
  T& operator[](const std::size_t i) noexcept { return elem[i]; }
  const T& operator[](const std::size_t i) const noexcept { return elem[i]; }

  T& operator()(const std::size_t i, const std::size_t j) AP_NOEXCEPT {
    AP_ASSERT_LT(i, _rows);
    AP_ASSERT_LT(j, _cols);
    return (*this)[i * _cols + j];
  }
  const T& operator()(const std::size_t i,
                      const std::size_t j) const AP_NOEXCEPT {
    AP_ASSERT_LT(i, _rows);
    AP_ASSERT_LT(j, _cols);
    return (*this)[i * _cols + j];
  }
  friend std::ostream& operator<<(std::ostream& os, const Matrix& m) {
    for (std::size_t i = 0; i < m._rows; ++i) {
      for (std::size_t j = 0; j < m._cols; ++j)
        os << m(i, j) << " ";
      os << std::endl;
    }
    return os;
  }

  Matrix& operator+=(const Matrix& b) {
    for (std::size_t i = 0; i < _rows * _cols; ++i)
      (*this)[i] += b[i];

    return *this;
  }

  friend Matrix operator+(Matrix&& a, const Matrix& b) {
    return std::forward<Matrix>(a += b);
  }

  friend Matrix operator+(const Matrix& a, const Matrix& b) {
    AP_ASSERT_EQ(a._rows, b._rows);
    AP_ASSERT_EQ(a._cols, b._cols);

    Matrix res{a._rows, a._cols};

    for (std::size_t i = 0; i < a._rows * a._cols; ++i)
      res[i] = a[i] + b[i];

    return res;
  }
};

int main() {
  constexpr std::size_t N{20'000};
  Matrix<int> m1{N};
  for (std::size_t i = 0; i < N * N; ++i) {
    m1[i] = 1;
  }

  // ...
  auto t0 = std::chrono::high_resolution_clock::now();
  auto res = m1 + m1 + m1 + m1 + m1 + m1 + m1 + m1 + m1 + m1;
  auto t1 = std::chrono::high_resolution_clock::now();

  auto t = std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0);
  std::cout << t.count() << std::endl;

  std::cout << res[10 & 63] << std::endl;
}
