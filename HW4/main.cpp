#include "ComplexNumber.h"
#include "GaussianInteger.h"
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

  EXPECT_EQ(result->getReal(), -5); // (3*1 - 4*2) = -5
  EXPECT_EQ(result->getImag(), 10); // (3*2 + 4*1) = 10

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
  EXPECT_TRUE(g2.divides(g1)); // 2 divides 4

  GaussianInteger g3(2, 0);    // 2 + 0i
  GaussianInteger g4(1, 1);    // 1 + i
  EXPECT_TRUE(g4.divides(g3)); // (1 + i) * (1 - i) = 2

  GaussianInteger g5(2, 0);     // 2 + 0i
  GaussianInteger g6(2, 1);     // 2 + i
  EXPECT_FALSE(g5.divides(g6)); // 2 does not divide 2 + i
}

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

  EXPECT_EQ(result.getReal(), -5); // (3*1 - 4*2) = -5
  EXPECT_EQ(result.getImag(), 10); // (3*2 + 4*1) = 10
}

// Test the output stream operator
TEST(GaussianIntegerTest, OutputStreamOperator) {
  GaussianInteger g(3, 4);
  std::ostringstream oss;
  oss << g;
  EXPECT_EQ(oss.str(), "3 + 4i");
}

int main(int argc, char **argv) {
  GaussianInteger g(3, 4);
  g.getReal();
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
