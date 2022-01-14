#include "catch.hpp"

#include "stack_pool.hpp"
#include <algorithm> // max_element, min_element

SCENARIO("getting confident with the addresses"){
  stack_pool<int, std::size_t> pool{16};
  auto l = pool.new_stack();

  REQUIRE( l == 0);
  l = pool.push(42,l);
  REQUIRE( l == std::size_t(1));
  

}

SCENARIO("basic operations on stack") {
  GIVEN("a generic pool") {
    stack_pool<int, std::size_t> pool{16};

    GIVEN("a new stack") {
      auto l = pool.new_stack();
      
      THEN("the stack is empty")
	REQUIRE(pool.empty(l));

      WHEN("we add one value") {
        l = pool.push(1, l);
        REQUIRE(pool.value(l) == 1);
      

	WHEN("we delete the only node") {
	  l = pool.pop(l);
	  THEN("the stack is empty again")
	    REQUIRE(pool.empty(l));

	  //empty stacks point to pool.end()
	  REQUIRE(l == pool.end());
	}
      }

      WHEN("we add two values") {
        l = pool.push(1, l);
        REQUIRE(pool.value(l) == 1);
        l = pool.push(2, l);

        REQUIRE(pool.value(l) == 2);

        l = pool.free_stack(l);
        REQUIRE(pool.empty(l) == true);
      }
    }
  }
}

SCENARIO("handling multiple stacks") {
  GIVEN("a simple pool") {
    stack_pool<int, uint16_t> pool{};
    WHEN("we create two stacks") {
      auto l1 = pool.new_stack();
      l1 = pool.push(3, l1);
      l1 = pool.push(2, l1);
      l1 = pool.push(1, l1);

      auto l2 = pool.new_stack();

      l2 = pool.push(4, l2);
      l2 = pool.push(5, l2);

      // scan l1
      auto tmp = l1;
      REQUIRE(pool.value(tmp) == 1);
      tmp = pool.next(tmp);
      REQUIRE(pool.value(tmp) == 2);
      tmp = pool.next(tmp);
      REQUIRE(pool.value(tmp) == 3);
      tmp = pool.next(tmp);
      REQUIRE(tmp == pool.end());

      // scan l2
      tmp = l2;
      REQUIRE(pool.value(tmp) == 5);
      tmp = pool.next(tmp);
      REQUIRE(pool.value(tmp) == 4);

      tmp = pool.next(tmp);
      REQUIRE(tmp == pool.end());
    }
  }
}

SCENARIO("using nodes of a deleted stack") {
  GIVEN("a stack") {
    stack_pool<int, uint16_t> pool{};
    auto l1 = pool.new_stack();
    l1 = pool.push(3, l1);
    l1 = pool.push(2, l1);
    l1 = pool.push(1, l1);

    auto capacity = pool.capacity();

    WHEN("we delete the stack") {
      l1 = pool.free_stack(l1);

      THEN("l1 is now empty") { REQUIRE(pool.empty(l1)); }

      WHEN("we create a new stack we use the old nodes") {
        auto l2 = pool.new_stack();

        l2 = pool.push(4, l2);
        l2 = pool.push(5, l2);

        auto tmp = l2;
        REQUIRE(pool.value(tmp) == 5);
        tmp = pool.next(tmp);
        REQUIRE(pool.value(tmp) == 4);

        tmp = pool.next(tmp);
        REQUIRE(tmp == pool.end());

        THEN("since we added just two nodes, the capacity didn't change")
        REQUIRE(pool.capacity() == capacity);
      }
    }
  }
}

SCENARIO("using iterators"){
  GIVEN("two stacks"){
    stack_pool<int, uint16_t> pool{};
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

    THEN("find the max on l1"){
      auto m = std::max_element(pool.begin(l1), pool.end(l1));
      REQUIRE(*m == 9);
    }

    THEN("find the min on l2"){
      auto m = std::min_element(pool.begin(l2), pool.end(l2));
      REQUIRE(*m == 1);
    }
    
    
  }

}
