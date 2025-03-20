#include "hw3_problem1.h"
#include <cstddef>
#include <cstdlib>
#include <cstring>

int getLength(const char *str);
void copyOverString(char *to, const char *from);

char *concatenate(const char *first, const char *second) {
  // If you don't check for null pointers first, it'll segfault
  if (first == nullptr && second == nullptr) {
    return nullptr;
  }
  if (first == nullptr) {
    char *toReturn = (char *)malloc(sizeof(char) * getLength(second));
    copyOverString(toReturn, second);
    return toReturn;
  }
  if (second == nullptr) {
    char *toReturn = (char *)malloc(sizeof(char) * getLength(first));
    copyOverString(toReturn, first);
    return toReturn;
  }
  char *toReturn =
      (char *)malloc(sizeof(char) * (getLength(first) + getLength(second)));
  for (int i = 0; i < getLength(first); i++) {
    toReturn[i] = first[i];
  }
  for (int i = 0; i < getLength(second); i++) {
    toReturn[i + getLength(first)] = second[i];
  }
  toReturn[getLength(toReturn)] = '\0';
  return toReturn;
}

int getLength(const char *str) {
  const char *start = str;
  while (*str) {
    str++;
  }
  return str - start;
}

void copyOverString(char *to, const char *from) {
  for (int i = 0; i < getLength(from); i++) {
    to[i] = from[i];
  }
}
