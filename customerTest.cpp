#include <iostream>
#include <string>
#include "Customer.h"
#include "Customer.cpp"

using namespace std;

int main() {
  Customer customer1("123", "Quan", "Vietnam", "0123456789");
  Customer customer2;

  customer1.details();
  customer2.details();

  return 0;
}
