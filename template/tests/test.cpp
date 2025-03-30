
#include <gtest/gtest.h>
#include <iostream>

int main(int argc, char **argv) {
  std::cout << "Hello Test Function!" << std::endl;
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
  return 0;
}
