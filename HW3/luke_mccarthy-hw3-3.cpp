#include "hw3_problem3.h"
#include <cstddef>

Node *insertInOrder(Node *head, int newValue) {
  Node *newNode = new Node{newValue, nullptr};
  printList(head);
  // If you don't check for a null list you'll try to index into something
  // nonexistant
  if (head == NULL) {
    printList(newNode);
    return newNode;
  }
  // Now we can index through safely
  if (head->value > newValue) {
    newNode->next = head;
    printList(newNode);
    return newNode;
  }
  Node *currentHead = head;
  while (currentHead->next != NULL && currentHead->next->value < newValue) {
    currentHead = currentHead->next;
  }
  newNode->next = currentHead->next;
  currentHead->next = newNode;
  printList(head);
  return head;
}
