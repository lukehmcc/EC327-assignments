#include "lab4_problem1.h"
#include "lab4_problem2.h"
#include "lab4_problem3.h"
#include "lab4_problem4.h"
#include <cstring>
#include <iostream>

void alphabetPrinter(int *countedLetters);

int checkAlphabetEquivalency(int caseNumber, std::string fileName,
                             int *countedLetters, int *expectedResult);
bool equivalentIntArray(int *arr1, int *arr2, int length);
void testAlphabetCounter();
void testFieldCounter();
void testStudentClass();
void testPersonClass();

int main() {
  std::cout << "--- Problem 1 ---" << std::endl;
  testAlphabetCounter();
  std::cout << "--- Problem 2 ---" << std::endl;
  testFieldCounter();
  std::cout << "--- Problem 3 ---" << std::endl;
  testStudentClass();
  std::cout << "--- Problem 4 ---" << std::endl;
  testPersonClass();
  return 0;
}

void testAlphabetCounter() {
  int totalTestCases = 5;
  int passedCases = 0;

  // Test Case 1: Brown Fox
  std::string fileNameBrownFox = "text_files/brown_fox.txt";
  int *countedLettersBrownFox = alphabetCounter(fileNameBrownFox);
  int *expectedResultBrownFox =
      new int[26]{1, 1, 1, 2, 4, 1, 1, 2, 1, 1, 1, 1, 1,
                  1, 4, 1, 1, 2, 0, 2, 2, 1, 1, 1, 1, 1};
  passedCases += checkAlphabetEquivalency(
      1, fileNameBrownFox, countedLettersBrownFox, expectedResultBrownFox);
  delete[] countedLettersBrownFox;
  delete[] expectedResultBrownFox;
  // Test Case 2: Empty
  std::string fileNameEmpty = "text_files/empty.txt";
  int *countedLettersEmpty = alphabetCounter(fileNameEmpty);
  int *expectedResultEmpty = new int[26]{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                                         0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  passedCases += checkAlphabetEquivalency(2, fileNameEmpty, countedLettersEmpty,
                                          expectedResultEmpty);
  delete[] countedLettersEmpty;
  delete[] expectedResultEmpty;
  // Test Case 3: All Letters (Alphabet)
  std::string fileNameAlphabet = "text_files/alphabet.txt";
  int *countedLettersAlphabet = alphabetCounter(fileNameAlphabet);
  int *expectedResultAlphabet =
      new int[26]{2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                  2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
  passedCases += checkAlphabetEquivalency(
      3, fileNameAlphabet, countedLettersAlphabet, expectedResultAlphabet);
  delete[] countedLettersAlphabet;
  delete[] expectedResultAlphabet;

  // Test Case 4: Special Characters and Numbers
  std::string fileNameSpecialChars = "text_files/special_chars.txt";
  int *countedLettersSpecialChars = alphabetCounter(fileNameSpecialChars);
  int *expectedResultSpecialChars =
      new int[26]{0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 3, 0,
                  0, 2, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0};
  passedCases += checkAlphabetEquivalency(4, fileNameSpecialChars,
                                          countedLettersSpecialChars,
                                          expectedResultSpecialChars);
  delete[] countedLettersSpecialChars;
  delete[] expectedResultSpecialChars;

  // Test Case 5: Mixed Case Letters
  std::string fileNameMixedCase = "text_files/mixed_case.txt";
  int *countedLettersMixedCase = alphabetCounter(fileNameMixedCase);
  int *expectedResultMixedCase =
      new int[26]{2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                  2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
  passedCases += checkAlphabetEquivalency(
      5, fileNameMixedCase, countedLettersMixedCase, expectedResultMixedCase);
  delete[] countedLettersMixedCase;
  delete[] expectedResultMixedCase;
  std::cout << "Passed: " << passedCases << "/" << totalTestCases << "!"
            << std::endl
            << std::endl;
}

bool checkFieldEquivalency(int caseNumber, std::string fileName,
                           int actualResult, int expectedResult) {
  if (actualResult == expectedResult) {
    return true;
  } else {
    std::cout << "Failed Case " << caseNumber << ": " << fileName << std::endl;
    std::cout << "Expected: " << expectedResult << std::endl;
    std::cout << "Got: " << actualResult << std::endl;
    return false;
  }
}

void testFieldCounter() {
  int passedCases = 0;

  // Test Case 1: Simple CSV
  std::string fileNameSimple = "csv_files/simple.csv";
  int maxFieldsSimple = fieldCounter(fileNameSimple);
  int expectedResultSimple = 3; // Each line has 3 fields
  if (checkFieldEquivalency(1, fileNameSimple, maxFieldsSimple,
                            expectedResultSimple)) {
    passedCases++;
  }

  // Test Case 2: Quoted Fields
  std::string fileNameQuotedFields = "csv_files/quoted_fields.csv";
  int maxFieldsQuotedFields = fieldCounter(fileNameQuotedFields);
  int expectedResultQuotedFields = 4; // The line has 4 fields
  if (checkFieldEquivalency(2, fileNameQuotedFields, maxFieldsQuotedFields,
                            expectedResultQuotedFields)) {
    passedCases++;
  }

  // Test Case 3: Mixed Fields
  std::string fileNameMixedFields = "csv_files/mixed_fields.csv";
  int maxFieldsMixedFields = fieldCounter(fileNameMixedFields);
  int expectedResultMixedFields = 4; // The second line has 4 fields
  if (checkFieldEquivalency(3, fileNameMixedFields, maxFieldsMixedFields,
                            expectedResultMixedFields)) {
    passedCases++;
  }

  // Test Case 4: Empty File
  std::string fileNameEmpty = "csv_files/empty.csv";
  int maxFieldsEmpty = fieldCounter(fileNameEmpty);
  int expectedResultEmpty = 0; // No fields in an empty file
  if (checkFieldEquivalency(4, fileNameEmpty, maxFieldsEmpty,
                            expectedResultEmpty)) {
    passedCases++;
  }

  // Test Case 5: Complex CSV
  std::string fileNameComplex = "csv_files/complex.csv";
  int maxFieldsComplex = fieldCounter(fileNameComplex);
  int expectedResultComplex = 3; // Each line has 3 fields
  if (checkFieldEquivalency(5, fileNameComplex, maxFieldsComplex,
                            expectedResultComplex)) {
    passedCases++;
  }

  // Print test results
  std::cout << "Passed " << passedCases << "/5!" << std::endl << std::endl;
}

void alphabetPrinter(int *countedLetters) {
  std::cout << "Letters: ";
  for (int i = 0; i < 26; i++) {
    std::cout << (char)('a' + i) << ":" << countedLetters[i] << ", ";
  }
  std::cout << std::endl;
}

bool checkStudentEquivalency(int caseNumber, const std::string &testName,
                             double actualResult, double expectedResult) {
  if (actualResult == expectedResult) {
    return true;
  } else {
    std::cout << "Failed Case " << caseNumber << ": " << testName << std::endl;
    std::cout << "Expected: " << expectedResult << std::endl;
    std::cout << "Got: " << actualResult << std::endl;
    return false;
  }
}

void testStudentClass() {
  int passedCases = 0;

  // Test Case 1: Single Quiz Score
  Student student1("Alice");
  student1.addQuizScore(100);
  double average1 = student1.getAverageScore();
  if (checkStudentEquivalency(1, "Single Quiz Score", average1, 100.0)) {
    passedCases++;
  }

  // Test Case 2: Multiple Quiz Scores
  Student student2("Bob");
  student2.addQuizScore(80);
  student2.addQuizScore(90);
  student2.addQuizScore(70);
  double average2 = student2.getAverageScore();
  if (checkStudentEquivalency(2, "Multiple Quiz Scores", average2, 80.0)) {
    passedCases++;
  }

  // Test Case 3: No Quiz Scores
  Student student3("Charlie");
  double average3 = student3.getAverageScore();
  if (checkStudentEquivalency(3, "No Quiz Scores", average3, 0.0)) {
    passedCases++;
  }

  // Test Case 4: Negative Quiz Scores
  Student student4("David");
  student4.addQuizScore(-50);
  student4.addQuizScore(100);
  double average4 = student4.getAverageScore();
  if (checkStudentEquivalency(4, "Negative Quiz Scores", average4, 25.0)) {
    passedCases++;
  }

  // Test Case 5: Large Number of Quiz Scores
  Student student5("Eve");
  for (int i = 1; i <= 100; i++) {
    student5.addQuizScore(i);
  }
  double average5 = student5.getAverageScore();
  if (checkStudentEquivalency(5, "Large Number of Quiz Scores", average5,
                              50.5)) {
    passedCases++;
  }

  // Print test results
  std::cout << "Passed " << passedCases << "/5!" << std::endl << std::endl;
}

// Helper function to check if two values are equal and print results if they
// are not
bool checkPersonEquivalency(int caseNumber, const std::string &testName,
                            const std::string &actualResult,
                            const std::string &expectedResult) {
  if (actualResult == expectedResult) {
    return true;
  } else {
    std::cout << "Failed Case " << caseNumber << ": " << testName << std::endl;
    std::cout << "Expected: " << expectedResult << std::endl;
    std::cout << "Got: " << actualResult << std::endl;
    return false;
  }
}

bool checkPersonEquivalency(int caseNumber, const std::string &testName,
                            int actualResult, int expectedResult) {
  if (actualResult == expectedResult) {
    return true;
  } else {
    std::cout << "Failed Case " << caseNumber << ": " << testName << std::endl;
    std::cout << "Expected: " << expectedResult << std::endl;
    std::cout << "Got: " << actualResult << std::endl;
    return false;
  }
}

void testPersonClass() {
  int passedCases = 0;

  // Test Case 1: Basic Befriending
  Person person1("Alice");
  Person person2("Bob");
  person1.befriend(person2);
  if (checkPersonEquivalency(1, "Basic Befriending", person1.getFriendCount(),
                             1) &&
      checkPersonEquivalency(1, "Basic Befriending", person1.getFriends(),
                             "Bob")) {
    passedCases++;
  }

  // Test Case 2: Unfriending
  person1.unfriend(person2);
  if (checkPersonEquivalency(2, "Unfriending", person1.getFriendCount(), 0) &&
      checkPersonEquivalency(2, "Unfriending", person1.getFriends(), "")) {
    passedCases++;
  }

  // Test Case 3: Multiple Friends
  Person person3("Charlie");
  Person person4("Dave");
  person1.befriend(person2);
  person1.befriend(person3);
  person1.befriend(person4);
  if (checkPersonEquivalency(3, "Multiple Friends", person1.getFriendCount(),
                             3) &&
      checkPersonEquivalency(3, "Multiple Friends", person1.getFriends(),
                             "Bob, Charlie, Dave")) {
    passedCases++;
  }

  // Test Case 4: Friends of Friends
  person2.befriend(person3);
  person2.befriend(person4);
  if (checkPersonEquivalency(4, "Friends of Friends",
                             person1.getFriendsOfFriends(), "Charlie, Dave")) {
    passedCases++;
  }
  // Test Case 5: Complex Friends of Friends
  Person person5("Eve");
  Person person6("Frank");

  // person1's friends
  person1.befriend(person2);
  person1.befriend(person3);

  // person2's friends
  person2.befriend(person4);
  person2.befriend(person5);

  // person3's friends
  person3.befriend(person5);
  person3.befriend(person6);

  // person4's friends
  person4.befriend(person6);

  // Check friends of friends for person1
  if (checkPersonEquivalency(5, "Complex Friends of Friends",
                             person1.getFriendsOfFriends(),
                             "Charlie, Dave, Dave, Eve, Eve, Frank, Frank, "
                             "Charlie, Dave, Dave, Eve, Eve, Frank")) {
    passedCases++;
  }
  // Test Case 6: No Friends
  Person person7("Eve");
  if (checkPersonEquivalency(5, "No Friends", person7.getFriendCount(), 0) &&
      checkPersonEquivalency(5, "No Friends", person7.getFriends(), "")) {
    passedCases++;
  }

  // Print test results
  std::cout << "Passed: " << passedCases << "/6!" << std::endl;
}

int checkAlphabetEquivalency(int caseNumber, std::string fileName,
                             int *countedLetters, int *expectedResult) {
  if (equivalentIntArray(countedLetters, expectedResult, 26)) {
    return 1;
  } else {
    std::cout << "Failed Case " << caseNumber << ": " << fileName << std::endl;
    std::cout << "Expected: " << std::endl;
    alphabetPrinter(expectedResult);
    std::cout << "Got: " << std::endl;
    alphabetPrinter(countedLetters);
    return 0;
  }
}

bool equivalentIntArray(int *arr1, int *arr2, int length) {
  for (int i = 0; i < length; i++) {
    if (arr1[i] != arr2[i]) {
      return false;
    }
  }
  return true;
}
