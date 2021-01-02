#pragma once

#include "Customer.h"
#define GUEST_RENTAL_LIMIT 2
#define GUEST_PROMOTION_CONDITION 3

class GuestAccount : public Customer {

public:
  // Constructors
  GuestAccount();

  GuestAccount(string id, string name, string address, string phoneNumber, int numberOfRental);

  // Member functions
  void rentItem(const string itemName);

  void returnItem(const string itemName);

  void details();

  void showRentalList();

};
