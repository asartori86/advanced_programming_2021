#include "ap_error.hpp"
#include <chrono>
#include <iostream>
#include <memory>

#ifndef NDEBUG
#  define AP_NOEXCEPT
#else
#  define AP_NOEXCEPT noexcept
#endif

template <typename ET>
struct MatrixExpression{
  auto operator[](const std::size_t i)const noexcept{return static_cast<const ET&>(*this)[i]; }
  auto rows() const noexcept {return static_cast<const ET&>(*this).rows(); }
  auto cols() const noexcept {return static_cast<const ET&>(*this).cols(); }
};


template <typename T>
class Matrix {
  std::size_t _rows;
  std::size_t _cols;
  std::unique_ptr<T[]> elem;

 public:
  auto rows() const noexcept { return _rows; }
  auto cols() const noexcept { return _cols; }

  template <typename ET>
  Matrix(const MatrixExpression<ET>& e): Matrix{e.rows(), e.cols()} {
    for (std::size_t i=0; i < _rows*_cols; ++i)
      elem[i] = e[i];
  }

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

  //   friend Matrix operator+(const Matrix& a, const Matrix& b) {
  //     AP_ASSERT_EQ(a._rows, b._rows);
  //     AP_ASSERT_EQ(a._cols, b._cols);

  //     Matrix res{a._rows, a._cols};

  //     for (std::size_t i = 0; i < a._rows * a._cols; ++i)
  //       res[i] = a[i] + b[i];

  //     return res;
  //   }
};

template <typename L, typename R>
class MatrixSum :public MatrixExpression<MatrixSum<L,R>>{ //curiously recurring template pattern
  const L& l;
  const R& r;

 public:
  MatrixSum(const L& l, const R& r) : l{l}, r{r} {}
  auto operator[](const std::size_t i) const noexcept { return l[i] + r[i]; }
  auto rows() const noexcept {return l.rows();}
  auto cols() const noexcept {return l.cols();}
};

template <typename ET, typename T> 
auto operator+(const MatrixExpression<ET>& e, const Matrix<T>& b){
  return MatrixSum<MatrixExpression<ET>, Matrix<T>>{e,b};
}

template <typename ET, typename T> 
auto operator+(const Matrix<T>& b,const MatrixExpression<ET>& e){
  return MatrixSum<MatrixExpression<ET>, Matrix<T>>{e,b};
}

template <typename T>
auto operator+(const Matrix<T>& a, const Matrix<T>& b) {
  return MatrixSum<Matrix<T>, Matrix<T>>{a, b};
}

template <typename T>
Matrix<T> sum_10(const Matrix<T>& m0,
                 const Matrix<T>& m1,
                 const Matrix<T>& m2,
                 const Matrix<T>& m3,
                 const Matrix<T>& m4,
                 const Matrix<T>& m5,
                 const Matrix<T>& m6,
                 const Matrix<T>& m7,
                 const Matrix<T>& m8,
                 const Matrix<T>& m9) {
  Matrix<T> tmp{m0.rows(), m0.cols()};
  for (std::size_t i = 0; i < m0.rows() * m0.cols(); ++i)
    tmp[i] = m0[i] + m1[i] + m2[i] + m3[i] + m4[i] + m5[i] + m6[i] + m7[i] +
             m8[i] + m9[i];
  return tmp;
}

int main() {
  constexpr std::size_t N{20'000};
  Matrix<int> m1{N};
  for (std::size_t i = 0; i < N * N; ++i) {
    m1[i] = 1;
  }

  // ...
  auto t0 = std::chrono::high_resolution_clock::now();
  // do not use auto with expr templates!!!!
  Matrix<int> res = m1 + m1 + m1 + m1 + m1 + m1 + m1 + m1 + m1 + m1;
  // Matrix<int> res= sum_10(m1 , m1 , m1 , m1 , m1 , m1 , m1 , m1 , m1 , m1);
  ///
  auto t1 = std::chrono::high_resolution_clock::now();

  auto t = std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0);
  std::cout << t.count() << std::endl;

  std::cout << res[10 & 63] << std::endl;
}
