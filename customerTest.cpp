#include <iostream>
#include <string>
#include "Customer.h"
#include "GuestAccount.h"
#include "RegularAccount.h"
#include "VipAccount.h"
#include "LinkedRentalList.h"
#include "RentalListNode.h"

#include "Customer.cpp"
#include "GuestAccount.cpp"
#include "RegularAccount.cpp"
#include "VipAccount.cpp"
#include "LinkedRentalList.cpp"
#include "RentalListNode.cpp"

using namespace std;

// int test() {
  int main() {
  // Test objects instantiation
  Customer customer1;
  Customer customer2("123", "Quan", "Vietnam", "0123456789");

  GuestAccount guest1;
  GuestAccount guest2("234", "Huan", "Ha Noi", "0123456789");

  RegularAccount regular1;
  RegularAccount regular2("456", "Hoa", "Ha Noi", "0123456789");

  VipAccount vip1;
  VipAccount vip2("789", "Huan Rose", "Ha Noi", "0123456789");


  // Test object methods
  // customer1.details(); // Empty object of Customer
  customer2.details();
  customer2.rentItem("PowerPuff Girls");
  customer2.rentItem("Sex in the city");
  customer2.showRentalList();
  customer2.returnItem("PowerPuff Girls");
  customer2.showRentalList();

  guest2.details();
  guest2.rentItem("Superhero");
  guest2.showRentalList();

  // guest1.details();
  // guest2.details();
  //
  // regular1.details();
  // regular2.details();
  //
  // vip1.details();
  // vip2.details();
  //
  // vip2.rentItem();
  // vip2.checkRewardPoints();
  // vip2.rentItem();
  // vip2.rentItem();
  // vip2.rentItem();
  // vip2.rentItem();
  // vip2.rentItem();
  // vip2.rentItem();
  // vip2.rentItem();
  // vip2.rentItem();
  // vip2.checkRewardPoints();
  // vip2.freeRentItem();
  // vip2.rentItem(); // 10 rents
  // vip2.checkRewardPoints();
  // vip2.freeRentItem();

  return 0;
}
