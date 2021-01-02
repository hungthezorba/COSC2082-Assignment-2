#pragma once

#include <string>
#include "RentalListNode.h"
#include "LinkedRentalList.h"

using namespace std;

class Customer {
private:
  string id;
  string name;
  string address;
  string phoneNumber;
  LinkedRentalList rentalList;

public:
  // Constructor
  Customer();
  Customer(string id, string name, string address, string phoneNumber);

  /* Destructor
     ~Customer(); */

  // Methods
  string getId() const;

  void setId(const string id);

  string getName() const;

  void setName(const string name);

  string getAddress() const;

  void setAddress(const string address);

  string getPhoneNumber() const;

  void setPhoneNumber(const string phoneNumber);

  // Polymorphism functions
  virtual void details();

  virtual void showRentalList();

  virtual void rentItem(const string itemName);

  virtual void returnItem(const string itemName);
};
