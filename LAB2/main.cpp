#include "lab2_problem1.h"
#include "lab2_problem2.h"
#include "lab2_problem3.h"
#include "lab2_problem4.h"
#include <iostream>

// EC327 Lab 2
int main() {
  // Problem 1
  printf("--- Problem 1 ---\n");
  int n = 4; // Example input
  std::cout << diagonalStars(n) << std::endl;
  printf("\n");

  // Problem 2
  printf("--- Problem 2 ---\n");
  std::cout << digitSums(-51) << std::endl;
  printf("\n");

  // Problem 3
  printf("--- Problem 3 ---\n");
  std::cout << allSubstringsWithoutChar({1, "e"}, 'e') << std::endl;
  printf("\n");

  // Problme 4
  printf("--- Problem 4 ---\n");
  GreatestCommonFactorResult result = identifyGCF((int[]){0, 0, 0, 0, 0});
  printf("GCF: %d, #CF: %d\n", result.greatestCommonFactor,
         result.numberOfCommonFactors);
  printf("\n");
  return 0;
}
