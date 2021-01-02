#include "VipAccount.h"
#include "Customer.h"
#include <iostream>

using namespace std;

VipAccount::VipAccount() {
  this->rewardPoints = 0;
  this->freeItemAwarded = 0;
}

VipAccount::VipAccount(string id, string name, string address, string phoneNumber) : Customer(id, name, address, phoneNumber) {
  this->rewardPoints = 0;
  this->freeItemAwarded = 0;
}

void VipAccount::rentItem(const string itemName) {
  if (this->rewardPoints >= 100) {
    cout << "Congratulations " << this->getName() << ", you are eligible to exchange for 1 free rent item!" << endl;
    this->freeItemAwarded++;
    this->Customer::rentItem(itemName);
    this->rewardPoints-=100;
    cout << "Total of Free Rent Items awarded: " << freeItemAwarded << endl;
    cout << "Thank you so much, " << this->getName() << " for supporting our store <3" << endl;
    cout << endl;
  } else {
    this->Customer::rentItem(itemName);
    this->rewardPoints+=10;
    cout << "VIP customer " << this->getName() << " rented item successfully, you are rewarded 10 reward points!" << endl;
    cout << "Your current Reward Points: " << rewardPoints << endl;
    if (rewardPoints == 100) {
      cout << "You now have collected 100 Reward Points, you are eligible to exchange for a free rent item for your next purchase!" << endl;
    } else {
      cout << "Once you have collected 100 Reward Points, you are rewarded a Free Rent Item at our store!" << endl;
    }
    cout << endl;
  }
}

void VipAccount::returnItem(const string itemName) {
  this->Customer::returnItem(itemName);
  cout << "VIP customer " << this->getName() << " successfully returned an item!" << endl;
}

void VipAccount::checkRewardPoints() {
  cout << "Your total reward points: " << this->rewardPoints << endl;
}

void VipAccount::freeRentItem() {
  if (this->rewardPoints >= 100) {
    cout << "Congratulations " << this->getName() << ", you are eligible to exchange for 1 free rent item!" << endl;
    this->freeItemAwarded++;
  }
}

void VipAccount::details() {
  cout << "Customer's details:" << endl;
  cout << "ID: " << this->getId() << endl;
  cout << "Name: " << this->getName() << endl;
  cout << "Address: " << this->getAddress() << endl;
  cout << "Phone Number: " << this->getPhoneNumber() << endl;
  cout << "Reward Points: " << this->rewardPoints << endl;
}

void VipAccount::showRentalList() {
  this->Customer::showRentalList();
}
