#include "GaussianInteger.h"
#include "ComplexNumber.h"

/**
 * Constructs an GaussianInteger 0
 */
GaussianInteger::GaussianInteger() : ComplexNumber(0, 0) {}

/**
 * Constructs a Gaussian integer representing real + imag i
 * @example GaussianInteger ex(1, 3) produces the Gaussian Integer 1 + 3i.
 */
GaussianInteger::GaussianInteger(int r, int i) : ComplexNumber(r, i) {}

/**
 * Copy constructor - constructs a duplicate of [other]
 * @param other The GaussianInteger to duplicate
 * @example
 * GaussianInteger ex(1, 3);
 * GaussianInteger ex2(ex) results in ex2 being 1 + 3i as well.
 */
GaussianInteger::GaussianInteger(GaussianInteger &otherGaussianInteger)
    : ComplexNumber(otherGaussianInteger.real, otherGaussianInteger.imag) {}

/**
 * Adds another complex number to this number
 * @param The other complex number
 * @return The summation of these two complex number
 */
ComplexNumber *GaussianInteger::add(const ComplexNumber &other) {
  ComplexNumber *toReturn =
      new GaussianInteger(real + other.getReal(), imag + other.getImag());
  return toReturn;
}
/**
 * Multiplies another complex number to this number
 * @param The other complex number
 * @return The mulitplcation of these two complex number
 */
ComplexNumber *GaussianInteger::multiply(const ComplexNumber &other) {
  ComplexNumber *toReturn =
      new GaussianInteger(real * other.getReal(), imag * other.getImag());
  return toReturn;
}
/**
 * Computes the conjugate
 * @return The conjugate
 */
ComplexNumber *GaussianInteger::conjugate() {
  ComplexNumber *toReturn = new GaussianInteger(real, -imag);
  return toReturn;
}
/**
 * @param other The GaussianInteger by which to divide this object
 * @return true if and only if this object divides by [other]
 * (or, in other words, other is a factor of this object)
 * @example 1
 * GaussianInteger four(4, 0);
 * GaussianInteger two(2, 0);
 * four.divides(two) is true, because 2*2=4
 *
 * @example 2
 * GaussianInteger two(2, 0); // i.e., 2 + 0i
 * GaussianInteger onePlusI(1, 1); // i.e., 1 + i
 * two.divides(onePlusI) is true because (1 + i) * (1 - i) == 2
 *
 * @example 3
 * GaussianInteger two(2, 0); // i.e., 2 + 0i
 * GaussianInteger twoPlusI(2, 1); // i.e., 2 + i
 * two.divides(twoPlusI) is false because 2 does not divide 2 + i
 */
bool GaussianInteger::divides(const GaussianInteger &other) {
  int a = real;
  int b = imag;
  int c = other.getReal();
  int d = other.getImag();
  int denom = c * c + d * d;
  bool firstEquationTrue = ((a * c + b * d) % denom == 0) ? true : false;
  bool secondEquationTrue = ((b * c - a * d) % denom == 0) ? true : false;
  return firstEquationTrue && secondEquationTrue;
}
/**
 * Returns the normalized vector of the complex number
 * @return The norm of the complex number
 */
int GaussianInteger::norm() { return real * real + imag * imag; }
