//
// Created by Huy on 12/24/20.
//

#ifndef CUSTOMERDATA_H
#define CUSTOMERDATA_H
using namespace std;

class Customer {

public: string ID;
public: string name;
public: string address;
public: string phone;
public: string numOfRentals;
public: string listOfRentals[100];
public: string typeCus;
};


int CustomerData();

#endif
