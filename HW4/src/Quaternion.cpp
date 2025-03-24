#include "Quaternion.h"
#include "ComplexNumber.h"
#include "GaussianInteger.h"

/**
 * Constructs an Quaternion 0
 */
Quaternion::Quaternion() : GaussianInteger(), j(0), k(0) {}

/**
 * Constructs a Gaussian integer representing real + imag i
 * @example Quaternion ex(1, 3) produces the Gaussian Integer 1 + 3i.
 */
Quaternion::Quaternion(int r, int i, int j, int k)
    : GaussianInteger(r, i), j(j), k(k) {}

/**
 * Copy constructor - constructs a duplicate of [other]
 * @param other The Quaternion to duplicate
 * @example
 * Quaternion ex(1, 3);
 * Quaternion ex2(ex) results in ex2 being 1 + 3i as well.
 */
Quaternion::Quaternion(const Quaternion &otherQuaternion)
    : GaussianInteger(otherQuaternion.real, otherQuaternion.imag),
      j(otherQuaternion.getJ()), k(otherQuaternion.getK()) {}

/**
 * Adds another Quaternion to this number
 * @param The other Quanternion
 * @return The summation of these two Quanternion
 */
ComplexNumber *Quaternion::add(const ComplexNumber &other) {
  const Quaternion *otherQuat = dynamic_cast<const Quaternion *>(&other);

  if (otherQuat) {
    // Case 1: 'other' is a Quaternion → add all four components
    return new Quaternion(real + other.getReal(), imag + other.getImag(),
                          j + otherQuat->getJ(), k + otherQuat->getK());
  } else {
    // Case 2: 'other' is a GaussianInteger or ComplexNumber → default j/k to 0
    return new Quaternion(real + other.getReal(), imag + other.getImag(),
                          j, // j remains unchanged (adds 0 implicitly)
                          k  // k remains unchanged (adds 0 implicitly)
    );
  }
}
/**
 * Multiplies another Quanternion to this number
 * @param The other Quanternion
 * @return The mulitplcation of these two Quanternions
 */
ComplexNumber *Quaternion::multiply(const ComplexNumber &other) {
  const Quaternion *otherQuat = dynamic_cast<const Quaternion *>(&other);

  if (otherQuat) {
    // Case 1: 'other' is a Quaternion → add all four components
    return new Quaternion(real * other.getReal(), imag * other.getImag(),
                          j * otherQuat->getJ(), k * otherQuat->getK());
  } else {
    // Case 2: 'other' is a GaussianInteger or ComplexNumber → default j/k to 0
    return new Quaternion(real * other.getReal(), imag * other.getImag(),
                          j, // j remains unchanged (multiplies by 1 implicitly)
                          k  // k remains unchanged (multiplies by 1 implicitly)
    );
  }
}

/**
 * Returns the conjugate of the current quaternion.
 *
 * The conjugate of a quaternion q = w + xi + yj + zk is defined as:
 *
 * q* = w - xi - yj - zk
 *
 * The real part remains unchanged, and the signs of the imaginary components
 * are flipped.
 *
 * @return A new Quaternion that represents the conjugate of the current
 * quaternion.
 */
ComplexNumber *Quaternion::conjugate() {
  Quaternion *toReturn = new Quaternion(real, -imag, -j, -k);
  return toReturn;
}
/**
 * Prints the current quaternion in the format:
 *
 * w + xi + yj + zk
 *
 * Example output for a quaternion q = 3 + 2i - 4j + 0k:
 * "3 + 2i - 4j + 0k"
 */
std::ostream &operator<<(std::ostream &os, const Quaternion &other) {
  os << other.real << " + " << other.imag << "i" << " + " << other.j << "j"
     << " + " << other.k << "k";
  return os;
}
