#include "RegularAccount.h"
#include <iostream>

using namespace std;

RegularAccount::RegularAccount() {

}

RegularAccount::RegularAccount(string id, string name, string address, string phoneNumber) : Customer(id, name, address, phoneNumber) {

}

void RegularAccount::rentItem() {
  cout << "Regular account renting item.." << endl;
}

void RegularAccount::returnItem() {
  cout << "Regular account returning item.." << endl;
}

void RegularAccount::details() {
  cout << this->getId();
  cout << ", " << this->getName();
  cout << ", " << this->getAddress();
  cout << ", " << this->getPhoneNumber() << endl;
}
