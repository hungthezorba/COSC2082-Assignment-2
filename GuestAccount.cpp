#include "GuestAccount.h"
#include <iostream>

using namespace std;

// Constructors
GuestAccount::GuestAccount() {
this->setType("Guest");
this->setNumberOfReturnedItems(0);
}

GuestAccount::GuestAccount(string id, string name, string address, string phoneNumber, int numberOfRental) : Customer(id, name, address, phoneNumber, numberOfRental) {
this->setType("Guest");
this->setNumberOfReturnedItems(0);
}


// Member functions
void GuestAccount::rentItem(const string itemName, LinkedItem &itemList) {
  if (this->getNumberOfRental() < GUEST_RENTAL_LIMIT) {
	  ItemElement *item = itemList.searchItemByID(itemName);
	  if (item->data->getLoanType() != "1-week") {
		  cout << "FAIL: Guest member can only rent 1-week item." << endl;
	  }
	  else {
		  cout << "SUCCESS: Guest customer " << this->getName() << " rented item successfully!" << endl;
		  this->Customer::rentItem(itemName, itemList);
	  }
  } else {
    cout << "FAIL: Sorry! Guest member can only rent a maximum of " << GUEST_RENTAL_LIMIT << " items at a time!" << endl;
    cout << "FAIL: Please return your rented items first!" << endl;
  }
}

void GuestAccount::returnItem(const string itemName) {
  cout << "SUCCESS: Guest customer " << this->getName() << " returned item successfully!" << endl;
  this->Customer::returnItem(itemName);
  // Reduce current rentals
}

void GuestAccount::details() {
	cout << "Customer ID: " << this->getId() << endl;
	cout << "Type: Guest" << endl;
	cout << "1. Name: " << this->getName() << endl;
	cout << "2. Address: " << this->getAddress() << endl;
	cout << "3. Phone Number: " << this->getPhoneNumber() << endl;
	cout << "Currently renting: " << endl;
	this->showRentalList();
}

void GuestAccount::showRentalList() {
  this->Customer::showRentalList();
}
int GuestAccount::typeCustomer() {
    return 3;
}