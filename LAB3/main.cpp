#include "lab3_problem1.h"
#include "lab3_problem2.h"
#include "lab3_problem3.h"
#include "lab3_problem4.h"
#include <cassert>
#include <cstddef>
#include <cstring>
#include <iostream>
#include <string.h>

void testSumElements();
void testReverseString();
void testFindMiddle();
void testFibonacci();

int main() {
  std::cout << "--- Problem 1 ---\n";
  testSumElements();

  std::cout << "--- Problem 2 ---\n";
  testReverseString();

  std::cout << "--- Problem 3 ---\n";
  testFindMiddle();

  std::cout << "--- Problem 4 ---\n";
  testFibonacci();
  return 0;
}

void testSumElements() {
  // Test Case 1: Basic Case
  {
    int arr[] = {1, 2, 3};
    int size = 3;
    assert(sumElements(arr, size) == 9);
    std::cout << "Test Case 1 Passed!\n";
  }

  // Test Case 2: Basic Case with Even Size
  {
    int arr[] = {1, 2, 3, 4};
    int size = 4;
    assert(sumElements(arr, size) == 14);
    std::cout << "Test Case 2 Passed!\n";
  }

  // Test Case 3: All Even Numbers
  {
    int arr[] = {2, 4, 6, 8};
    int size = 4;
    assert(sumElements(arr, size) == 44);
    std::cout << "Test Case 3 Passed!\n";
  }

  // Test Case 4: All Odd Numbers
  {
    int arr[] = {1, 3, 5, 7};
    int size = 4;
    assert(sumElements(arr, size) == 13);
    std::cout << "Test Case 4 Passed!\n";
  }

  // Test Case 5: Single Element
  {
    int arr[] = {10};
    int size = 1;
    assert(sumElements(arr, size) == 120);
    std::cout << "Test Case 5 Passed!\n";
  }

  // Test Case 6: Empty Array
  {
    int arr[] = {};
    int size = 0;
    assert(sumElements(arr, size) == 0);
    std::cout << "Test Case 6 Passed!\n";
  }

  // Test Case 7: Negative Numbers
  {
    int arr[] = {-1, -2, -3, -4};
    int size = 4;
    assert(sumElements(arr, size) == -6);
    std::cout << "Test Case 7 Passed!\n";
  }

  // Test Case 8: Mixed Positive and Negative Numbers
  {
    int arr[] = {-1, 2, -3, 4};
    int size = 4;
    assert(sumElements(arr, size) == -2);
    std::cout << "Test Case 8 Passed!\n";
  }

  // Test Case 10: All Zeros
  {
    int arr[] = {0, 0, 0, 0};
    int size = 4;
    assert(sumElements(arr, size) == 0);
    std::cout << "Test Case 10 Passed!\n";
  }

  // Test Case 11: Large Array
  {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10;
    assert(sumElements(arr, size) == 65);
    std::cout << "Test Case 11 Passed!\n";
  }

  // Test Case 12: Odd-Sized Array
  {
    int arr[] = {1, 2, 3, 4, 5};
    int size = 5;
    assert(sumElements(arr, size) == 20);
    std::cout << "Test Case 12 Passed!\n";
  }

  std::cout << "All test cases passed!\n\n";
}

void testReverseString() {
  // Test Case 1: Empty String
  {
    const char *input = "";
    char *output = reverseString(input);
    assert(strcmp(output, "") == 0);
    free(output);
    std::cout << "Test 1 Passed\n";
  }

  // Test Case 2: Single Character
  {
    const char *input = "A";
    char *output = reverseString(input);
    assert(strcmp(output, "A") == 0);
    free(output);
    std::cout << "Test 2 Passed\n";
  }

  // Test Case 3: Even-Length String
  {
    const char *input = "test";
    char *output = reverseString(input);
    assert(strcmp(output, "tset") == 0);
    free(output);
    std::cout << "Test 3 Passed\n";
  }

  // Test Case 4: Odd-Length String
  {
    const char *input = "hello";
    char *output = reverseString(input);
    assert(strcmp(output, "olleh") == 0);
    free(output);
    std::cout << "Test 4 Passed\n";
  }

  // Test Case 5: String with Spaces
  {
    const char *input = "Hello World";
    char *output = reverseString(input);
    assert(strcmp(output, "dlroW olleH") == 0);
    free(output);
    std::cout << "Test 5 Passed\n";
  }

  // Test Case 6: String with Special Characters
  {
    const char *input = "Hello!";
    char *output = reverseString(input);
    assert(strcmp(output, "!olleH") == 0);
    free(output);
    std::cout << "Test 6 Passed\n";
  }

  // Test Case 7: NULL Input
  {
    assert(reverseString(nullptr) == nullptr);
    std::cout << "Test 7 Passed\n";
  }

  // Test Case 8: All Same Characters
  {
    const char *input = "aaaaa";
    char *output = reverseString(input);
    assert(strcmp(output, "aaaaa") == 0);
    free(output);
    std::cout << "Test 8 Passed\n";
  }

  // Test Case 9: Mixed Case Letters
  {
    const char *input = "AbCd";
    char *output = reverseString(input);
    assert(strcmp(output, "dCbA") == 0);
    free(output);
    std::cout << "Test 9 Passed\n";
  }

  // Test Case 10: Numeric String
  {
    const char *input = "12345";
    char *output = reverseString(input);
    assert(strcmp(output, "54321") == 0);
    free(output);
    std::cout << "Test 10 Passed\n";
  }

  // Test Case 11: Palindrome
  {
    const char *input = "madam";
    char *output = reverseString(input);
    assert(strcmp(output, "madam") == 0);
    free(output);
    std::cout << "Test 11 Passed\n";
  }

  // Test Case 12: Long String
  {
    const char *input = "abcdefghijklmnopqrstuvwxyz";
    char *output = reverseString(input);
    assert(strcmp(output, "zyxwvutsrqponmlkjihgfedcba") == 0);
    free(output);
    std::cout << "Test 12 Passed\n";
  }

  std::cout << "All Tests Passed!\n\n";
}

void testFindMiddle() {
  // Test Case 1: Empty List
  {
    struct Node *head = NULL;
    assert(findMiddle(head) == NULL);
    printf("Test 1 Passed\n");
  }

  // Test Case 2: Single Node
  {
    struct Node *head = (Node *)malloc(sizeof(struct Node));
    head->value = 1;
    head->next = NULL;
    assert(findMiddle(head) == head);
    free(head);
    printf("Test 2 Passed\n");
  }

  // Test Case 3: Two Nodes (Even)
  {
    struct Node *node1 = (Node *)malloc(sizeof(struct Node));
    struct Node *node2 = (Node *)malloc(sizeof(struct Node));
    node1->value = 1;
    node1->next = node2;
    node2->value = 2;
    node2->next = NULL;
    assert(findMiddle(node1)->value == 2); // Middle is second node
    free(node1);
    free(node2);
    printf("Test 3 Passed\n");
  }

  // Test Case 4: Three Nodes (Odd)
  {
    struct Node *node1 = (Node *)malloc(sizeof(struct Node));
    struct Node *node2 = (Node *)malloc(sizeof(struct Node));
    struct Node *node3 = (Node *)malloc(sizeof(struct Node));
    node1->value = 1;
    node1->next = node2;
    node2->value = 2;
    node2->next = node3;
    node3->value = 3;
    node3->next = NULL;
    assert(findMiddle(node1)->value == 2); // Middle is second node
    free(node1);
    free(node2);
    free(node3);
    printf("Test 4 Passed\n");
  }

  // Test Case 5: Four Nodes (Even)
  {
    struct Node *node1 = (Node *)malloc(sizeof(struct Node));
    struct Node *node2 = (Node *)malloc(sizeof(struct Node));
    struct Node *node3 = (Node *)malloc(sizeof(struct Node));
    struct Node *node4 = (Node *)malloc(sizeof(struct Node));
    node1->value = 1;
    node1->next = node2;
    node2->value = 2;
    node2->next = node3;
    node3->value = 3;
    node3->next = node4;
    node4->value = 4;
    node4->next = NULL;
    assert(findMiddle(node1)->value == 3); // Middle is third node
    free(node1);
    free(node2);
    free(node3);
    free(node4);
    printf("Test 5 Passed\n");
  }

  // Test Case 6: Five Nodes (Odd)
  {
    struct Node *nodes[5];
    for (int i = 0; i < 5; i++) {
      nodes[i] = (Node *)malloc(sizeof(struct Node));
      nodes[i]->value = i + 1;
      if (i > 0)
        nodes[i - 1]->next = nodes[i];
    }
    nodes[4]->next = NULL;
    assert(findMiddle(nodes[0])->value == 3); // Middle is third node
    for (int i = 0; i < 5; i++)
      free(nodes[i]);
    printf("Test 6 Passed\n");
  }

  // Test Case 7: Six Nodes (Even)
  {
    struct Node *nodes[6];
    for (int i = 0; i < 6; i++) {
      nodes[i] = (Node *)malloc(sizeof(struct Node));
      nodes[i]->value = i + 1;
      if (i > 0)
        nodes[i - 1]->next = nodes[i];
    }
    nodes[5]->next = NULL;
    assert(findMiddle(nodes[0])->value == 4); // Middle is fourth node
    for (int i = 0; i < 6; i++)
      free(nodes[i]);
    printf("Test 7 Passed\n");
  }

  // Test Case 8: Seven Nodes (Odd)
  {
    struct Node *nodes[7];
    for (int i = 0; i < 7; i++) {
      nodes[i] = (Node *)malloc(sizeof(struct Node));
      nodes[i]->value = i + 1;
      if (i > 0)
        nodes[i - 1]->next = nodes[i];
    }
    nodes[6]->next = NULL;
    assert(findMiddle(nodes[0])->value == 4); // Middle is fourth node
    for (int i = 0; i < 7; i++)
      free(nodes[i]);
    printf("Test 8 Passed\n");
  }

  // Test Case 9: All Same Values (Even)
  {
    struct Node *node1 = (Node *)malloc(sizeof(struct Node));
    struct Node *node2 = (Node *)malloc(sizeof(struct Node));
    struct Node *node3 = (Node *)malloc(sizeof(struct Node));
    struct Node *node4 = (Node *)malloc(sizeof(struct Node));
    node1->value = node2->value = node3->value = node4->value = 0;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;
    assert(findMiddle(node1)->value == 0 && findMiddle(node1) == node3);
    free(node1);
    free(node2);
    free(node3);
    free(node4);
    printf("Test 9 Passed\n");
  }

  // Test Case 10: All Same Values (Odd)
  {
    struct Node *nodes[3];
    for (int i = 0; i < 3; i++) {
      nodes[i] = (Node *)malloc(sizeof(struct Node));
      nodes[i]->value = 0;
      if (i > 0)
        nodes[i - 1]->next = nodes[i];
    }
    nodes[2]->next = NULL;
    assert(findMiddle(nodes[0])->value == 0 &&
           findMiddle(nodes[0]) == nodes[1]);
    for (int i = 0; i < 3; i++)
      free(nodes[i]);
    printf("Test 10 Passed\n");
  }

  // Test Case 11: Alternating Values (Even)
  {
    struct Node *nodes[4];
    for (int i = 0; i < 4; i++) {
      nodes[i] = (Node *)malloc(sizeof(struct Node));
      nodes[i]->value = (i % 2 == 0) ? 1 : 2;
      if (i > 0)
        nodes[i - 1]->next = nodes[i];
    }
    nodes[3]->next = NULL;
    assert(findMiddle(nodes[0])->value == 1); // Third node (value 1)
    for (int i = 0; i < 4; i++)
      free(nodes[i]);
    printf("Test 11 Passed\n");
  }

  // Test Case 12: Alternating Values (Odd)
  {
    struct Node *nodes[5];
    for (int i = 0; i < 5; i++) {
      nodes[i] = (Node *)malloc(sizeof(struct Node));
      nodes[i]->value = (i % 2 == 0) ? 1 : 2;
      if (i > 0)
        nodes[i - 1]->next = nodes[i];
    }
    nodes[4]->next = NULL;
    assert(findMiddle(nodes[0])->value == 1); // Third node (value 1)
    for (int i = 0; i < 5; i++)
      free(nodes[i]);
    printf("Test 12 Passed\n");
  }

  printf("All Tests Passed!\n\n");
}

void testFibonacci() {
  // Test Case 1: n = 0 (base case)
  assert(fibonacci(0) == 0);
  std::cout << "Test 1 Passed\n";

  // Test Case 2: n = 1 (base case)
  assert(fibonacci(1) == 1);
  std::cout << "Test 2 Passed\n";

  // Test Case 3: n = 2 → 0 + 1 = 1
  assert(fibonacci(2) == 1);
  std::cout << "Test 3 Passed\n";

  // Test Case 4: n = 3 → 1 + 1 = 2
  assert(fibonacci(3) == 2);
  std::cout << "Test 4 Passed\n";

  // Test Case 5: n = 4 → 1 + 2 = 3
  assert(fibonacci(4) == 3);
  std::cout << "Test 5 Passed\n";

  // Test Case 6: n = 5 → 2 + 3 = 5
  assert(fibonacci(5) == 5);
  std::cout << "Test 6 Passed\n";

  // Test Case 7: n = 6 → 3 + 5 = 8 (example from problem)
  assert(fibonacci(6) == 8);
  std::cout << "Test 7 Passed\n";

  // Test Case 8: n = 7 → 5 + 8 = 13
  assert(fibonacci(7) == 13);
  std::cout << "Test 8 Passed\n";

  // Test Case 9: n = 10 → 34 + 55 = 89 → 55 (n=10)
  assert(fibonacci(10) == 55);
  std::cout << "Test 9 Passed\n";

  // Test Case 10: n = 15 → 377 + 610 = 987 → 610 (n=15)
  assert(fibonacci(15) == 610);
  std::cout << "Test 10 Passed\n";

  // Test Case 11: n = 20 → 6765 (larger value)
  assert(fibonacci(20) == 6765);
  std::cout << "Test 11 Passed\n";

  // Test Case 12: n = 12 → 144
  assert(fibonacci(12) == 144);
  std::cout << "Test 12 Passed\n";

  std::cout << "All Tests Passed!\n";
}
