#include <iostream>
#include <iterator>
#include <vector>
#include <utility>

template <typename T, typename N, typename S>
class _iterator {
  using stack_type = N;  // const std::size_t
  using stack_pool = S;  // const stack_pool<int,std::size_t>
  stack_type current;    // std::size_t
  stack_pool& pool;      // const stack_pool<int,std::size_t>&

 public:

  using value_type = T;  // const int
  using reference = value_type&;  // const int&
  using pointer = value_type*;    // const int*
  // using difference_type = stack_type; // chiedere al prof! 
  using iterator_category = std::forward_iterator_tag;

  _iterator(stack_pool& pool, stack_type x)
      : current{x}, pool{pool} {}  // take head as argument

  reference operator*() const {  // check for constantness
    return pool.value(current);
  }
  
  stack_type operator&() const {  // check for constantness
    return current;
  }

  _iterator& operator++() {  // pre-increment
    current = pool.next(current);
    return *this;
  }

  _iterator operator++(int) {  // post-increment
    auto tmp = *this;
    ++(*this);
    
    return tmp;
  }
  
  //_iterator(const _iterator& i): current{i.current},pool{i.pool} {}
  _iterator(const _iterator& i)= default;
  
  /* All the following functions assume only iterators originated
     from the same stack pool are compared */
  _iterator& operator=(const _iterator& x) {
    current = x.current;
    return *this;
  }
  
  friend bool operator==(const _iterator& x, const _iterator& y) {
    return x.current == y.current;
  }
  friend bool operator!=(const _iterator& x, const _iterator& y) {
    return !(x == y);
  }
};

template <typename T, typename N = std::size_t>
class stack_pool {
  struct node_t {
    T value;
    N next;
  };

  using stack_type = N;
  using value_type = T;
  using size_type = typename std::vector<node_t>::size_type;

  // Members
  std::vector<node_t> pool;
  stack_type free_nodes;  // at the beginning, it is empty

  node_t& node(stack_type x) noexcept { return pool[x - 1]; }
  const node_t& node(stack_type x) const noexcept { return pool[x - 1]; }

 public:
  stack_pool() : stack_pool{0} {};  // defaul ctor
  explicit stack_pool(size_type n) : pool{}, free_nodes{new_stack()} {
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

  auto begin(stack_type x) { return iterator{*this, x}; }
  auto end(stack_type) { return iterator{*this, end()}; }  // this is not a typo

  auto begin(stack_type x) const { return const_iterator{*this, x}; }
  auto end(stack_type) const { return const_iterator{*this, end()}; }

  auto cbegin(stack_type x) const { return const_iterator{*this, x}; }
  auto cend(stack_type) const { return const_iterator{*this, end()}; }

  stack_type new_stack() const { return end(); }  // return an empty stack

  void reserve(size_type n) { pool.reserve(n); }

  size_type capacity() const { return pool.capacity(); }

  bool empty(stack_type x) const { return x == end(); }

  stack_type end() const noexcept { return stack_type(0); }


  // T const & f() const {
  //   return something_complicated();
  // }
  // T & f() {
  //   return const_cast<T &>(std::as_const(*this).f());
  // }
  
  T& value(stack_type x) { 
    // what if x is empty??
    if (!empty(x))
      return node(x).value;
    else
      std::cout << "Trying to access value of a empty node" << std::endl;
    // Invoke dctor;
    exit(66);
  };

  const T& value(stack_type x) const {
    // what if x is empty??
    if (!empty(x))
      return node(x).value;
    else
      std::cout << "Trying to access value of a empty node" << std::endl;
    // Invoke dctor;
    exit(66);
  };

  stack_type& next(stack_type x) { return node(x).next; };
  const stack_type& next(stack_type x) const { return node(x).next; };
  
  void move_head(stack_type& to,stack_type& from){
    std::swap<stack_type>(next(to),from);
    std::swap<stack_type>(to,from);
    return;
  }
  
  template<typename X>
  stack_type _push(X&& val,stack_type head) {
    if (empty(free_nodes)) {
      pool.push_back(node_t{std::forward<X>(val), head});
      // pool.emplace_back(val, head); // just for fun
      return pool.size();
    } else {
      value(free_nodes)=std::forward<X>(val);
      move_head(free_nodes,head);
      return head;
    }
  }
  
  stack_type push(const T& val, stack_type head) {
    return _push(val,head);
  };

  stack_type push(T&& val, stack_type head) {
    return _push(std::move(val),head);
  }


  stack_type pop(stack_type x) {  // delete first node
    if (empty(x)) {
      std::cout << "Trying to pop from an empty stack" << std::endl;
      exit(66);
    }
    move_head(x,free_nodes);
    return x;
  };

  stack_type get_last(stack_type x) {
    auto first=begin(x);
    while(next(&first)!=end())      //  while(!next(first++)){}
      first++;
    return &first;
  }
  
  stack_type free_stack(stack_type x) {
    auto tmp = get_last(x);
    next(tmp)=free_nodes;
    free_nodes=x;
    return end();
  }  // free entire stack
  
  stack_type get_free_nodes() { return free_nodes; };  // only for debug
};
