#pragma once

#include <string>
#include "RentalListNode.h"
#include "LinkedRentalList.h"
#include "LinkedItem.h"

using namespace std;

class Customer {
private:
  string id;
  string name;
  string address;
  string phoneNumber;
  int numberOfRental;
  string type;
  int numberOfReturnedItems;
  LinkedRentalList rentalList;

public:
  // Constructor
  Customer();


    Customer(string id, string name, string address, string phoneNumber, int numberOfRental);

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

  int getNumberOfRental();

  void setNumberOfRental(const int numberOfRental);

  int getNumberOfReturnedItems();

  void setNumberOfReturnedItems(const int numberOfReturnedItems);

  string getType() const;

  void setType(const string &typeCustomer);

  LinkedRentalList *getRentalList();
  LinkedRentalList getRentalList2();

  void setRentalList(LinkedRentalList &rentalList);

  // Polymorphism functions
  virtual void details();

  virtual void showRentalList();

  virtual void rentItem(const string itemName, LinkedItem &itemList);

  virtual void returnItem(const string itemName);
  virtual int typeCustomer();

};
