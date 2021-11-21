#ifndef __ap_dog
#define __ap_dog

#include "animal.hpp"

/**
 * Specialization of class Animal. It simply overrides the function speak.
 */
class Dog : public Animal {
 public:
  /**
   * A dog usually says "Bau"
   */
  void speak() const noexcept override;
  /**
   * Default constructor is fine. It will call the default constructor
   * of Animal.
   */
  Dog() = default;

  /**
   * Delegating constructor to build an Animal{a,b}
   */
  Dog(const unsigned int a, const double d);
};

#endif
