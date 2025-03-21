#include "lab2_problem3.h"
#include <cstring>

// Do function proto
std::string getCharRange(const char *array, int start, int end);

std::string allSubstringsWithoutChar(CharArrayWithSize input,
                                     char excludeChar) {
  // Create string to return
  std::string result;
  // Loop defines how many prints there are
  for (int i = input.size; i >= 0; i--) {
    // Loop defines position within string
    for (int j = 0; j < i; j++) {
      // print the current stat of i & j
      // printf("i: %d, j: %d, offset: %d\n", i, j, input.size - i);
      // concatinate the string to the result
      std::string range = getCharRange(input.charArray, j, j + input.size - i);
      // checks if range string inclues a character
      if (range.find(excludeChar) == std::string::npos) {
        result += range;
        result += "\n";
      }
      // printf("%s\n",
      //        getCharRange(input.charArray, j, j + input.size - i).c_str());
    }
  }
  // removes the last character from the result (if it exists)
  // if (result.length() != 0) {
  //   result.pop_back();
  // }
  return result;
}

std::string getCharRange(const char *array, int start, int end) {
  std::string result;
  for (int i = start; i <= end; ++i) {
    result += array[i];
  }
  return result;
}
