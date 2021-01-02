#include "GuestAccount.h"
#include <iostream>

using namespace std;

// Constructors
GuestAccount::GuestAccount() {
  currentRentingItemCount = 0;
}

GuestAccount::GuestAccount(string id, string name, string address, string phoneNumber) : Customer(id, name, address, phoneNumber) {
  currentRentingItemCount = 0;
}


// Member functions
void GuestAccount::rentItem(const string itemName) {
  if (currentRentingItemCount < GUEST_RENTAL_LIMIT) {
    this->Customer::rentItem(itemName);
    currentRentingItemCount++;
  } else {
    cout << "Sorry! Guest member can only rent a maximum of " << GUEST_RENTAL_LIMIT << " at a time!" << endl;
    cout << "Please return your rented items first!" << endl;
  }
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
