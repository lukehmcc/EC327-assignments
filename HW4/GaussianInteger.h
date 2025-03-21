#ifndef GAUSSIANINTEGER_H
#define GAUSSIANINTEGER_H
#include "ComplexNumber.h"

/**
 * Derived class defining gaussian integers based on the complex number class.
 * Provides extended functionality like additional constructors & methods (like
 * divides & norm )
 */
class GaussianInteger : ComplexNumber {
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
};
#endif // GAUSSIANINTEGER_H
