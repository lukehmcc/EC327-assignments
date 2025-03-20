#include "hw3_problem2.h"
#include <cstdlib>

char *reverseString(const char *toReverse);
int getLength2(const char *str);

ReverseResult reverseOdd(const char **inputStrings, int inputStringsLength) {
  ReverseResult result = {false, nullptr};
  // First check if they are all odd lengthed
  for (int i = 0; i < inputStringsLength; i++) {
    if (getLength2(inputStrings[i]) % 2 == 0) {
      return result;
    }
  }
  // Then create a new array and put in the reversed ones
  char **reversedArray = new char *[inputStringsLength];
  for (int i = 0; i < inputStringsLength; i++) {
    reversedArray[i] = reverseString(inputStrings[i]);
  }
  result.reversedStrings = reversedArray;
  result.success = true;
  return result;
}

char *reverseString(const char *toReverse) {
  char *reversed = (char *)std::malloc(sizeof(char) * getLength2(toReverse));
  for (int i = 0; i < getLength2(toReverse); i++) {
    reversed[i] = toReverse[getLength2(toReverse) - i - 1];
  }
  reversed[getLength2(toReverse)] = '\0';
  return reversed;
}

int getLength2(const char *str) {
  const char *start = str;
  while (*str) {
    str++;
  }
  return str - start;
}
