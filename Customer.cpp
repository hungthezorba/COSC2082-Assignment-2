#include "Customer.h"
#include <iostream>

using namespace std;

Customer::Customer() {
  this->id = "NA";
  this->name = "NA";
  this->address = "NA";
  this->phoneNumber = "NA";
}

Customer::Customer(string id, string name, string address, string phoneNumber) {
  this->id = id;
  this->name = name;
  this->address = address;
  this->phoneNumber = phoneNumber;
}

string Customer::getId() const {
  return id;
}

void Customer::setId(string id) {
  this->id = id;
}

string Customer::getName() const {
  return name;
}

void Customer::setName(string name) {
  this->name = name;
}

string Customer::getAddress() const {
  return address;
}

void Customer::setAddress(string address) {
  this->address = address;
}

string Customer::getPhoneNumber() const {
  return phoneNumber;
}

void Customer::setPhoneNumber(string phoneNumber) {
  this->phoneNumber = phoneNumber;
}

void Customer::details() {
  cout << this->id;
  cout << ", " << this->name;
  cout << ", " << this->address;
  cout << ", " << this->phoneNumber << endl;
}

void Customer::showRentalList() {
  rentalList.showItem();
}

void Customer::rentItem(const string itemName) {
  rentalList.addItem(itemName);
}

void Customer::returnItem(const string itemName) {
  rentalList.removeItem(itemName);
}
