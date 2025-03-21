#include "hw2_problem4.h"
#include <cmath>
#include <cstring>

void binEncode(int *charCounter, std::string *binString, int num);
void binEncodeFraction(int *charCounter, std::string *binString, double num,
                       int maxLength);

std::string convertToBinaryFraction(double num) {
  std::string binary = "";
  int charCounter = 0;
  // Make sure it isn't too big!
  if (num > 4294967295) {
    binary = "Input number too large!";
    // Then check if it is fully decimal, if it is, encode it and return
  } else if (0 < num && num < 1) {
    binEncodeFraction(&charCounter, &binary, num, 17);
    // If it is a mix, first encode the whole number part, then the decimal part
  } else if (0 > num) {
    binary = "Negative numbers not supported!";
    // Then check if it is a whole number
  } else if (std::fmod(num, 1.0) == 0) {
    binEncode(&charCounter, &binary, num);
    // Finally mixed number check
  } else {
    binEncode(&charCounter, &binary, num);
    binary.append(".");
    binEncodeFraction(&charCounter, &binary, fmod(num, 1.0),
                      33 - binary.length());
  }
  return binary;
}

// Encodes whole numbers to binary string
void binEncode(int *charCounter, std::string *binString, int num) {
  if (num == 0) {
    *binString = "0";
    *charCounter = 1;
    return;
  }

  while (num > 0) {
    *binString = (num % 2 == 0 ? "0" : "1") + *binString;
    num /= 2;
  }

  *charCounter = binString->length();
}

// Encodes fractions to binary string
void binEncodeFraction(int *charCounter, std::string *binString, double num,
                       int maxLength) {
  if (num <= 0.0 || num >= 1.0) {
    *binString = "Error: Input must be a fraction between 0 and 1.";
    *charCounter = binString->length();
    return;
  }
  if (binString->length() == 0) {
    *binString = "0.";
  }
  maxLength +=
      binString->length(); // increase max length to deal with whole # string
  while (num > 0.0) {
    if (binString->length() >
        maxLength) { // Limit to 32 bits to avoid infinite loops
      break;
    }
    num *= 2;
    if (num >= 1.0) {
      *binString += "1";
      num -= 1.0;
    } else {
      *binString += "0";
    }
  }

  *charCounter = binString->length();
}
