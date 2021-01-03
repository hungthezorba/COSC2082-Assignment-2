#include "Customer.h"
#include <iostream>

using namespace std;

Customer::Customer() {
  this->id = "NA";
  this->name = "NA";
  this->address = "NA";
  this->phoneNumber = "NA";
  this->numberOfRental = 0;
  this->rentalList;
}

Customer::Customer(string id, string name, string address, string phoneNumber, int numberOfRental) {
  this->id = id;
  this->name = name;
  this->address = address;
  this->phoneNumber = phoneNumber;
  this->numberOfRental = numberOfRental;
  this->rentalList;
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

int Customer::getNumberOfRental() {
	return numberOfRental;
}

void Customer::setNumberOfRental(const int numberOfRental) {
	this->numberOfRental = numberOfRental;
}

// This function will return the reference so when reading data from database, it can be used to add items in correct list.
LinkedRentalList *Customer::getRentalList() {
	return &rentalList;
}

void Customer::setRentalList(LinkedRentalList &rentalList) {
	this->rentalList = rentalList;
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
	this->numberOfRental++;
	rentalList.addItem(itemName);
}

void Customer::returnItem(const string itemName) {
	this->numberOfRental--;
  rentalList.removeItem(itemName);
}
