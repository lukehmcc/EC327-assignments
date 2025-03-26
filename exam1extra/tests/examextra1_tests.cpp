#include "../src/examextra_problem1.h"
#include <gtest/gtest.h>

TEST(AverageTest, IntInt) {
  EXPECT_EQ(average(10, 20), 15); // (10+20)/2 = 15
  EXPECT_EQ(average(-5, 5), 0);   // (-5+5)/2 = 0
  EXPECT_EQ(average(0, 0), 0);    // (0+0)/2 = 0
  EXPECT_EQ(average(3, 2), 2);    // (3+2)/2 = 2.5 -> truncated to 2
}

TEST(AverageTest, IntFloat) {
  EXPECT_FLOAT_EQ(average(10, 20.5f), 15.25f); // (10+20.5)/2
  EXPECT_FLOAT_EQ(average(5, 1.5f), 3.25f);    // (5+1.5)/2
  EXPECT_FLOAT_EQ(average(-3, 3.5f), 0.25f);   // (-3+3.5)/2
}

TEST(AverageTest, FloatInt) {
  EXPECT_FLOAT_EQ(average(10.5f, 20), 15.25f); // (10.5+20)/2
  EXPECT_FLOAT_EQ(average(1.5f, 5), 3.25f);    // (1.5+5)/2
  EXPECT_FLOAT_EQ(average(3.5f, -3), 0.25f);   // (3.5-3)/2
}

TEST(AverageTest, DoubleInt) {
  EXPECT_DOUBLE_EQ(average(10.5, 20), 15.25); // (10.5+20)/2
  EXPECT_DOUBLE_EQ(average(1.5, 5), 3.25);    // (1.5+5)/2
  EXPECT_DOUBLE_EQ(average(3.5, -3), 0.25);   // (3.5-3)/2
}

TEST(AverageTest, IntDouble) {
  EXPECT_DOUBLE_EQ(average(10, 20.5), 15.25); // (10+20.5)/2
  EXPECT_DOUBLE_EQ(average(5, 1.5), 3.25);    // (5+1.5)/2
  EXPECT_DOUBLE_EQ(average(-3, 3.5), 0.25);   // (-3+3.5)/2
}

TEST(AverageTest, FloatDouble) {
  EXPECT_DOUBLE_EQ(average(10.5f, 20.5), 15.5); // (10.5+20.5)/2
  EXPECT_DOUBLE_EQ(average(1.5f, 5.5), 3.5);    // (1.5+5.5)/2
  EXPECT_DOUBLE_EQ(average(3.5f, -3.5), 0.0);   // (3.5-3.5)/2
}

TEST(AverageTest, DoubleDouble) {
  EXPECT_DOUBLE_EQ(average(10.5, 20.5), 15.5); // (10.5+20.5)/2
  EXPECT_DOUBLE_EQ(average(1.5, 5.5), 3.5);    // (1.5+5.5)/2
  EXPECT_DOUBLE_EQ(average(3.5, -3.5), 0.0);   // (3.5-3.5)/2
}
