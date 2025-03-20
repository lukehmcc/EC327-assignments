#include "lab4_problem2.h"
#include <fstream>

int fieldCounter(string filenameCSV) {
  int maxFields = 0;
  std::fstream file(filenameCSV);
  std::string line;

  while (std::getline(file, line)) {
    // Every time a " is seen this will get flipped, so items in quotes won't
    // have their commas counted
    bool shouldCountComma = true;
    int tempFieldCounter = 1;
    for (int i = 0; i < line.length(); i++) {
      if (line[i] == ',' && shouldCountComma) {
        tempFieldCounter++;
      }
      if (line[i] == '"') {
        shouldCountComma = !shouldCountComma;
      }
    }
    if (tempFieldCounter > maxFields) {
      maxFields = tempFieldCounter;
    }
  }
  file.close();
  return maxFields;
}
