#include "../src/PolishNotation.h"
#include <gtest/gtest.h>

// Test fixture for RPNCalculator tests
template <typename T> class RPNCalculatorTest : public ::testing::Test {
protected:
  RPNCalculator<T> calculator;
};

// Instantiate tests for both string and vector<string> types
using InputTypes = ::testing::Types<std::string, std::vector<std::string>>;
TYPED_TEST_SUITE(RPNCalculatorTest, InputTypes);

// Basic arithmetic operations
TYPED_TEST(RPNCalculatorTest, HandlesAddition) {
  EXPECT_EQ(this->calculator.evaluate(TypeParam{"2 3 +"}), 5);
}

TYPED_TEST(RPNCalculatorTest, HandlesSubtraction) {
  EXPECT_EQ(this->calculator.evaluate(TypeParam{"5 3 -"}), 2);
}

TYPED_TEST(RPNCalculatorTest, HandlesMultiplication) {
  EXPECT_EQ(this->calculator.evaluate(TypeParam{"2 3 *"}), 6);
}

TYPED_TEST(RPNCalculatorTest, HandlesDivision) {
  EXPECT_EQ(this->calculator.evaluate(TypeParam{"6 2 /"}), 3);
}

// Complex expressions
TYPED_TEST(RPNCalculatorTest, HandlesMultipleOperations) {
  EXPECT_EQ(this->calculator.evaluate(TypeParam{"4 2 5 * + 1 3 - /"}), -7);
}

TYPED_TEST(RPNCalculatorTest, HandlesWhitespaceInStringInput) {
  if constexpr (std::is_same_v<TypeParam, std::string>) {
    EXPECT_EQ(this->calculator.evaluate("  2   3   +  "), 5);
  }
}

// Edge cases
TYPED_TEST(RPNCalculatorTest, HandlesSingleNumber) {
  EXPECT_EQ(this->calculator.evaluate(TypeParam{"42"}), 42);
}

TYPED_TEST(RPNCalculatorTest, HandlesNegativeNumbers) {
  EXPECT_EQ(this->calculator.evaluate(TypeParam{"-3 5 +"}), 2);
}

// Error conditions
TYPED_TEST(RPNCalculatorTest, ThrowsOnInsufficientOperands) {
  EXPECT_THROW(this->calculator.evaluate(TypeParam{"2 +"}), std::runtime_error);
}
