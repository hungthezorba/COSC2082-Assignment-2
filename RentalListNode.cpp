#include "RentalListNode.h"

RentalListNode::RentalListNode()
  : item(""), next(NULL) {}

RentalListNode::RentalListNode(string itemName, RentalListNode* nextNode)
  : item(itemName), next(nextNode) {}

string RentalListNode::getItem() {
  return item;
}

RentalListNode* RentalListNode::getNext() {
  return next;
}

void RentalListNode::setNext(RentalListNode *newNext) {
  next = newNext;
}

