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
// Is List Rentals have this Id
bool LinkedRentalList::isListHaveId(string id) {
    RentalListNode* temp = head;
    while (temp != nullptr) {
        if (temp->getItem().compare(id) == 0) {
            return true;
        }
        temp = temp->getNext();
    }
    return false;
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
}

RentalListNode *LinkedRentalList::getHead() {
    return head;
}

ostream& operator<<(ostream& os, const LinkedRentalList& obj)
{
    RentalListNode* temp = obj.head;
    while (temp != nullptr) {
        os << temp->getItem() << endl;
        temp = temp->getNext();
    }
    return os;
}