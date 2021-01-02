#include "GuestAccount.h"
#include <iostream>

using namespace std;

// Constructors
GuestAccount::GuestAccount() {

}

GuestAccount::GuestAccount(string id, string name, string address, string phoneNumber) : Customer(id, name, address, phoneNumber) {

}


// Member functions
void GuestAccount::rentItem(const string itemName) {
  this->Customer::rentItem(itemName);
}

void GuestAccount::returnItem(const string itemName) {
  this->Customer::returnItem(itemName);
}

void GuestAccount::details() {
  cout << this->getId();
  cout << ", " << this->getName();
  cout << ", " << this->getAddress();
  cout << ", " << this->getPhoneNumber() << endl;
}

void GuestAccount::showRentalList() {
  this->Customer::showRentalList();
}
