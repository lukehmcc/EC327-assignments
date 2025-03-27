#include "examextra_problem2.h"
#include <iostream>
#include <limits>

void llprinter(Node *head) {
  if (head == nullptr) {
    return;
  }
  int c = 1;
  Node *current = head;
  while (current != nullptr) {
    std::cout << c << ":" << current->data << " -> ";
    c++;
    current = current->next;
  }
  std::cout << std::endl;
}

Node *insertAtPosition(Node *head, int value, int position) {
  if (position < 1) {
    return head;
  }
  if (position == 1 || head == nullptr) {
    Node *newHead = new Node{value, head};
    return newHead;
  }
  Node *currentHead = head;
  for (int i = 1; i < position - 1; i++) {
    if (currentHead->next == nullptr) {
      return head;
    }
    currentHead = currentHead->next;
  }
  Node *newNode = new Node{value, currentHead->next};
  currentHead->next = newNode;
  return head;
}

Node *deleteAtPosition(Node *head, int position) {
  if (head == nullptr) {
    return nullptr;
  }
  if (position < 1) {
    return head;
  }
  if (position == 1) {
    return head->next;
  }
  Node *currentHead = head;
  for (int i = 1; i < position - 1; i++) {
    if (currentHead->next == nullptr) {
      return head;
    }
    currentHead = currentHead->next;
  }
  if (head->next->next == nullptr) {
    return head;
  }
  Node *toDelete = currentHead->next;
  currentHead->next = currentHead->next->next;
  delete toDelete;
  return head;
}

int findGreatestProduct(Node *head) {
  if (head == nullptr) {
    return 0;
  }
  Node *current = head;
  int biggest = std::numeric_limits<int>::min();
  int almostBiggest = std::numeric_limits<int>::min();
  int c = 0;
  while (current != nullptr) {
    if (current->data > biggest) {
      int tmpBiggest = biggest;
      biggest = current->data;
      if (tmpBiggest > almostBiggest) {
        almostBiggest = tmpBiggest;
      }
    } else {
      if (current->data > almostBiggest) {
        almostBiggest = current->data;
      }
    }
    current = current->next;
    c++;
  }
  if (c < 2) {
    return 0;
  }
  return biggest * almostBiggest;
}
