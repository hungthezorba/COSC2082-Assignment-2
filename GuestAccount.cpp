#include "GuestAccount.h"
#include <iostream>

using namespace std;

GuestAccount::GuestAccount() {

}

GuestAccount::GuestAccount(string id, string name, string address, string phoneNumber) : Customer(id, name, address, phoneNumber) {

}

void GuestAccount::rentItem() {
  cout << "Guest renting item.." << endl;
}

void GuestAccount::returnItem() {
  cout << "Guest returning item.." << endl;
}

void GuestAccount::details() {
  cout << this->getId();
  cout << ", " << this->getName();
  cout << ", " << this->getAddress();
  cout << ", " << this->getPhoneNumber() << endl;
}
