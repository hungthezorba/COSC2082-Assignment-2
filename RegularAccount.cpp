#include "RegularAccount.h"
#include <iostream>

using namespace std;

// Constructors
RegularAccount::RegularAccount() {
this->setTypeCustomer("Regular");
}

RegularAccount::RegularAccount(string id, string name, string address, string phoneNumber, int numberOfRental) : Customer(id, name, address, phoneNumber, numberOfRental) {
this->setTypeCustomer("Regular");
}

// Member Functions
void RegularAccount::rentItem(const string itemName) {
	// This work fine, but the pattern is weird. Need to refactor
  this->Customer::rentItem(itemName);
}

void RegularAccount::returnItem(const string itemName) {
	// This work fine, but the pattern is weird. Need to refactor
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
