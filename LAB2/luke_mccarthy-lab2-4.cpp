#include "lab2_problem4.h"
#include <cstdio>
#include <limits.h>

// define prototypes
int twoNumberGCF();

GreatestCommonFactorResult identifyGCF(int input[5]) {
  // check if they are all 0 to save the trouble
  if (input[0] == 0 && input[1] == 0 && input[2] == 0 && input[3] == 0 &&
      input[4] == 0) {
    return {0, 0};
  }
  // set all of the values in input to the absolute value of themselves
  for (int i = 0; i < 5; i++) {
    input[i] = (input[i] < 0) ? -input[i] : input[i];
  }
  // find the smallest of the bunch
  int smallest = INT_MAX;
  for (int i = 0; i < 5; i++) { // 5 is hardcoded so this is fine
    smallest = (input[i] < smallest && input[i] != 0) ? input[i] : smallest;
  }
  // count up to that number, keep track of total common factors
  int cfs = 0;
  int gcf = 0;
  // loop through and fill out the data
  for (int i = 1; i <= smallest; i++) {
    bool allDivisible = true;
    for (int j = 0; j < 5; j++) {
      if (input[j] == 0) {
        continue;
      }
      if (input[j] % i != 0) {
        allDivisible = false;
        break;
      }
    }
    if (allDivisible == true) {
      cfs++;
      gcf = i;
    }
  }
  return {gcf, cfs};
}
