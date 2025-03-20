#include "hw3_problem1.h"
#include "hw3_problem2.h"
#include "hw3_problem3.h"
#include "hw3_problem5.h"
#include "iostream"
#include <cassert>

void test_concatenate();
void test_reverse_odd();
void test_insert();
void test_possible_change();

int main() {
  std::cout << "--- Problem 1 ---" << std::endl;
  std::cout << "Running concatenation tests...\n";
  test_concatenate();

  std::cout << "--- Problem 2 ---" << std::endl;
  std::cout << "Running reverse tests..." << std::endl;
  test_reverse_odd();

  std::cout << "--- Problem 3 ---" << std::endl;
  std::cout << "Running insert tests..." << std::endl;
  test_insert();

  std::cout << "--- Problem 5 ---" << std::endl;
  std::cout << "Running nickeling & diming test..." << std::endl;
  test_possible_change();

  return 0;
}

// Function to run all test cases
void test_concatenate() {
  struct TestCase {
    const char *first;
    const char *second;
    const char *expected;
  };

  TestCase testCases[] = {
      {"Hello", "World", "HelloWorld"},     // Test 1: Basic concatenation
      {"", "World", "World"},               // Test 2: Empty first string
      {"Hello", "", "Hello"},               // Test 3: Empty second string
      {"", "", ""},                         // Test 4: Both strings empty
      {"A", "B", "AB"},                     // Test 5: Single character strings
      {"Hello@", "#World", "Hello@#World"}, // Test 6: Special characters
      {"Hello ", "World", "Hello World"},   // Test 7: Concatenation with spaces
      {"123", "456", "123456"},             // Test 8: Numeric characters
      {"Lorem ipsum dolor sit amet, consectetur ", "adipiscing elit.",
       "Lorem ipsum dolor sit amet, consectetur adipiscing elit."}, // Test 9:
                                                                    // Long
                                                                    // strings
      {nullptr, "World",
       "World"}, // Test 10: First string is NULL (assume safe handling)
      {"Hello", nullptr,
       "Hello"}, // Test 11: Second string is NULL (assume safe handling)
      {nullptr, nullptr,
       nullptr} // Test 12: Both strings NULL (assume safe handling)
  };

  int passed = 0, failed = 0;

  for (const auto &test : testCases) {
    char *result = concatenate(test.first, test.second);
    if ((result == nullptr && test.expected == nullptr) ||
        (result != nullptr && test.expected != nullptr &&
         strcmp(result, test.expected) == 0)) {
      std::cout << "PASS: \"" << (test.first ? test.first : "NULL") << "\" + \""
                << (test.second ? test.second : "NULL") << "\" -> \""
                << (result ? result : "NULL") << "\"\n";
      passed++;
    } else {
      std::cout << "FAIL: \"" << (test.first ? test.first : "NULL") << "\" + \""
                << (test.second ? test.second : "NULL") << "\" -> Expected \""
                << (test.expected ? test.expected : "NULL") << "\", but got \""
                << (result ? result : "NULL") << "\"\n";
      failed++;
    }
    delete[] result; // Free dynamically allocated memory
  }

  std::cout << "\nConcatenation Test Summary: " << passed << " passed, "
            << failed << " failed.\n";
}

void test_reverse_odd() {
  struct TestCase {
    const char **input;
    int length;
    bool expectedSuccess;
    const char **expectedReversed;
  };

  const char *case1_input[] = {"abc", "defgh", "ijklm"};
  const char *case1_expected[] = {"cba", "hgfed", "mlkji"};

  const char *case2_input[] = {"hello", "world", "test"};

  const char *case3_input[] = {};

  const char *case4_input[] = {"racecar"};
  const char *case4_expected[] = {"racecar"};

  const char *case5_input[] = {"even"};

  const char *case6_input[] = {"abcd", "efgh", "ijkl"};

  const char *case7_input[] = {"Odd", "Words", "Mix"};
  const char *case7_expected[] = {"ddO", "sdroW", "xiM"};

  const char *case8_input[] = {"@#!", "$%^&*"};
  const char *case8_expected[] = {"!#@", "*&^%$"};

  const char *case9_input[] = {"12345", "678"};
  const char *case9_expected[] = {"54321", "876"};

  const char *case10_input[] = {"üñîçø∂e", "测试"};

  const char *case11_input[] = {"sdupercalifragilisticexpialidocious"};
  const char *case11_expected[] = {"suoicodilaipxecitsiligarfilacrepuds"};

  TestCase testCases[] = {{case1_input, 3, true, case1_expected},
                          {case2_input, 3, false, nullptr},
                          {nullptr, 0, true, nullptr},
                          {case4_input, 1, true, case4_expected},
                          {case5_input, 1, false, nullptr},
                          {case6_input, 3, false, nullptr},
                          {case7_input, 3, true, case7_expected},
                          {case8_input, 2, true, case8_expected},
                          {case9_input, 2, true, case9_expected},
                          {case10_input, 2, false, nullptr},
                          {case11_input, 1, true, case11_expected}};

  int passed = 0, failed = 0;

  for (const auto &test : testCases) {
    ReverseResult result = reverseOdd(test.input, test.length);
    if (result.success == test.expectedSuccess) {
      if (test.expectedSuccess && result.reversedStrings) {
        bool match = true;
        for (int i = 0; i < test.length; ++i) {
          if (strcmp(result.reversedStrings[i], test.expectedReversed[i]) !=
              0) {
            match = false;
            break;
          }
        }
        if (match) {
          std::cout << "PASS\n";
          passed++;
        } else {
          std::cout << "FAIL: Unexpected reversed strings\n";
          failed++;
        }
      } else {
        std::cout << "PASS\n";
        passed++;
      }
    } else {
      std::cout << "FAIL: Unexpected success value\n";
      failed++;
    }
  }

  std::cout << "\nReverseOdd Test Summary: " << passed << " passed, " << failed
            << " failed.\n";
}

// Helper function to convert a linked list to a vector for easier comparison
std::vector<int> listToArray(Node *head) {
  if (!head)
    return {};
  std::vector<int> result = listToArray(head->next);
  result.insert(result.begin(), head->value);
  return result;
}

// Helper function to create a linked list from a vector
Node *arrayToList(const std::vector<int> &values, size_t index = 0) {
  if (index >= values.size())
    return nullptr;
  return new Node{values[index], arrayToList(values, index + 1)};
}

// Helper function to free allocated memory
void freeList(Node *head) {
  if (!head)
    return;
  freeList(head->next);
  delete head;
}

// Function to run all test cases recursively
void runTests(const std::vector<std::pair<std::vector<int>, int>> &testCases,
              int index, int &passed, int &failed) {
  if (index >= testCases.size()) {
    std::cout << "\nInsertInOrder Test Summary: " << passed << " passed, "
              << failed << " failed.\n";
    return;
  }
  auto [initialList, newValue] = testCases[index];
  Node *head = arrayToList(initialList);
  std::cout << "Testing case " << index << ", adding " << newValue << std::endl;
  Node *resultHead = insertInOrder(head, newValue);

  std::vector<int> expected = initialList;
  expected.push_back(newValue);
  std::sort(expected.begin(), expected.end());

  if (listToArray(resultHead) == expected) {
    std::cout << "PASS: Insert " << newValue << " into list" << "\n";
    passed++;
  } else {
    std::cout << "FAIL: Insert " << newValue << " into list" << "\n";
    failed++;
  }

  freeList(resultHead);
  runTests(testCases, index + 1, passed, failed);
}

// Wrapper function to start the test
void test_insert() {
  std::vector<std::pair<std::vector<int>, int>> testCases = {
      {{}, 5},
      {{10, 20, 30}, 5},
      {{10, 20, 30}, 40},
      {{10, 20, 40}, 30},
      {{10, 20, 30}, 20},
      {{0, 10, 20}, -10},
      {{10, 20, 30}, 1000},
      {{1, 2, 3}, 0},
      {{10}, 5},
      {{10}, 15},
      {{1, 2, 3, 4, 5}, 3}};

  int passed = 0, failed = 0;
  runTests(testCases, 0, passed, failed);
}
void freeCoinArrays(struct CoinArrays coinArrays) {
  for (int i = 0; i < coinArrays.size; i++) {
    free(coinArrays.arrays[i].coins);
  }
  free(coinArrays.arrays);
}

int compareCoinArray(struct CoinArray a, struct CoinArray b) {
  if (a.size != b.size)
    return 0;
  for (int i = 0; i < a.size; i++) {
    if (a.coins[i] != b.coins[i])
      return 0;
  }
  return 1;
}

void test_possible_change() {
  int cases[] = {5, 10, 17, 25};
  int length = sizeof(cases) / sizeof(cases[0]);

  for (int i = 0; i < length; i++) {
    std::cout << std::endl << "Testing for input: " << cases[i] << std::endl;
    printCoinArrays(possibleChangeAmounts(cases[i]));
  }
}
