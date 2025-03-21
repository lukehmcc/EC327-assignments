#include "lab3_problem1.h"

int sumElements(int *arr, int size) {
  int runningSum = 0;
  // To keep to o(n) run time, just gonna use a big if else inside this single
  // loop
  for (int i = 0; i < size; i++) {
    if ((i == 0) || (i % 2 == 0)) {
      runningSum += arr[i];
    }
    if ((arr[i] % 2 == 0)) {
      runningSum += arr[i];
    }
  }
  runningSum += arr[0] * arr[size - 1];
  // std::cout << "Addition result: " << runningSum << "\n";
  return runningSum;
}
