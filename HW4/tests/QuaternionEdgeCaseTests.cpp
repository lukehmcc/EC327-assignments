#include "../src/Quaternion.h"
#include <gtest/gtest.h>

TEST(QuaternionEdgeCases, MultiplyWithZero) {
  Quaternion q1(1, 2, 3, 4);
  Quaternion q2(0, 0, 0, 0);
  ComplexNumber *product = q1.multiply(q2);
  Quaternion *qProduct = dynamic_cast<Quaternion *>(product);

  EXPECT_EQ(qProduct->getReal(), 0);
  EXPECT_EQ(qProduct->getImag(), 0);
  EXPECT_EQ(qProduct->getJ(), 0);
  EXPECT_EQ(qProduct->getK(), 0);
  delete product;
}
