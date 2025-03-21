#include "lab3_problem3.h"
#include <cstddef>

int linkedListLength(struct Node *head);
Node *getNodeAtIndex(struct Node *head, int index);

// Returns a pointer to the middle of a linked list
struct Node *findMiddle(struct Node *head) {
  if (head == NULL) {
    return NULL;
  };
  int length = linkedListLength(head);
  int middle = (length / 2);
  // if (length % 2 == 0) {
  //   middle++;
  // }
  // std::cout << "Length: " << length << " Middle:" << middle << "\n";
  return getNodeAtIndex(head, middle);
}

Node *getNodeAtIndex(struct Node *head, int index) {
  Node *currentHead = head;
  // printList(currentHead);
  for (int i = 0; i < index; i++) {
    currentHead = currentHead->next;
  }
  return currentHead;
}

int linkedListLength(struct Node *head) {
  int lengthCounter = 0;
  Node *currentHead = head;
  while (currentHead != NULL) {
    currentHead = currentHead->next;
    lengthCounter++;
  }
  return lengthCounter;
}
