## Advanced Programming Exam 2021-22

### Deadline

The deadline for this project is **February 18, 2022**, at midnight. 21--23: oral sessions!

### How to submit

Fork the repository, then push on the master branch of the fork. I will not accept any other form (e.g., you send me a tar.gz). I will check just the master branch. 

### A pool of blazingly fast stacks

In this project, you must write a pool for fast stacks. The pool stores each node in a `std::vector<node_t>`. The "address" of a node is `1+idx`, where `idx` is the index where the node is stored in the vector. This trick allows us to use address `0` as `end`, so we can use unsigned integers type. The first node stored in the vector will be put at `idx == 0`, but it will be referenced as `1`.

```c++
  stack_pool<int, std::size_t> pool{};
  auto l = pool.new_stack();
  // l == pool.end() == std::size_t(0)
  l = pool.push(42,l);
  // l == std::size_t(1)
  pool.value(l) = 77;
```

The pool maintains a stack of free nodes, i.e., available positions in the vector. The `free_nodes` is empty at the beginning.

```c++
  stack_pool<int, std::size_t> pool{};
  auto l = pool.new_stack();
  l = pool.push(10,l); // l == std::size_t(1)
  l = pool.push(11,l); // l == std::size_t(2) <-- later, this node will be deleted
  
  auto l2 = pool.new_stack();
  l2 = pool.push(20,l2); // l2 == std::size_t(3)
  
  l = pool.pop(l); // that node is deleted, so it is added to free_nodes
  
  l2 = pool.push(21,l2); // l2 == std::size_t(2)
```

Here is the class template (without the `noexcept`s, remember to use them). The following functions **must be implemented**, and you don't have to change the names. Of course, you are free to implement more private and public methods. Remember to write a good class for iterators to avoid code duplication for `iterator` and `const_iterator`.

```c++
template <typename T, typename N = std::size_t>
class stack_pool{
  struct node_t{
    T value;
    N next;
  };
  std::vector<node_t> pool;
  using stack_type = N;
  using value_type = T;
  using size_type = typename std::vector<node_t>::size_type;
  stack_type free_nodes; // at the beginning, it is empty
  
  node_t& node(stack_type x) noexcept { return pool[x-1]; }
  const node_t& node(stack_type x) const noexcept { return pool[x-1]; }

  public:
  stack_pool();
  explicit stack_pool(size_type n); // reserve n nodes in the pool
    
  using iterator = ...;
  using const_iterator = ...;

  iterator begin(stack_type x);
  iterator end(stack_type ); // this is not a typo
    
  const_iterator begin(stack_type x) const;
  const_iterator end(stack_type ) const; 
  
  const_iterator cbegin(stack_type x) const;
  const_iterator cend(stack_type ) const;
    
  stack_type new_stack(); // return an empty stack

  void reserve(size_type n); // reserve n nodes in the pool
  size_type capacity() const; // the capacity of the pool

  bool empty(stack_type x) const;

  stack_type end() const noexcept { return stack_type(0); }

  T& value(stack_type x);
  const T& value(stack_type x);

  stack_type& next(stack_type x);
  const stack_type& next(stack_type x) const;

  stack_type push(const T& val, stack_type head);
  stack_type push(T&& val, stack_type head);
  
  stack_type pop(stack_type x); // delete first node

  stack_type free_stack(stack_type x); // free entire stack
};
```

Finally, there is an example of the usage of the iterators.

```c++
#include <cassert>
#include <algorithm> max_element, min_element

stack_pool<int> pool{22};
auto l1 = pool.new_stack();
// credits: pi as random number generator :)
l1 = pool.push(3, l1);
l1 = pool.push(1, l1);
l1 = pool.push(4, l1);
l1 = pool.push(1, l1);
l1 = pool.push(5, l1);
l1 = pool.push(9, l1);
l1 = pool.push(2, l1);
l1 = pool.push(6, l1);
l1 = pool.push(5, l1);
l1 = pool.push(3, l1);
l1 = pool.push(5, l1);
    
auto l2 = pool.new_stack();
l2 = pool.push(8, l2);
l2 = pool.push(9, l2);
l2 = pool.push(7, l2);
l2 = pool.push(9, l2);
l2 = pool.push(3, l2);
l2 = pool.push(1, l2);
l2 = pool.push(1, l2);
l2 = pool.push(5, l2);
l2 = pool.push(9, l2);
l2 = pool.push(9, l2);
l2 = pool.push(7, l2);

auto M = std::max_element(pool.begin(l1), pool.end(l1));
assert(*M == 9);

auto m = std::min_element(pool.begin(l2), pool.end(l2));
assert(*m == 1);

```

