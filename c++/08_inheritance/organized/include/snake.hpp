#ifndef __ap_snake
#define __ap_snake

#include "animal.hpp"

/**
 * Base class for snakes. It specializes into DangerousSnake and
 * NonDangerousSnake. It is derived from class Animal and add a
 * boolean Snake#dangerous to specify if a type of snake is dangerous or
 * not.
 */
class Snake : public Animal {
  /** Is dangerous */
  bool dangerous;

 public:
  /**
   * Constructor. Takes all the arguments to construct an Animal plus
   * the additional boolean
   */
  Snake(const unsigned int a, const double w, const bool b);

  /**
   * Calls the default constructor for Animal, and the \p dangerous is
   * set to \p b
   */
  explicit Snake(const bool b);

  /**
   * Print details.
   */
  void info() const noexcept override;

  /**
   * Snake's call
   */
  void speak() const noexcept override;
};

/**
 * Specialization of class Snake. It specialize the constructors such
 * that the attribute \p dangerous is set to true
 */
class DangerousSnake : public Snake {
 public:
  DangerousSnake(const unsigned int a, const double w) : Snake{a, w, true} {}
  DangerousSnake() : Snake{true} {}
};

/**
 * Specialization of class Snake. It specialize the constructors such
 * that the attribute \p dangerous is set to false.
 */
class NonDangerousSnake : public Snake {
 public:
  NonDangerousSnake(const unsigned int a, const double w)
      : Snake{a, w, false} {}
  NonDangerousSnake() : Snake{false} {}
};

/**
 * Define the type Python
 */
struct Python : public NonDangerousSnake {};

/**
 * Aliasing Anaconda as DangerousSnake
 */
using Anaconda = DangerousSnake;

#endif
