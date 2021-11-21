#include <ap_error.hpp>
#include <iostream>

struct Animal {
  unsigned int age;
  double weight;

  Animal(const unsigned int a, const double w) : age{a}, weight{w} {
    AP_ERROR(!(weight < 0)) << "invalid weight!\n";
  }

  Animal() : Animal{0, 0} {}  // delegating constructor

  virtual void speak() const = 0;  // pure virtual function ==> abstract class
  virtual void info() const noexcept {
    std::cout << "age:\t" << age << '\n' << "weight:\t" << weight << '\n';
  }

  virtual ~Animal() {}  // why? see file 03_virtual_destructor.cc
};

struct Dog : public Animal {
  void speak() const noexcept override { std::cout << "Bau\n"; }
  Dog() = default;
  Dog(const unsigned int a, const double d) : Animal{a, d} {}
};

struct Snake : public Animal {
  bool dangerous;
  Snake(const unsigned int a, const double w, const bool b)
      : Animal{a, w}, dangerous{b} {}
  explicit Snake(const bool b) : Animal{}, dangerous{b} {}
  void info() const noexcept override {
    Animal::info();
    std::cout << "dangerous:\t" << (dangerous ? "true" : "false") << std::endl;
  }
  void speak() const noexcept override { std::cout << "ssss\n"; }
};

void print_animal(const Animal& a) noexcept {
  std::cout << "throught ref\n";
  a.info();
  a.speak();
}

int main() {
  try {
    Snake s{true};
    s.info();
    s.speak();

    std::cout << std::endl;

    Animal* p = new Snake{1, 2.3, false};

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
