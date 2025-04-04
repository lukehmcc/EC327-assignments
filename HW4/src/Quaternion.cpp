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
    // Case 1: Both are Quaternions
    int w1 = real, x1 = imag, y1 = j, z1 = k;
    int w2 = other.getReal(), x2 = other.getImag();
    int y2 = otherQuat->getJ(), z2 = otherQuat->getK();

    int newReal = w1 * w2 - x1 * x2 - y1 * y2 - z1 * z2;
    int newImag = w1 * x2 + x1 * w2 + y1 * z2 - z1 * y2;
    int newJ = w1 * y2 - x1 * z2 + y1 * w2 + z1 * x2;
    int newK = w1 * z2 + x1 * y2 - y1 * x2 + z1 * w2;

    return new Quaternion(newReal, newImag, newJ, newK);
  } else {
    // Case 2: Second is complex number
    int w1 = real, x1 = imag, y1 = j, z1 = k;
    int w2 = other.getReal(), x2 = other.getImag();
    int y2 = 0, z2 = 0;

    int newReal = w1 * w2 - x1 * x2 - y1 * y2 - z1 * z2;
    int newImag = w1 * x2 + x1 * w2 + y1 * z2 - z1 * y2;
    int newJ = w1 * y2 - x1 * z2 + y1 * w2 + z1 * x2;
    int newK = w1 * z2 + x1 * y2 - y1 * x2 + z1 * w2;

    return new Quaternion(newReal, newImag, newJ, newK);
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
  os << other.real << (other.imag >= 0 ? " + " : " - ") << std::abs(other.imag)
     << "i" << (other.j >= 0 ? " + " : " - ") << std::abs(other.j) << "j"
     << (other.k >= 0 ? " + " : " - ") << std::abs(other.k) << "k";
  return os;
}
