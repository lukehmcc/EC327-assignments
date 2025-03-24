#include "../src/GaussianInteger.h"
#include <gtest/gtest.h>

// Test the default constructor
TEST(GaussianIntegerTest, DefaultConstructor) {
  GaussianInteger g;
  EXPECT_EQ(g.getReal(), 0);
  EXPECT_EQ(g.getImag(), 0);
}

// Test the parameterized constructor
TEST(GaussianIntegerTest, ParameterizedConstructor) {
  GaussianInteger g(3, 4);
  EXPECT_EQ(g.getReal(), 3);
  EXPECT_EQ(g.getImag(), 4);
}

// Test the copy constructor
TEST(GaussianIntegerTest, CopyConstructor) {
  GaussianInteger g1(3, 4);
  GaussianInteger g2(g1);
  EXPECT_EQ(g2.getReal(), 3);
  EXPECT_EQ(g2.getImag(), 4);
}
