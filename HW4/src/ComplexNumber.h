#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H
#include <iostream>
/**
 * Represents a complex number with real and imaginary components.
 * Provides basic arithmetic operations such as addition, multiplication, and
 * conjugation.
 */
class ComplexNumber {
protected:
  int real;
  int imag;

public:
  /**
   * Constructor to initialize the complex number
   * @param r The real compoenent
   * @param i The imaginary compoenent
   */
  ComplexNumber(const int r, const int i) : real(r), imag(i) {}
  /**
   * Virtual destructor
   */
  virtual ~ComplexNumber() {}
  /**
   * Returns the real compoenent
   * @return The real component as a integer
   */
  int getReal() const { return real; }
  /**
   * Return the imaginary compoenent
   * @return The imaginary component as an integer
   */
  int getImag() const { return imag; }
  /**
   * Adds another complex number to this number
   * Virtual funciton which must be defined in derived class
   * @param The other complex number
   * @return The summation of these two complex number
   */
  virtual ComplexNumber *add(const ComplexNumber &other) = 0;
  /**
   * Multiplies another complex number to this number
   * Virtual funciton which must be defined in derived class
   * @param The other complex number
   * @return The mulitplcation of these two complex number
   */
  virtual ComplexNumber *multiply(const ComplexNumber &other) = 0;
  /**
   * Computes the conjugate
   * Virual funciton which must be defined in the derived class
   * @return The conjugate
   */
  virtual ComplexNumber *conjugate() = 0;
  /**
   * Prints the complex number in a formatted manner.
   * The output format is "a + bi" or "a - bi", where `a` is the real part and
   * `b` is the absolute value of the imaginary part.
   */
  void print() {
    std::cout << real << (imag >= 0 ? " + " : " - ") << std::abs(imag) << "i"
              << std::endl;
  }
};
#endif
