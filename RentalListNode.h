#pragma once

#include <string>

using namespace std;

class RentalListNode {
private:
  string item;
  RentalListNode* next;

public:
  RentalListNode();
  RentalListNode(string itemName, RentalListNode* nextNode);

  string getItem();

  RentalListNode* getNext();
  void setNext(RentalListNode *newNext);
};

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
