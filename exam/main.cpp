#include "stack_pool.hpp"
#include <iostream>
#include <utility>
//useful function to check const iterator ! 
void foo(const stack_pool<int,std::size_t>& pool,std::size_t s2){
  for(auto i=pool.begin(s2);i!=pool.end(s2);++i){
  std::cout<<*i<<std::endl;

  }
}

int main() {

  //test capacity
  // stack_pool<std::vector<int>, std::size_t> pool{22};
  // auto s = pool.new_stack();
  // auto s2 = pool.new_stack();
  // for(int i=0;i<10;++i){
  //   std::vector<int> v{5,6,7,4};
  //   s=pool.push(v, s);
  //   s2=pool.push(v, s2);
  //   std::cout<<pool.capacity()<<"==";
  //   if(i%2)
  //     s=pool.pop(s);
  //   std::cout<<pool.capacity()<<"\n";
  // }
  
  
  //foo(pool,s);
  //foo(pool,s2);
  
  return 0;
}
