#pragma once

#include "Customer.h"

#define VIP_REWARD_EXCHANGE_CONDITION 100
#define VIP_REWARD_POINTS 10

class VipAccount : public Customer {
private:
  int rewardPoints;
  int freeRentItemAwarded;


public:
  // Constructors
  VipAccount();

  VipAccount(string id, string name, string address, string phoneNumber, int numberOfRental);

  // Member functions
  void rentItem(const string itemName, LinkedItem &itemList);

  void returnItem(const string itemName);

  void checkRewardPoints();

  void details();

  void showRentalList();

  int typeCustomer();
};
