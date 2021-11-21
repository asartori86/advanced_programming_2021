#include <ap_error.hpp>
#include <iostream>

class Animal {
  unsigned int age;
  double weight;

 public:
  Animal(const unsigned int a, const double w) : age{a}, weight{w} {
    AP_ERROR_GE(weight, 0) << "invalid weight!\n";
  }

  Animal() : Animal{0, 0} {}  // delegating constructor

  virtual void speak() const = 0;
  virtual void info() const noexcept {
    std::cout << "age:\t" << age << '\n' << "weight:\t" << weight << '\n';
  }

  virtual ~Animal() {}
};

class Dog : public Animal {
 public:
  void speak() const noexcept override { std::cout << "Bau\n"; }
  Dog() = default;
  Dog(const unsigned int a, const double d) : Animal{a, d} {}
};

class Snake : public Animal {
  bool dangerous;

 public:
  Snake(const unsigned int a, const double w, const bool b)
      : Animal{a, w}, dangerous{b} {}
  explicit Snake(const bool b) : Animal{}, dangerous{b} {}
  void info() const noexcept override {
    Animal::info();
    std::cout << "dangerous:\t" << (dangerous ? "true" : "false") << std::endl;
  }
  void speak() const noexcept override { std::cout << "ssss\n"; }
};

class DangerousSnake : public Snake {
 public:
  DangerousSnake(const unsigned int a, const double w) : Snake{a, w, true} {}
  DangerousSnake() : Snake{true} {}
};

class NonDangerousSnake : public Snake {
 public:
  NonDangerousSnake(const unsigned int a, const double w)
      : Snake{a, w, false} {}
  NonDangerousSnake() : Snake{false} {}
};

struct Python : public NonDangerousSnake {};

using Anaconda = DangerousSnake;

void print_animal(const Animal& a) noexcept {
  a.info();
  a.speak();

  // dynamic_cast is used to know the real type of the object
  if (dynamic_cast<const DangerousSnake*>(&a))
    std::cout << "call 911...\n";
}

int main() {
  try {
    Python s;
    print_animal(s);

    std::cout << std::endl;

    // Animal* p = new DangerousSnake{1, 2.3};
    Animal* p = new Anaconda{1, 2.3};

    print_animal(*p);
    delete p;

    return 0;
  } catch (std::runtime_error& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
}
