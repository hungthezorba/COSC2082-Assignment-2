#pragma once

#include <string>

using namespace std;

class Customer {
  private:
    string id;
    string name;
    string address;
    string phoneNumber;
    // rentalList not implemented
    string rentalList;

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

    // Print Customer details
    virtual void details();

};
