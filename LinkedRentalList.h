#pragma once

#include "RentalListNode.h"
#include <iostream>

using namespace std;

class LinkedRentalList {
private:
  RentalListNode* head;

public:
  LinkedRentalList();
  ~LinkedRentalList();

  void addItem(string s); // Adds to front
  void removeItem(string s); // Delete first occurence of s in the list
  void showItem(); // Show all elements in the RentalListNode
};
