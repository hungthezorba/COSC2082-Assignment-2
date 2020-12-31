#include "VipAccount.h"
#include "Customer.h"
#include <iostream>

using namespace std;

VipAccount::VipAccount() {
  this->rewardPoints = 0;
}

VipAccount::VipAccount(string id, string name, string address, string phoneNumber) : Customer(id, name, address, phoneNumber) {
  this->rewardPoints = 0;
}

void VipAccount::rentItem() {
  this->rewardPoints+=10;
  cout << "Guest renting item.." << endl;
}

void VipAccount::returnItem() {
  cout << "Guest returning item.." << endl;
}

void VipAccount::checkRewardPoints() {
  cout << "Your total reward points: " << this->rewardPoints << endl;
}

void VipAccount::freeRentItem() {
  if (this->rewardPoints >= 100) {
    cout << "Congratulations " << this->getName() << ", you are eligible to exchange for 1 free rent item!" << endl;
  } else {
    cout << "Sorry " << this->getName() << ", you need 100 points to exchange for a free rent item!" << endl;
  }
}

void VipAccount::details() {
  cout << this->getId();
  cout << ", " << this->getName();
  cout << ", " << this->getAddress();
  cout << ", " << this->getPhoneNumber() << endl;
}
