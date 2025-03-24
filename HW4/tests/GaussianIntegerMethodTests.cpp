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
  // Case 1: Basic multiplication (positive numbers)
  {
    GaussianInteger g1(2, 3);
    GaussianInteger g2(4, 5);
    ComplexNumber *result = g1.multiply(g2);
    EXPECT_EQ(result->getReal(), (2 * 4 - 3 * 5)); // -7
    EXPECT_EQ(result->getImag(), (2 * 5 + 3 * 4)); // 22
    delete result;
  }

  // Case 2: One negative component
  {
    GaussianInteger g1(-1, 2);
    GaussianInteger g2(3, -4);
    ComplexNumber *result = g1.multiply(g2);
    EXPECT_EQ(result->getReal(), (-1 * 3 - 2 * (-4))); // 5
    EXPECT_EQ(result->getImag(), (-1 * (-4) + 2 * 3)); // 10
    delete result;
  }

  // Case 3: Both negative components
  {
    GaussianInteger g1(-2, -3);
    GaussianInteger g2(-4, -5);
    ComplexNumber *result = g1.multiply(g2);
    EXPECT_EQ(result->getReal(), (-2 * -4 - -3 * -5)); // -7
    EXPECT_EQ(result->getImag(), (-2 * -5 + -3 * -4)); // 22
    delete result;
  }

  // Case 4: Multiplication with zero
  {
    GaussianInteger g1(0, 0);
    GaussianInteger g2(3, 4);
    ComplexNumber *result = g1.multiply(g2);
    EXPECT_EQ(result->getReal(), 0);
    EXPECT_EQ(result->getImag(), 0);
    delete result;
  }

  // Case 5: Identity multiplication (1 + 0i)
  {
    GaussianInteger g1(1, 0);
    GaussianInteger g2(3, 4);
    ComplexNumber *result = g1.multiply(g2);
    EXPECT_EQ(result->getReal(), 3);
    EXPECT_EQ(result->getImag(), 4);
    delete result;
  }

  // Case 6: Imaginary unit multiplication (0 + 1i)
  {
    GaussianInteger g1(0, 1);
    GaussianInteger g2(3, 4);
    ComplexNumber *result = g1.multiply(g2);
    EXPECT_EQ(result->getReal(), -4); // (0*3 - 1*4)
    EXPECT_EQ(result->getImag(), 3);  // (0*4 + 1*3)
    delete result;
  }

  // Case 7: Large numbers
  {
    GaussianInteger g1(100, 200);
    GaussianInteger g2(300, 400);
    ComplexNumber *result = g1.multiply(g2);
    EXPECT_EQ(result->getReal(), (100 * 300 - 200 * 400)); // -50000
    EXPECT_EQ(result->getImag(), (100 * 400 + 200 * 300)); // 100000
    delete result;
  }

  // Case 8: Equal numbers (squaring)
  {
    GaussianInteger g1(5, 7);
    ComplexNumber *result = g1.multiply(g1);
    EXPECT_EQ(result->getReal(), (5 * 5 - 7 * 7)); // -24
    EXPECT_EQ(result->getImag(), (5 * 7 + 7 * 5)); // 70
    delete result;
  }
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
