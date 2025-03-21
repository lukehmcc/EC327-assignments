#include "lab2_problem1.h"
#include <string>
#include <vector>

std::string diagonalStars(int n) {
  // Check for bad inputs
  if (n < 1) {
    return "Not Supported";
  }

  // Define the counters that place the stars
  int forward = 0;
  int backward = n - 1;

  // Create a vector to store each line of the pattern
  std::vector<std::string> lines;

  // Loop through and construct the pattern
  for (int i = 0; i < n; i++) {
    std::string line;
    for (int j = 0; j < n; j++) {
      // Decide if it's a "-" or " "
      if (j == forward || j == backward) {
        line += '-';
      } else {
        line += ' ';
      }
    }
    lines.push_back(line);
    forward++;
    backward--;
  }

  // Combine the lines into a single string with newlines
  std::string result;
  for (int i = 0; i < lines.size(); i++) {
    result += lines[i];
    if (i != lines.size() - 1) {
      result += '\n';
    }
  }

  return result;
}
