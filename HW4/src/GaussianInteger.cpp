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
 * Default destructor override for GaussianInteger
 */
GaussianInteger::~GaussianInteger() {}
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
  int newReal = (real * other.getReal()) - (imag * other.getImag());
  int newImag = (real * other.getImag()) + (imag * other.getReal());
  return new GaussianInteger(newReal, newImag);
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
  int denom = (c * c) + (d * d);
  int num1 = a * c + b * d;
  int num2 = b * c - a * d;
  bool firstEquationTrue = (num1 % denom == 0) ? true : false;
  bool secondEquationTrue = (num2 % denom == 0) ? true : false;
  return firstEquationTrue && secondEquationTrue;
}
/**
 * Returns the normalized vector of the complex number
 * @return The norm of the complex number
 */
int GaussianInteger::norm() { return real * real + imag * imag; }

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
GaussianInteger GaussianInteger::operator+(const GaussianInteger &other) const {
  // Create a non-const copy of the current object so we can add to it
  GaussianInteger *tempThis = new GaussianInteger(real, imag);
  ComplexNumber *toReturn = tempThis->add(other);
  delete tempThis;
  return GaussianInteger(toReturn->getReal(), toReturn->getImag());
}
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
GaussianInteger GaussianInteger::operator*(const GaussianInteger &other) const {
  GaussianInteger *tempThis = new GaussianInteger(real, imag);
  ComplexNumber *toReturn = tempThis->multiply(other);
  delete tempThis;
  return GaussianInteger(toReturn->getReal(), toReturn->getImag());
}
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
bool GaussianInteger::operator==(const GaussianInteger &other) const {
  if (real == other.getReal() && imag == other.getImag()) {
    return true;
  } else {
    return false;
  }
}
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
std::ostream &operator<<(std::ostream &os, const GaussianInteger &other) {
  os << other.real << (other.imag >= 0 ? " + " : " - ") << std::abs(other.imag)
     << "i";
  return os;
}
