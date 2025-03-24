#include "../src/GaussianInteger.h"
#include <gtest/gtest.h>

// Test the add method
TEST(GaussianIntegerTest, AddMethod) {
  GaussianInteger g1(3, 4);
  GaussianInteger g2(1, 2);
  ComplexNumber *result = g1.add(g2);

  EXPECT_EQ(result->getReal(), 4);
  EXPECT_EQ(result->getImag(), 6);

  delete result; // Clean up dynamically allocated memory
}

// Test the multiply method
TEST(GaussianIntegerTest, MultiplyMethod) {
  GaussianInteger g1(3, 4);
  GaussianInteger g2(1, 2);
  ComplexNumber *result = g1.multiply(g2);

  EXPECT_EQ(result->getReal(), 3); // (3*1) = 3
  EXPECT_EQ(result->getImag(), 8); // (4*2) = 8

  delete result; // Clean up dynamically allocated memory
}

// Test the conjugate method
TEST(GaussianIntegerTest, ConjugateMethod) {
  GaussianInteger g(3, 4);
  ComplexNumber *result = g.conjugate();

  EXPECT_EQ(result->getReal(), 3);
  EXPECT_EQ(result->getImag(), -4);

  delete result; // Clean up dynamically allocated memory
}

// Test the norm method
TEST(GaussianIntegerTest, NormMethod) {
  GaussianInteger g(3, 4);
  EXPECT_EQ(g.norm(), 25); // 3^2 + 4^2 = 25
}

// Test the divides method
TEST(GaussianIntegerTest, DividesMethod) {
  GaussianInteger g1(4, 0);    // 4 + 0i
  GaussianInteger g2(2, 0);    // 2 + 0i
  EXPECT_TRUE(g1.divides(g2)); // 2 divides 4

  GaussianInteger g3(2, 0);    // 2 + 0i
  GaussianInteger g4(1, 1);    // 1 + i
  EXPECT_TRUE(g3.divides(g4)); // 1 divides 2

  GaussianInteger g5(2, 0);     // 2 + 0i
  GaussianInteger g6(2, 1);     // 2 + i
  EXPECT_FALSE(g5.divides(g6)); // 2 does not divide 2 + i
}
