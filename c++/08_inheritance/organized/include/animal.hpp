#ifndef __ap__animal
#define __ap__animal

/**
 * Base class for animals. Each new animal should derive from this
 * class and override \p speak() which is pure virtual.
 */
class Animal {
  /** animal's age */
  unsigned int age;

  /** animal's weight */
  double weight;

 public:
  /**
   * Animal Constructor. Takes \p a for the age and \p w for the
   * weight.
   */
  Animal(const unsigned int a, const double w);

  /**
   * Deafult constructor. Set all attributes to zero.
   */
  Animal();

  /**
   * print on stdout the animal's call
   */
  virtual void speak() const = 0;

  /**
   * print animal's details
   */
  virtual void info() const noexcept;

  /**
   * Destructor. It does anything but is set virtual to ensure proper
   * cleanup of the data that will be defined in the derived classes.
   */
  virtual ~Animal() {}
};

#endif
