#include "lab2_problem2.h"
#include <cmath>

// Function prototypes
int countDigits(int number);
int getDigitAtIndex(int number, int index);

int digitSums(int number) {
  int sum = 0;
  // abs the number
  if (number < 0) {
    number *= -1;
  }
  // First sum up all the digits
  int numDigits = countDigits(number);
  for (int i = 0; i < numDigits; i++) {
    sum += getDigitAtIndex(number, i);
  }

  if (numDigits > 1) {
    // Add the second to last digit to the sum
    sum += getDigitAtIndex(number, numDigits - 2);

    // Add the second digit to the sum
    sum += getDigitAtIndex(number, 1);
  }

  return sum;
}

// Function to count the number of digits in a number
int countDigits(int number) {
  int count = 0;
  while (number != 0) {
    number /= 10;
    count++;
  }
  return count;
}

// Function to get the digit at a specific index (0-based index from right)
int getDigitAtIndex(int number, int index) {
  int divisor = pow(10, index);
  return (number / divisor) % 10;
}
