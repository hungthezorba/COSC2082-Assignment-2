#pragma once

#include "Customer.h"

#define VIP_REWARD_EXCHANGE_CONDITION 100
#define VIP_REWARD_POINTS 10

class VipAccount : public Customer {
private:
  int rewardPoints;

public:
  // Constructors
  VipAccount();

  VipAccount(string id, string name, string address, string phoneNumber);

  // Member functions
  void rentItem(const string itemName);

  void returnItem(const string itemName);

  void checkRewardPoints();

  void freeRentItem();

  void details();

  void showRentalList();

};
