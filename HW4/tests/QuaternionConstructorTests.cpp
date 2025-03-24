#include "../src/Quaternion.h"
#include <gtest/gtest.h>

TEST(QuaternionConstructors, DefaultConstructor) {
  Quaternion q;
  EXPECT_EQ(q.getReal(), 0);
  EXPECT_EQ(q.getImag(), 0);
  EXPECT_EQ(q.getJ(), 0);
  EXPECT_EQ(q.getK(), 0);
}

TEST(QuaternionConstructors, ParameterizedConstructor) {
  Quaternion q(1, 2, 3, 4);
  EXPECT_EQ(q.getReal(), 1);
  EXPECT_EQ(q.getImag(), 2);
  EXPECT_EQ(q.getJ(), 3);
  EXPECT_EQ(q.getK(), 4);
}

TEST(QuaternionConstructors, CopyConstructor) {
  Quaternion q1(1, 2, 3, 4);
  Quaternion q2(q1);
  EXPECT_EQ(q2.getReal(), 1);
  EXPECT_EQ(q2.getImag(), 2);
  EXPECT_EQ(q2.getJ(), 3);
  EXPECT_EQ(q2.getK(), 4);
}
