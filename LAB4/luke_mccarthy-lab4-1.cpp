#include "lab4_problem1.h"

#include <cctype>
#include <fstream>
#include <iostream>
int *alphabetCounter(string filename) {
  // lets ignore the input for a sec and define our own string
  int *letterFrequency = new int[26];
  for (int i = 0; i < 26; i++) {
    letterFrequency[i] = 0;
  }
  std::fstream file(filename);

  if (!file) {
    std::cerr << "Error opening file: " << filename << "!\n";
    return NULL;
  }

  char ch;
  while (file.get(ch)) {
    // Convert to lowercase
    ch = std::tolower(ch);

    // Check if the character is a lowercase letter
    if (ch >= 'a' && ch <= 'z') {
      letterFrequency[ch - 'a']++;
    }
  }

  file.close();
  return letterFrequency;
}
