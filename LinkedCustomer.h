//
// Created by Enterprise on 12/27/2020.
//
#include "Customer.h"
#include "CustomerNode.h"
#ifndef LINKEDCUSTOMER_H
#define LINKEDCUSTOMER_H
class LinkedCustomer{
private:
    CustomerNode *Head;
    CustomerNode *temp;
    CustomerNode *last;
    CustomerNode *track;
public:
    LinkedCustomer();
    void addCustomer(Customer *newItem);
    void deleteCustomer(string id);
    CustomerNode*searchCustomerByID(string id);
	LinkedCustomer searchCustomerByName(string name);
	CustomerNode* getHead();
    void printAllCustomer();

    CustomerNode *getHead() const;


};

#endif //ASSIGN2_LINKEDCUSTOMER_H
