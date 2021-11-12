#include "instrumented.hpp"
#include <cstddef>
#include <iostream>
#include <memory>
#include <utility>
#include <vector>
template <typename T, typename Allocator = std::allocator<T>>
class vector {
  T* data{nullptr};
  std::size_t _size{0};
  std::size_t _capacity{0};
  Allocator allocator;

  void check_capacity() {
    if (_size < _capacity)
      return;
    if (_size == 0)
      reserve(8);  // _size == _capacity
    // _size != 0
    else
      reserve(_size * 2);
  }

  template <typename X>
  void _push_back(X&& x) {
    check_capacity();
    data[_size] = std::forward<X>(x);
    ++_size;
  }

  void clean_data() {
    for (std::size_t i{0}; i < _size; ++i)
      traits_alloc::destroy(allocator, data + i);

    traits_alloc::deallocate(allocator, data, _capacity);
  }

  void move_data_to(T* tmp) {
    // std::uninitialized_move(data, data+_size, tmp);
    for (std::size_t i{0}; i < _size; ++i)
      traits_alloc::construct(allocator, tmp + i, std::move(data[i]));

    clean_data();
    data = tmp;
  }

 public:
  using traits_alloc = std::allocator_traits<Allocator>;
  vector() = default;
  ~vector() {
    if (data)
      clean_data();
  }

  vector(Allocator a) : allocator{std::move(a)} {}

  void reserve(std::size_t n) {
    auto tmp = traits_alloc::allocate(allocator, n);  // raw memory
    move_data_to(tmp);
    _capacity = n;
  }

  void push_back(const T& x) { _push_back(x); }

  void push_back(T&& x) { _push_back(std::move(x)); }

  template <typename... Types>
  void emplace_back(Types&&... args) {
    check_capacity();
    traits_alloc::construct(allocator, data + _size,
                            T{std::forward<Types>(args)...});
    ++_size;
  }

  auto size() const { return _size; }
  auto capacity() const { return _capacity; }
};

int main() {
  using value_type = instrumented<int>;
  std::vector<value_type> v;
  value_type::initialize(1);
  for (auto i = 0; i < 9; ++i) {
    v.emplace_back(i);
    std::cout << v.capacity() << ", " << v.size() << std::endl;
  }

  value_type::print_summary();

  // std::pair<int, double> p;
  // p.first = 7;
  // p.second = 9.9;
  // vector<std::pair<int,int>> vp;
  // vp.push_back(std::make_pair<int,int>(3,4));
  // vp.push_back(std::pair<int,int>(3,4));
  // vp.push_back({3,4});

  // vp.emplace_back(3,4);
}
