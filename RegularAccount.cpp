#include "RegularAccount.h"
#include <iostream>

using namespace std;

// Constructors
RegularAccount::RegularAccount() {

}

RegularAccount::RegularAccount(string id, string name, string address, string phoneNumber) : Customer(id, name, address, phoneNumber) {

}

// Member Functions
void RegularAccount::rentItem(const string itemName) {
  this->Customer::rentItem(itemName);
}

void RegularAccount::returnItem(const string itemName) {
  this->Customer::returnItem(itemName);
}

void RegularAccount::details() {
  cout << this->getId();
  cout << ", " << this->getName();
  cout << ", " << this->getAddress();
  cout << ", " << this->getPhoneNumber() << endl;
}

void RegularAccount::showRentalList() {
  this->Customer::showRentalList();
}
