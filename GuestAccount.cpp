#include "GuestAccount.h"
#include <iostream>

using namespace std;

// Constructors
GuestAccount::GuestAccount() {

}

GuestAccount::GuestAccount(string id, string name, string address, string phoneNumber, int numberOfRental) : Customer(id, name, address, phoneNumber, numberOfRental) {

}


// Member functions
void GuestAccount::rentItem(const string itemName) {
  if (this->getNumberOfRental() < GUEST_RENTAL_LIMIT) {
    this->Customer::rentItem(itemName);
	// Increase current rentals
  } else {
    cout << "Sorry! Guest member can only rent a maximum of " << GUEST_RENTAL_LIMIT << " at a time!" << endl;
    cout << "Please return your rented items first!" << endl;
  }
}

void GuestAccount::returnItem(const string itemName) {
  this->Customer::returnItem(itemName);
  // Reduce current rentals
}

void GuestAccount::details() {
	cout << "Customer ID: " << this->getId() << endl;
	cout << "1. Name: " << this->getName() << endl;
	cout << "2. Address: " << this->getAddress() << endl;
	cout << "3. Phone Number: " << this->getPhoneNumber() << endl;
	cout << "4. Type: Guest" << endl;
}

void GuestAccount::showRentalList() {
  this->Customer::showRentalList();
}
