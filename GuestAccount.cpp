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
    cout << "Guest customer " << this->getName() << " rented item successfully!" << endl;
    this->Customer::rentItem(itemName);
	// Increase current rentals
  } else {
    cout << "Sorry! Guest member can only rent a maximum of " << GUEST_RENTAL_LIMIT << " at a time!" << endl;
    cout << "Please return your rented items first!" << endl;
  }
}

void GuestAccount::returnItem(const string itemName) {
  cout << "Guest customer " << this->getName() << " returned item successfully!" << endl;
  this->Customer::returnItem(itemName);
  // Reduce current rentals
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
int GuestAccount::typeCustomer() {
    return 3;
}