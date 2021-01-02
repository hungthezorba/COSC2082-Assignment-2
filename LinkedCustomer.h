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
    CustomerNode*searchCustomer(string id);
    void printAllCustomer();


};

#endif //ASSIGN2_LINKEDCUSTOMER_H
