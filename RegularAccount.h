#pragma once

#include "Customer.h"

#define REGULAR_PROMOTION_CONDITION 3

class RegularAccount : public Customer {
private:


public:
  // Constructors
  RegularAccount();

  RegularAccount(string id, string name, string address, string phoneNumber, int numberOfRental);

  // Member functions
  void rentItem(const string itemName, LinkedItem &itemList);

  void returnItem(const string itemName);

  void details();

  void showRentalList();

  int typeCustomer();

};
