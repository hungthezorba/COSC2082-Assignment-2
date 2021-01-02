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
