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

TEST(QuaternionMultiplication, BasicQuaternionMultiplication) {
  Quaternion q1(1, 2, 3, 4); // 1 + 2i + 3j + 4k
  Quaternion q2(5, 6, 7, 8); // 5 + 6i + 7j + 8k
  ComplexNumber *result = q1.multiply(q2);
  Quaternion *qResult = dynamic_cast<Quaternion *>(result);

  // 1*5 - 2*6 - 3*7 - 4*8 = 5-12-21-32 = -60 (real)
  // 1*6 + 2*5 + 3*8 - 4*7 = 6+10+24-28 = 12 (imag)
  // 1*7 - 2*8 + 3*5 + 4*6 = 7-16+15+24 = 30 (j)
  // 1*8 + 2*7 - 3*6 + 4*5 = 8+14-18+20 = 24 (k)
  EXPECT_EQ(qResult->getReal(), -60);
  EXPECT_EQ(qResult->getImag(), 12);
  EXPECT_EQ(qResult->getJ(), 30);
  EXPECT_EQ(qResult->getK(), 24);
  delete result;
}

TEST(QuaternionMultiplication, MultiplyWithGaussianInteger) {
  Quaternion q1(1, 2, 3, 4); // 1 + 2i + 3j + 4k
  GaussianInteger g(5, 6);   // 5 + 6i (j=k=0)
  ComplexNumber *result = q1.multiply(g);
  Quaternion *qResult = dynamic_cast<Quaternion *>(result);

  // 1*5 - 2*6 - 3*0 - 4*0 = 5-12 = -7 (real)
  // 1*6 + 2*5 + 3*0 - 4*0 = 6+10 = 16 (imag)
  // 1*0 - 2*0 + 3*5 + 4*0 = 15 (j)
  // 1*0 + 2*0 - 3*0 + 4*5 = 20 (k)
  EXPECT_EQ(qResult->getReal(), -7);
  EXPECT_EQ(qResult->getImag(), 16);
  EXPECT_EQ(qResult->getJ(), 39);
  EXPECT_EQ(qResult->getK(), 2);
  delete result;
}

TEST(QuaternionMultiplication, MultiplyWithIdentity) {
  Quaternion q1(2, 3, 4, 5);       // 2 + 3i + 4j + 5k
  Quaternion identity(1, 0, 0, 0); // 1 + 0i + 0j + 0k
  ComplexNumber *result = q1.multiply(identity);
  Quaternion *qResult = dynamic_cast<Quaternion *>(result);

  // Should return same quaternion
  EXPECT_EQ(qResult->getReal(), 2);
  EXPECT_EQ(qResult->getImag(), 3);
  EXPECT_EQ(qResult->getJ(), 4);
  EXPECT_EQ(qResult->getK(), 5);
  delete result;
}

TEST(QuaternionMultiplication, MultiplyWithZero) {
  Quaternion q1(1, 2, 3, 4);   // 1 + 2i + 3j + 4k
  Quaternion zero(0, 0, 0, 0); // 0 + 0i + 0j + 0k
  ComplexNumber *result = q1.multiply(zero);
  Quaternion *qResult = dynamic_cast<Quaternion *>(result);

  // Should return zero quaternion
  EXPECT_EQ(qResult->getReal(), 0);
  EXPECT_EQ(qResult->getImag(), 0);
  EXPECT_EQ(qResult->getJ(), 0);
  EXPECT_EQ(qResult->getK(), 0);
  delete result;
}

TEST(QuaternionMultiplication, NonCommutativeCheck) {
  Quaternion q1(1, 0, 1, 0); // 1 + i + j
  Quaternion q2(0, 1, 0, 0); // i
  ComplexNumber *result1 = q1.multiply(q2);
  ComplexNumber *result2 = q2.multiply(q1);
  Quaternion *qResult1 = dynamic_cast<Quaternion *>(result1);
  Quaternion *qResult2 = dynamic_cast<Quaternion *>(result2);

  // Verify non-commutativity: q1*q2 != q2*q1
  EXPECT_EQ(qResult1->getReal(), 0);
  EXPECT_EQ(qResult1->getImag(), 1);
  EXPECT_EQ(qResult1->getJ(), 0);
  EXPECT_EQ(qResult1->getK(), -1);

  EXPECT_EQ(qResult2->getReal(), 0);
  EXPECT_EQ(qResult2->getImag(), 1);
  EXPECT_EQ(qResult2->getJ(), 0);
  EXPECT_EQ(qResult2->getK(), 1);

  // Verify they're not equal
  EXPECT_FALSE(qResult1->getReal() == qResult2->getReal() &&
               qResult1->getImag() == qResult2->getImag() &&
               qResult1->getJ() == qResult2->getJ() &&
               qResult1->getK() == qResult2->getK());

  delete result1;
  delete result2;
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
