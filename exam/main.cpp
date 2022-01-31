#include "stack_pool.hpp"
#include <iostream>




//usefull function to check const iterator ! 
void foo( stack_pool<int,std::size_t>& pool,std::size_t s2){
  for(auto i=pool.begin(s2);i!=pool.end(s2);++i){
    auto b=pool.begin(s2);
    i=b;
    std::cout<<*i<<std::endl;
  }
}

int main() {
  stack_pool<int, std::size_t> pool{22};
  auto s = pool.new_stack();
  auto s2 = pool.new_stack();
  s = pool.push(3, s);
  s2 = pool.push(2, s2);
  std::cout << pool.value(s2) << std::endl;
  s2 = pool.push(4, s2);
  std::cout << pool.value(s2) << std::endl;
  std::cout << "free: " << pool.get_free_nodes() << std::endl;
  s2 = pool.pop(s2);
  std::cout << pool.value(s2) << std::endl;
  std::cout << "free: " << pool.get_free_nodes() << std::endl;
  s2 = pool.push(6, s2);
  std::cout <<"s2: " <<s2<<std::endl;
  s2 = pool.push(7, s2);
  std::cout <<"s2: " <<s2<<std::endl;
  std::cout<<"s2 next: "<<pool.next(s2)<<std::endl;
 
  std::cout << pool.value(s2) << std::endl;
  std::cout << "free: " << pool.get_free_nodes() << std::endl;

  std::cout << "s: " << s << std::endl;
  std::cout << "s2: " << s2 << std::endl;


  std::cout<<"\nFOR RANGE LOOP\n";
  foo(pool,s2);
    
  return 0;
}
