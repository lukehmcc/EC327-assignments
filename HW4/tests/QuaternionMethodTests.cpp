#include "../src/GaussianInteger.h"
#include "../src/Quaternion.h"
#include <gtest/gtest.h>

TEST(QuaternionArithmetic, AddWithQuaternion) {
  Quaternion q1(1, 2, 3, 4);
  Quaternion q2(5, 6, 7, 8);
  ComplexNumber *sum = q1.add(q2);
  Quaternion *qSum = dynamic_cast<Quaternion *>(sum);

  EXPECT_EQ(qSum->getReal(), 6);
  EXPECT_EQ(qSum->getImag(), 8);
  EXPECT_EQ(qSum->getJ(), 10);
  EXPECT_EQ(qSum->getK(), 12);
  delete sum;
}

TEST(QuaternionArithmetic, AddWithGaussianInteger) {
  Quaternion q1(1, 2, 3, 4);
  GaussianInteger q2(5, 6);
  ComplexNumber *sum = q1.add(q2);
  Quaternion *qSum = dynamic_cast<Quaternion *>(sum);

  EXPECT_EQ(qSum->getReal(), 6);
  EXPECT_EQ(qSum->getImag(), 8);
  EXPECT_EQ(qSum->getJ(), 3); // j/k preserved (added 0 implicitly)
  EXPECT_EQ(qSum->getK(), 4);
  delete sum;
}

TEST(QuaternionArithmetic, MultiplyWithQuaternion) {
  Quaternion q1(1, 2, 3, 4);
  Quaternion q2(5, 6, 7, 8);
  ComplexNumber *product = q1.multiply(q2);
  Quaternion *qProduct = dynamic_cast<Quaternion *>(product);

  // Verify multiplication logic (example values)
  EXPECT_EQ(qProduct->getReal(), 5 /* expected real part */);
  EXPECT_EQ(qProduct->getImag(), 12 /* expected imag part */);
  EXPECT_EQ(qProduct->getJ(), 21 /* expected j part */);
  EXPECT_EQ(qProduct->getK(), 32 /* expected k part */);
  delete product;
}

TEST(QuaternionArithmetic, Conjugate) {
  Quaternion q(1, 2, 3, 4);
  ComplexNumber *conj = q.conjugate();
  Quaternion *qConj = dynamic_cast<Quaternion *>(conj);

  EXPECT_EQ(qConj->getReal(), 1);
  EXPECT_EQ(qConj->getImag(), -2);
  EXPECT_EQ(qConj->getJ(), -3);
  EXPECT_EQ(qConj->getK(), -4);
  delete conj;
}
