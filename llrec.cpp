#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
  // Base case: we made it to the end of the original list
  if(head == nullptr){
    smaller = nullptr;
    larger = nullptr;
    return;
  }

  // Need to store the next node before changing the head
  Node* nextN = head->next;

  // Recursive cases
  if(head->val <= pivot){
    smaller = head;
    smaller->next = nullptr;
    llpivot(nextN, smaller->next, larger, pivot);
  }
  else{
    larger = head;
    larger->next = nullptr;
    llpivot(nextN, smaller, larger->next, pivot);
  }

  head = nullptr; // Making sure head is disconnected from rest of list
}