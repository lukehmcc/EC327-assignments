#include "../src/Quaternion.h"
#include <gtest/gtest.h>
#include <sstream>

TEST(QuaternionOperators, OutputOperator) {
  Quaternion q(1, 2, 3, 4);
  std::ostringstream oss;
  oss << q;
  EXPECT_EQ(oss.str(), "1 + 2i + 3j + 4k"); // Adjust format as needed
}
