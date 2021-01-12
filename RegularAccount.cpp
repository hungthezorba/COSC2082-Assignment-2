#include "RegularAccount.h"
#include <iostream>

using namespace std;

// Constructors
RegularAccount::RegularAccount() {
this->setType("Regular");
this->setNumberOfReturnedItems(0);
}

RegularAccount::RegularAccount(string id, string name, string address, string phoneNumber, int numberOfRental) : Customer(id, name, address, phoneNumber, numberOfRental) {
this->setType("Regular");
this->setNumberOfReturnedItems(0);
}

// Member Functions
void RegularAccount::rentItem(const string itemName) {
	// This work fine, but the pattern is weird. Need to refactor
  this->Customer::rentItem(itemName);
  cout << "Regular customer " << this->getName() << " rented item successfully!" << endl;
}

void RegularAccount::returnItem(const string itemName) {
	// This work fine, but the pattern is weird. Need to refactor
  cout << "Guest customer " << this->getName() << " returned item successfully!" << endl;
  this->Customer::returnItem(itemName);
}

void RegularAccount::details() {
	cout << "Customer ID: " << this->getId() << endl;
	cout << "Type: Regular" << endl;
	cout << "1. Name: " << this->getName() << endl;
	cout << "2. Address: " << this->getAddress() << endl;
	cout << "3. Phone Number: " << this->getPhoneNumber() << endl;
}

void RegularAccount::showRentalList() {
  this->Customer::showRentalList();
}
int RegularAccount::typeCustomer() {
	return 1;
}
