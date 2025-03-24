#ifndef GAUSSIANINTEGER_H
#define GAUSSIANINTEGER_H
#include "ComplexNumber.h"

/**
 * Derived class defining gaussian integers based on the complex number class.
 * Provides extended functionality like additional constructors & methods (like
 * divides & norm )
 */
class GaussianInteger : public ComplexNumber {
public:
  /**
   * No parameter constructor, creating an empty object
   */
  GaussianInteger();
  /**
   * Two parameter constructor, equivalent to the inherrited constructor
   * @param r The real compoenent
   * @param i The imaginary compoenet
   */
  GaussianInteger(int r, int i);
  /**
   * Copy constructor, takes other GaussianInteger and takes it's values
   * @param gausInt The other GaussianInteger
   */
  GaussianInteger(GaussianInteger &gausInt);
  /**
   * Destructor implementation
   */
  ~GaussianInteger() override;
  /**
   * Adds another complex number to this number
   * @param The other complex number
   * @return The summation of these two complex number
   */
  ComplexNumber *add(const ComplexNumber &other) override;
  /**
   * Multiplies another complex number to this number
   * @param The other complex number
   * @return The mulitplcation of these two complex number
   */
  ComplexNumber *multiply(const ComplexNumber &other) override;
  /**
   * Computes the conjugate
   * @return The conjugate
   */
  ComplexNumber *conjugate() override;
  /**
   * Checks if local instance of GaussianInteger divides the other
   * GaussianInteger
   * @param Another GaussianInteger
   * @return Boolean value if it divides
   */
  bool divides(const GaussianInteger &other);
  /**
   * Returns the normalized vector of the complex number
   * @return The norm of the complex number
   */
  int norm();
  /**
   * @param other The GaussianInteger to add to this object
   * @return this object added to [other].
   * Does not modify this object.
   *
   * @example
   * GaussianInteger one(1, 0);
   * GaussianInteger i(0, 1);
   * (one + i) produces the Gaussian Integer 1 + i
   */
  GaussianInteger operator+(const GaussianInteger &other) const;
  /**
   * @param other The GaussianInteger to multiply to this object
   * @return this object multiplied by [other]
   * Does not modify this object.
   *
   * @example
   * GaussianInteger one(1, 0);
   * GaussianInteger i(0, 1);
   * (one * i) produces the Gaussian Integer i (1 * i)
   */
  GaussianInteger operator*(const GaussianInteger &other) const;
  /**
   *
   * @param other The Gaussian integer to which this should be compared
   * @return true if and only if this object is equal to [other]
   * Does not modify this object.
   * @example
   * GaussianInteger one(1, 0);
   * GaussianInteger i(0, 1);
   * one == one is true, but one == i is false
   */
  bool operator==(const GaussianInteger &other) const;
  /**
   * @param os A reference to the ostream object
   * @param other The GaussianInteger being printed
   * @return The reference to the ostream object to allow for cout chaining
   * friend function
   *
   * @example
   * GaussianInteger two(2, 0);
   * std::cout << two << std::endl;
   * produces 2 + 0i
   */
  friend std::ostream &operator<<(std::ostream &os,
                                  const GaussianInteger &other);
};
#endif // GAUSSIANINTEGER_H
