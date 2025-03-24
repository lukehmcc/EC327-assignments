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

TEST(GaussianIntegerTest, MultiplicationOperator) {
  // Test case 1: Basic multiplication
  {
    GaussianInteger g1(3, 4); // 3 + 4i
    GaussianInteger g2(1, 2); // 1 + 2i
    GaussianInteger result = g1 * g2;

    // Correct calculation:
    // Real part: (3*1 - 4*2) = 3 - 8 = -5
    // Imaginary part: (3*2 + 4*1) = 6 + 4 = 10
    EXPECT_EQ(result.getReal(), -5);
    EXPECT_EQ(result.getImag(), 10);
  }

  // Test case 2: Multiplication with negative numbers
  {
    GaussianInteger g1(2, -3); // 2 - 3i
    GaussianInteger g2(-1, 4); // -1 + 4i
    GaussianInteger result = g1 * g2;

    // (2*-1 - (-3)*4) = -2 + 12 = 10 (real)
    // (2*4 + (-3)*-1) = 8 + 3 = 11 (imaginary)
    EXPECT_EQ(result.getReal(), 10);
    EXPECT_EQ(result.getImag(), 11);
  }

  // Test case 3: Multiplication with zero
  {
    GaussianInteger g1(0, 0);
    GaussianInteger g2(3, 4);
    GaussianInteger result = g1 * g2;
    EXPECT_EQ(result.getReal(), 0);
    EXPECT_EQ(result.getImag(), 0);
  }

  // Test case 4: Multiplication by identity (1 + 0i)
  {
    GaussianInteger g1(1, 0);
    GaussianInteger g2(3, 4);
    GaussianInteger result = g1 * g2;
    EXPECT_EQ(result.getReal(), 3);
    EXPECT_EQ(result.getImag(), 4);
  }

  // Test case 5: Multiplication by imaginary unit (0 + 1i)
  {
    GaussianInteger g1(0, 1);
    GaussianInteger g2(3, 4);
    GaussianInteger result = g1 * g2;
    EXPECT_EQ(result.getReal(), -4); // (0*3 - 1*4)
    EXPECT_EQ(result.getImag(), 3);  // (0*4 + 1*3)
  }
}

// Test the output stream operator
TEST(GaussianIntegerTest, OutputStreamOperator) {
  GaussianInteger g(3, -4);
  std::ostringstream oss;
  oss << g;
  EXPECT_EQ(oss.str(), "3 - 4i");
}
