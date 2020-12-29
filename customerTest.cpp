#include <iostream>
#include <string>
#include "Customer.h"
#include "Customer.cpp"
#include "RegularAccount.h"

using namespace std;

int main() {
  Customer customer1("123", "Quan", "Vietnam", "0123456789");
  Customer customer2;
  RegularAccount regular1("123", "Teo", "HCM", "0903");

  customer1.details();
  customer2.details();
  regular1.details();

  return 0;
}
