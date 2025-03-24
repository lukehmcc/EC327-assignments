#include "../src/GaussianInteger.h"
#include <gtest/gtest.h>

// Test the equality operator
TEST(GaussianIntegerTest, EqualityOperator) {
  GaussianInteger g1(3, 4);
  GaussianInteger g2(3, 4);
  GaussianInteger g3(1, 2);

  EXPECT_TRUE(g1 == g2);
  EXPECT_FALSE(g1 == g3);
}

// Test the addition operator
TEST(GaussianIntegerTest, AdditionOperator) {
  GaussianInteger g1(3, 4);
  GaussianInteger g2(1, 2);
  GaussianInteger result = g1 + g2;

  EXPECT_EQ(result.getReal(), 4);
  EXPECT_EQ(result.getImag(), 6);
}

// Test the multiplication operator
TEST(GaussianIntegerTest, MultiplicationOperator) {
  GaussianInteger g1(3, 4);
  GaussianInteger g2(1, 2);
  GaussianInteger result = g1 * g2;

  EXPECT_EQ(result.getReal(), 3); // (3*1) = 3
  EXPECT_EQ(result.getImag(), 8); // (4*2) = 8
}

// Test the output stream operator
TEST(GaussianIntegerTest, OutputStreamOperator) {
  GaussianInteger g(3, 4);
  std::ostringstream oss;
  oss << g;
  EXPECT_EQ(oss.str(), "3 + 4i");
}
