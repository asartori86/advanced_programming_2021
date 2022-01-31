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
  explicit stack_pool(size_type n)
      : pool{n}, free_nodes{1} {};  // reserve n nodes in the pool

  //   using iterator = ...;
  //   using const_iterator = ...;

  iterator begin(stack_type x);
  iterator end(stack_type);  // this is not a typo

  const_iterator begin(stack_type x) const;
  const_iterator end(stack_type) const;

  const_iterator cbegin(stack_type x) const;
  const_iterator cend(stack_type) const;

  stack_type new_stack();  // return an empty stack
  { return stack_type{0}; } 

  void reserve(size_type n);   // reserve n nodes in the pool
  size_type capacity() const;  // the capacity of the pool

  bool empty(stack_type x) const;

  stack_type end() const noexcept { return stack_type(0); }

  T& value(stack_type x);
  const T& value(stack_type x) const;

  stack_type& next(stack_type x);
  const stack_type& next(stack_type x) const;

  stack_type push(const T& val, stack_type head);
  stack_type push(T&& val, stack_type head);

  stack_type pop(stack_type x);  // delete first node

  stack_type free_stack(stack_type x);  // free entire stack
};