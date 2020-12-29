#include <iostream>
#include <string>
#include "Customer.h"
#include "GuestAccount.h"
#include "RegularAccount.h"
#include "VipAccount.h"

#include "Customer.cpp"
#include "GuestAccount.cpp"
#include "RegularAccount.cpp"
#include "VipAccount.cpp"

using namespace std;

int main() {
  // Test objects instantiation
  Customer customer1;
  Customer customer2("123", "Quan", "Vietnam", "0123456789");

  GuestAccount guest1;
  GuestAccount guest2("234", "Huan", "Ha Noi", "0123456789");

  RegularAccount regular1;
  RegularAccount regular2("456", "Hoa", "Ha Noi", "0123456789");

  VipAccount vip1;
  VipAccount vip2("789", "Hong", "Ha Noi", "0123456789");


  // Test object methods
  customer1.details();
  customer2.details();

  guest1.details();
  guest2.details();

  regular1.details();
  regular2.details();

  vip1.details();
  vip2.details();

  vip2.rentItem();
  vip2.checkRewardPoints();
  vip2.rentItem();
  vip2.rentItem();
  vip2.rentItem();
  vip2.rentItem();
  vip2.rentItem();
  vip2.rentItem();
  vip2.rentItem();
  vip2.rentItem();
  vip2.checkRewardPoints();
  vip2.freeRentItem();
  vip2.rentItem(); // 10 rents
  vip2.checkRewardPoints();
  vip2.freeRentItem();

  return 0;
}
