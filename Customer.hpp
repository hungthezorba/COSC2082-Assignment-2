// COSC2082 - Assignment 2 - Quan Bui

#ifndef COSC2082_ASSIGNMENT_2_CUSTOMER_H
#define COSC2082_ASSIGNMENT_2_CUSTOMER_H
#include <iostream>
#include <string>

using namespace std;

class Customer {
  private:
    string id;
    string name;
    string address;
    string phoneNumber;
    // Implement Linked List
    string rentalList;

  public:
    // Constructor
    Customer(string id, string name, string address, string phone);

    // Destructor
    ~Customer();

    // Methods
    string getId() const;

    void setId(const string &id);

    string getName() const;

    void setName(const string name);

    string getAddress() const;

    void setAddress(const address);

    string getPhoneNumber() const;

    void setPhoneNumber(const string phoneNumber);

};


#endif
