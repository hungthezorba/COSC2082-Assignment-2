#pragma once

#include "Customer.h"
#define GUEST_RENTAL_LIMIT 2
#define GUEST_PROMOTION_CONDITION 3

class GuestAccount : public Customer {
private:
  int rentalCount = 0;


public:

};
