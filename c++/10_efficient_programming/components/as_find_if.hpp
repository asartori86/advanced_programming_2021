#ifndef __find_if_hardcoded
#define __find_if_hardcoded

template <typename I, typename T>
// requires I is Iterator
// *I is of type T
I find_if_hardcoded(I first, const I last, const T& value) {
  // precondition [first, last)
  while (first != last && *first != value)
    ++first;
  return first;
}

template <typename I, typename P>
// requires I is Iterator
// *I is of type T
// P has operator(T) and returns a bool
I find_if_template(I first, const I last, P predicate) {
  // precondition [first, last)
  while (first != last && !predicate(*first))
    ++first;
  return first;
}

template <typename T>
struct predicate_base {
  virtual bool operator()(const T&) const = 0;
  virtual ~predicate_base() = default;
};

template <typename I, typename T>
// requires I is Iterator
// *I is compatible with predicate
I find_if_virtual(I first, const I last, const predicate_base<T>& predicate) {
  // precondition [first, last)
  while (first != last && !predicate(*first))
    ++first;
  return first;
}

#endif
