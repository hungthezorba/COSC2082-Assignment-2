#pragma once

#include "Customer.h"

#define REGULAR_PROMOTION_CONDITION 3

class RegularAccount : public Customer {
private:


public:
  // Constructors
  RegularAccount();

  RegularAccount(string id, string name, string address, string phoneNumber);

  // Member functions
  void rentItem(const string itemName);

  void returnItem(const string itemName);

  void details();

  void showRentalList();

};
