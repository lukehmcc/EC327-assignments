#include <gtest/gtest.h>

int main(int argc, char **argv) {
  std::cout << "main function" << std::endl;
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
