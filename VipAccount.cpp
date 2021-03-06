#include "VipAccount.h"
#include "Customer.h"
#include <iostream>

using namespace std;

VipAccount::VipAccount() {
  this->rewardPoints = 0;
  this->freeRentItemAwarded = 0;
  this->setType("VIP");
  this->setNumberOfReturnedItems(0);
}

VipAccount::VipAccount(string id, string name, string address, string phoneNumber, int numberOfRental) : Customer(id, name, address, phoneNumber, numberOfRental) {
  this->rewardPoints = 0;
  this->freeRentItemAwarded = 0;
  this->setType("VIP");
  this->setNumberOfReturnedItems(0);
}

void VipAccount::rentItem(const string itemName, LinkedItem &itemList) {
  if (this->rewardPoints >= VIP_REWARD_EXCHANGE_CONDITION) {
    cout << "Congratulations " << this->getName() << ", you are eligible to exchange for 1 free rent item!" << endl;
    this->freeRentItemAwarded++;
    this->Customer::rentItem(itemName, itemList);
    this->rewardPoints-=VIP_REWARD_EXCHANGE_CONDITION;
    cout << "Total of Free Rent Items awarded: " << freeRentItemAwarded << endl;
    cout << "Thank you so much, " << this->getName() << " for supporting our store <3" << endl;
    cout << endl;
  } else {
    this->Customer::rentItem(itemName, itemList);
    this->rewardPoints+=VIP_REWARD_POINTS;
    cout << "VIP customer " << this->getName() << " rented item successfully, you are rewarded 10 reward points!" << endl;
    cout << "Your current Reward Points: " << rewardPoints << endl;
    if (rewardPoints == VIP_REWARD_EXCHANGE_CONDITION) {
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

void VipAccount::details() {
  cout << "Customer ID: "<< this->getId() << endl;
  cout << "Type: VIP - Reward Points: " << this->rewardPoints << endl;
  cout << "1. Name: " << this->getName() << endl;
  cout << "2. Address: " << this->getAddress() << endl;
  cout << "3. Phone Number: " << this->getPhoneNumber() << endl;
  cout << "Currently renting: " << endl;
  this->showRentalList();
}

void VipAccount::showRentalList() {
  this->Customer::showRentalList();
}
int VipAccount::typeCustomer() {
    return 2;
}
