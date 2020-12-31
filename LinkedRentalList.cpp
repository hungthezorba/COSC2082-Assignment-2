#include "LinkedRentalList.h"
#include "RentalListNode.h"
#include "RentalListNode.cpp"

using namespace std;

LinkedRentalList::LinkedRentalList() {
  head = nullptr;
}

LinkedRentalList::~LinkedRentalList() {
  // TODO:: Free memory allocated to linked list
}

// Add item to the beginning of LinkedRentalList
void LinkedRentalList::addItem(string s) {
  if (head == nullptr) {
    // New item, make head point to it
    head = new RentalListNode(s, nullptr);
  } else {
    // Make a new node that points to head
    RentalListNode *temp = new RentalListNode(s, head);

    /* Attempt to append item to LinkedRentalList
    // Create new node and point to head
    RentalListNode *temp = head;

    // Traverse to next node until temp point to nullptr
    while (temp != nullptr) {
      temp = temp->getNext();
    }

    // Create new node and get s (item)
    temp = new RentalListNode(s, nullptr);
    */

    // Set head to the new node
    head = temp;
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

int main() {
  LinkedRentalList list1;

  list1.addItem("Superhero");
  list1.addItem("SpoderMen");
  list1.addItem("Sadman");

  list1.showItem();

  cout << "still fucking working!" << endl;

  return 0;
}
