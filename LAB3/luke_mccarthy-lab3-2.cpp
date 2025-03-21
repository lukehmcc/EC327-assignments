#include "lab3_problem2.h"
#include <cstddef>
#include <cstdlib>
#include <cstring>

char *reverseString(const char *str) {
  if (str == NULL) {
    return NULL;
  }
  int length = strlen(str);
  char *reversed = (char *)malloc(sizeof(char) * length + 1);
  for (int i = 0; i < length; i++) {
    reversed[i] = str[length - i - 1];
  }
  reversed[length] = '\0';
  return reversed;
}
