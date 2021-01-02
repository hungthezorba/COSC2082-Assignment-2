#include "LinkedRentalList.h"
#include "RentalListNode.h"

// #include "RentalListNode.cpp" // Delete this after testing is done

using namespace std;

LinkedRentalList::LinkedRentalList() {
  head = NULL;
}

LinkedRentalList::~LinkedRentalList() {
  // TODO:: Free memory allocated to linked list
}

// Add item to the beginning of LinkedRentalList
void LinkedRentalList::addItem(string s) {
	RentalListNode *node = new RentalListNode(s, NULL);
	RentalListNode *temp = head;

  if (head == NULL) {
    // New item, make head point to it
	  head = node;
  } else {
	// Check if next node is NULL
    while (temp->getNext() != NULL) {
      temp = temp->getNext();
    }
	// Set the next node(item)
	temp->setNext(node);
	// Head is always the first one so cannot set the head = temp
  }
}

void LinkedRentalList::removeItem(string s) {
  RentalListNode *temp = head;
  RentalListNode *prev = nullptr;

  while (temp != nullptr) {
    if (temp->getItem() == s) {
      if (prev == nullptr) {
        // Delete the head of the list
        head = head->getNext();
        delete temp;
      } else {
        prev->setNext(temp->getNext());
        delete temp;
      }
      break;
    }
    prev = temp;
    temp = temp->getNext();
  }
}

void LinkedRentalList::showItem() {
  RentalListNode *temp = head;
  while (temp != nullptr) {
    cout << temp->getItem() << endl;
    temp = temp->getNext();
  }
  cout << endl;
}
