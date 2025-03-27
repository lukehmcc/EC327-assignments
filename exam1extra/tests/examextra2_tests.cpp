#include "../src/examextra_problem2.h"
#include <gtest/gtest.h>

class LinkedListTest : public ::testing::Test {
protected:
  Node *head = nullptr;

  void TearDown() override {
    // Clean up all nodes after each test
    while (head) {
      Node *temp = head;
      head = head->next;
      delete temp;
    }
  }
};

TEST_F(LinkedListTest, InsertAtPosition_EmptyList) {
  head = insertAtPosition(nullptr, 10, 1);
  ASSERT_NE(head, nullptr);
  EXPECT_EQ(head->data, 10);
  EXPECT_EQ(head->next, nullptr);
}

TEST_F(LinkedListTest, InsertAtPosition_InvalidPosition) {
  head = new Node{5, nullptr};
  Node *original = head;
  head = insertAtPosition(head, 10, 0); // Too small
  EXPECT_EQ(head, original);
  head = insertAtPosition(head, 10, 3); // Too large
  EXPECT_EQ(head, original);
}

TEST_F(LinkedListTest, InsertAtPosition_Beginning) {
  head = new Node{2, new Node{3, nullptr}};
  head = insertAtPosition(head, 1, 1);
  EXPECT_EQ(head->data, 1);
  EXPECT_EQ(head->next->data, 2);
  EXPECT_EQ(head->next->next->data, 3);
}

TEST_F(LinkedListTest, InsertAtPosition_Middle) {
  head = new Node{1, new Node{3, nullptr}};
  head = insertAtPosition(head, 2, 2);
  EXPECT_EQ(head->data, 1);
  EXPECT_EQ(head->next->data, 2);
  EXPECT_EQ(head->next->next->data, 3);
}

TEST_F(LinkedListTest, InsertAtPosition_End) {
  head = new Node{1, new Node{2, nullptr}};
  head = insertAtPosition(head, 3, 3);
  EXPECT_EQ(head->data, 1);
  EXPECT_EQ(head->next->data, 2);
  EXPECT_EQ(head->next->next->data, 3);
}

TEST_F(LinkedListTest, DeleteAtPosition_EmptyList) {
  head = deleteAtPosition(nullptr, 1);
  EXPECT_EQ(head, nullptr);
}

TEST_F(LinkedListTest, DeleteAtPosition_InvalidPosition) {
  head = new Node{1, new Node{2, nullptr}};
  Node *original = head;
  head = deleteAtPosition(head, 0); // Too small
  EXPECT_EQ(head, original);
  head = deleteAtPosition(head, 3); // Too large
  EXPECT_EQ(head, original);
}

TEST_F(LinkedListTest, DeleteAtPosition_Beginning) {
  head = new Node{1, new Node{2, new Node{3, nullptr}}};
  head = deleteAtPosition(head, 1);
  EXPECT_EQ(head->data, 2);
  EXPECT_EQ(head->next->data, 3);
}

TEST_F(LinkedListTest, DeleteAtPosition_Middle) {
  head = new Node{1, new Node{2, new Node{3, nullptr}}};
  head = deleteAtPosition(head, 2);
  EXPECT_EQ(head->data, 1);
  EXPECT_EQ(head->next->data, 3);
}

TEST_F(LinkedListTest, DeleteAtPosition_End) {
  head = new Node{1, new Node{2, new Node{3, nullptr}}};
  head = deleteAtPosition(head, 3);
  EXPECT_EQ(head->data, 1);
  EXPECT_EQ(head->next->data, 2);
  EXPECT_EQ(head->next->next, nullptr);
}

TEST_F(LinkedListTest, FindGreatestProduct_EmptyList) {
  EXPECT_EQ(findGreatestProduct(nullptr), 0);
}

TEST_F(LinkedListTest, FindGreatestProduct_SingleElement) {
  head = new Node{5, nullptr};
  EXPECT_EQ(findGreatestProduct(head), 0);
}

TEST_F(LinkedListTest, FindGreatestProduct_TwoElements) {
  head = new Node{3, new Node{7, nullptr}};
  EXPECT_EQ(findGreatestProduct(head), 21);
}

// Note, the autograder only wants the greates POSITIVE values
TEST_F(LinkedListTest, FindGreatestProduct_MultipleElements) {
  head = new Node{-5, new Node{2, new Node{-10, new Node{4, nullptr}}}};
  EXPECT_EQ(findGreatestProduct(head), 8); // 2 * 4 = 8
}

TEST_F(LinkedListTest, FindGreatestProduct_AllNegative) {
  head = new Node{-3, new Node{-1, new Node{-2, nullptr}}};
  EXPECT_EQ(findGreatestProduct(head), 2); // -1 * -2 = 2
}

TEST_F(LinkedListTest, FindGreatestProduct_AllPositive) {
  head = new Node{3, new Node{7, new Node{2, new Node{5, nullptr}}}};
  EXPECT_EQ(findGreatestProduct(head), 35); // 5 * 7 = 35
}
