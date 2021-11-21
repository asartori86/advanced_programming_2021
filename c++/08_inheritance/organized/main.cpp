#include "dog.hpp"
#include "helper_functions.hpp"
#include "snake.hpp"
#include <iostream>

int main() {
  try {
    Python s;
    s.info();
    s.speak();

    std::cout << std::endl;

    // Animal* p = new DangerousSnake{1, 2.3};
    Animal* p = new Anaconda{1, 2.3};

    std::cout << "through pointer\n";
    p->info();
    p->speak();

    delete p;

    std::cout << std::endl;

    print_animal(s);

    return 0;
  } catch (std::runtime_error& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
}
