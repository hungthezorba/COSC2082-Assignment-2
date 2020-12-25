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
    string phone;
    // Implement Linked List
    string rentals;

  public:
    // Constructor
    Customer(string id, string name, string address, string phone);

    // Destructor
    ~Customer();

    // Methods
    const string getId();
    void setId(const string &id);
};


#endif
