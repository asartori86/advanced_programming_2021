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
  stack_pool<int, std::size_t> pool{22};
  auto s = pool.new_stack();
  auto s2 = pool.new_stack();
  s = pool.push(9, s);
  s2 = pool.push(22, s2);
  s2 = pool.push(333, s2);
  s2 = pool.push(444, s2);
  s2 = pool.push(555, s2);
  s2 = pool.push(6, s2);
  s = pool.push(9, s);
  s = pool.push(9, s);
  s = pool.pop(s);
  s2 = pool.pop(s2);
  s2 = pool.push(7, s2);
  std::cout << pool.value(s2) << std::endl;
  s2 = pool.push(4, s2);
  std::cout << pool.value(s2) << std::endl;
  std::cout << "free: " << pool.get_free_nodes() << std::endl;
  
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
  auto iter =  pool.begin(s2);

  std::cout<<"Iter value: "<<s2<<"\n";
  std::cout<<"get_current_first"<<pool.get_last(s2)<<"\n";
  std::cout<<"\nFOR RANGE LOOP\n";
  foo(pool,s2);
  s2 =pool.free_stack(s2);
  std::cout <<"is empty?"<<pool.empty(s2)<<"\n";
  std::cout <<"s2: " <<s2<<"\n";
  //auto i=std::move(iter);
  return 0;
}
