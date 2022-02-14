#include "ap_error.hpp"
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>

template <typename T, typename N, typename S>
class _iterator {
  using stack_type = N;  // const std::size_t
  using stack_pool = S;  // const stack_pool<int,std::size_t>
  stack_type current;    // std::size_t
  stack_pool* pool;      // const stack_pool<int,std::size_t>& //evitare referenza qui ! meglio stack_pool*
                         // Chiedere al prof se pool va bene
 public:
  using value_type = T;           // const int
  using reference = value_type&;  // const int&
  using pointer = value_type*;    // const int*
  // using difference_type = stack_type; // chiedere al prof!
  using iterator_category = std::forward_iterator_tag;

  _iterator(stack_pool& pool, stack_type x)
      : current{x}, pool{&pool} {}  // take head as argument

  _iterator(const _iterator& i) = default;

  /* All the following functions assume only iterators originated
   from the same stack pool are compared */
  // Chidere al prof
  _iterator& operator=(const _iterator& x) noexcept {
    current = x.current;
    return *this;
  }

  reference operator*() const {  // check for constantness
    return pool->value(current);
  }

  // Chiedere al prof
  stack_type operator&() const noexcept {  // check for constantness
    return current;
  }

  _iterator& operator++() noexcept {  // pre-increment
    current = pool->next(current);
    return *this;
  }

  _iterator operator++(int) noexcept {  // post-increment
    auto tmp = *this;
    ++(*this);
    return tmp;
  }

  friend bool operator==(const _iterator& x, const _iterator& y) noexcept {
    return x.current == y.current;
  }
  friend bool operator!=(const _iterator& x, const _iterator& y) noexcept {
    return !(x == y);
  }
};

template <typename T, typename N = std::size_t>
class stack_pool {

  struct node_t {
    T value;
    N next;
    
    explicit node_t(T value, N next) noexcept : value{value}, next{next} {}
  };

  using stack_type = N;
  using value_type = T;
  using size_type = typename std::vector<node_t>::size_type;

  // Members
  std::vector<node_t> pool;
  stack_type free_nodes;  // at the beginning, it is empty

  node_t& node(const stack_type x) noexcept { return pool[x - 1]; }
  const node_t& node(const stack_type x) const noexcept { return pool[x - 1]; }

 public:
  stack_pool() noexcept : stack_pool{0} {};  // defaul ctor
  // Chiedere al prof Can I place noexcept?

  explicit stack_pool(const size_type n) : pool{}, free_nodes{new_stack()} {
    reserve(n);
  };  // reserve n nodes in the pool

  stack_pool(const stack_pool&) = default;
  stack_pool(stack_pool&&) = default;

  stack_pool& operator=(const stack_pool&) = default;
  stack_pool& operator=(stack_pool&&) = default;

  using iterator =
      _iterator<value_type, stack_type, stack_pool<value_type, stack_type>>;
  using const_iterator = _iterator<const value_type,
                                   stack_type,
                                   const stack_pool<value_type, stack_type>>;

  auto begin(const stack_type x) {
    /**
       Returns an iterator pointing to the top element in the stack.
   */
    return iterator{*this, x};
  }
  auto end(stack_type) {
    /**
       Returns an iterator pointing the top of an empty stack.
    */
    return iterator{*this, end()};
  }  // this is not a typo

  auto begin(const stack_type x) const {
    /**
       Returns a const iterator pointing to the top element in the stack.
   */

    return const_iterator{*this, x};
  }
  auto end(stack_type) const {
    /**
       Returns a const iterator pointing the top of an empty stack.
    */
    return const_iterator{*this, end()};
  }

  auto cbegin(const stack_type x) const {
    /**
       Returns a const iterator pointing to the top element in the stack.
    */
    
    return const_iterator{*this, x}; 
  }
  
  auto cend(stack_type) const {
    /**
       Returns a const iterator pointing the top of an empty stack.
    */
    return const_iterator{*this, end()};
  }

  stack_type new_stack() const noexcept {
    /** 
	Create new empty stack.
    */
    return end();
  }  // return an empty stack

  void reserve(const size_type n) {
    /**
       Request that stack pool capacity be at least enough to contain n elements. 
     */
    pool.reserve(n);
  }
  
  size_type capacity() const noexcept {
    /**
       Return size of the storage space currently allocated for the stack pool, expressed in terms of nodes.
     */
    return pool.capacity();
  }

  bool empty(const stack_type x) const noexcept {
    /**
       Returns whether the stack is empty.
     */
    return x == end(); 
  }

  stack_type end() const noexcept {
    /**
       Returns top of empty stack.
     */
    return stack_type(0);
  }

  T& value(const stack_type x) {
    /**
       Returns a reference to the value contained in the of the stack.
    */
    AP_ERROR(!empty(x)) << "Trying to get value from an invalid stack\n"
                        << std::endl;
    return node(x).value;
  }

  const T& value(const stack_type x) const {
    /**
       Returns a const reference to the value contained in the of the stack.
    */
    AP_ERROR(!empty(x)) << "Trying to get value from an invalid stack\n"
                        << std::endl;
    return node(x).value;
  }

  stack_type& next(const stack_type x) noexcept {
    /**
       Return a reference to the index of the next element on the stack.
     */
    return node(x).next;
  };
  const stack_type& next(const stack_type x) const noexcept {
    /**
       Return a const reference to the index of the next element on the stack.
     */
    return node(x).next;
  };

 private:
  void move_head(stack_type& to, stack_type& from) noexcept {
    std::swap<stack_type>(next(to), from);
    std::swap<stack_type>(to, from);
    return;
  }

  template <typename X>
  stack_type _push(X&& val, stack_type head) {
    if (empty(free_nodes)) {
      pool.emplace_back(val, head);  // just for fun
      return pool.size();
    } else {
      value(free_nodes) = std::forward<X>(val);
      move_head(free_nodes, head);
      return head;
    }
  }

  stack_type get_last(const stack_type x) const noexcept {
    auto first = begin(x);
    while (next(&first) != end())  //  while(!next(first++)){},
      ++first;
    return &first;
  }

 public:
  stack_type push(const T& val, stack_type head) {
    /**
       Insert element on the top of the stack.
    */
    return _push(val, head); 
  }

  stack_type push(T&& val, stack_type head) {
    /**
       Insert element on the top of the stack using R-value ref.
    */    
    return _push(std::move(val), head);
  }

  stack_type pop(stack_type x) {  // delete first node
    /**
       Remove the element on the top of the stack
     */
    AP_ERROR(!empty(x)) << "Trying to pop from an empty stack error \n"
                        << std::endl;
    move_head(x, free_nodes);
    return x;
  };

  stack_type free_stack(stack_type x) noexcept {
    /**
       Free entire stack.
     */
    if (empty(x))
      return x;

    auto tmp = get_last(x);
    next(tmp) = free_nodes;
    free_nodes = x;
    return end();
  }  // free entire stack


};
