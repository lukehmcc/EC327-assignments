#include "helpers.h"
#include <iostream>

void printIntArray(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << "\n";
}
