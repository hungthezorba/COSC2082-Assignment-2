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
  int numberOfRental;
  LinkedRentalList rentalList;
  string typeCustomer;

public:
  // Constructor
  Customer();

    void setTypeCustomer(const string &typeCustomer);

    Customer(string id, string name, string address, string phoneNumber, int numberOfRental);

  /* Destructor
     ~Customer(); */

  // Methods
  const string &getTypeCustomer() const;

    string getId() const;

  void setId(const string id);

  string getName() const;

  void setName(const string name);

  string getAddress() const;

  void setAddress(const string address);

  string getPhoneNumber() const;

  void setPhoneNumber(const string phoneNumber);

  int getNumberOfRental();

  void setNumberOfRental(const int numberOfRental);

  LinkedRentalList *getRentalList();

  // Polymorphism functions
  virtual void details();

  virtual void showRentalList();

  virtual void rentItem(const string itemName);

  virtual void returnItem(const string itemName);
};
