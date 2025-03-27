#include "examextra_problem1.h"
#include <iostream>

int main() {
  int num1 = 5;
  int num2 = 10;
  float num3 = 7.5;
  double num4 = 12.8;
  std::cout << average(num1, num2) << std::endl;
  std::cout << average(num1, num3) << std::endl;
  std::cout << average(num3, num2) << std::endl;
  std::cout << average(num4, num1) << std::endl;
  std::cout << average(num3, num4) << std::endl;
  std::cout << average(num4, num4) << std::endl;
  return 0;
}
