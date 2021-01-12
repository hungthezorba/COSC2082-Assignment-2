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
    CustomerNode *current;

public:
    LinkedCustomer();
    LinkedCustomer(const LinkedCustomer &itemList);
    void addCustomer(Customer *newItem);
    void deleteCustomer(string id);
    CustomerNode*searchCustomerByID(string id);
	LinkedCustomer searchCustomerByName(string name);
	CustomerNode* getHead();
    void sortedByID();
    void sortedByName();
    void printAllCustomer();

    CustomerNode *getHead() const;

    void Output(LinkedCustomer* list);

};

#endif //ASSIGN2_LINKEDCUSTOMER_H
