//
// Created by Enterprise on 12/27/2020.
//

#include "LinkedCustomer.h"
#include "CustomerNode.h"
#include "Customer.h"
#include<iostream>
#include<fstream>

LinkedCustomer :: LinkedCustomer(){
    Head = NULL;
    temp = NULL;
    last = NULL;
    track = NULL;
}

// Add item to linked list
void LinkedCustomer::addCustomer(Customer *newItem) {
    CustomerNode* newPtr = new CustomerNode;
    newPtr->data = newItem;
    newPtr->next = NULL;
    if(Head == NULL){
        Head = newPtr;
    }
    else{
        temp = Head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newPtr;
    }
}
//
//
// Print all item
void LinkedCustomer::printAllCustomer(){
    temp = Head;
    while(temp!=NULL){
        // Print first then move to jnext
        temp->data->details();
        temp = temp->next;
    }
};
//
//// Search item by ID
CustomerNode *LinkedCustomer::searchCustomer(string id){

    temp = Head;
    track = Head;
    while(temp!=NULL && temp->data->getId()!=id){
        track = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        // No need to print message in this function. Message will be carried out by menu.
        return NULL;
    }
    return temp;
};
//
//// Delete item by ID
void LinkedCustomer::deleteCustomer(string id) {
    // Considering to refactor this function because there is a repeat part in find by id.
    temp = Head;
    track = temp;
    while(temp!=NULL){
        // Rewrite
        if (temp->data->getId() == id) {
            // Found match id
            if (temp != Head) {
                track->next = temp->next; // behind item now will point to front item of the deleted item
                temp->next = NULL; // deleted item will be remove the next
            }
            else {
                Head = temp->next;
            }
        }
        track = temp; // track will keep the behind item of the current item in case found item to delete.
        temp = temp->next;
    }

}
void LinkedCustomer::Output(LinkedCustomer* list) {
    ofstream out("customers.txt");
    CustomerNode* temp = list->Head;
    while (temp != NULL) {
        if (temp->data->typeCustomer() == 1) {
            out << temp->data->getId() << "," << temp->data->getName() << "," << temp->data->getAddress() << "," << temp->data->getPhoneNumber() << "," << temp->data->getNumberOfRental() << "," << "Regular" << endl;
            out << temp->data->getRentalList2();
        }
        if (temp->data->typeCustomer() == 2) {
            out << temp->data->getId() << "," << temp->data->getName() << "," << temp->data->getAddress() << "," << temp->data->getPhoneNumber() << "," << temp->data->getNumberOfRental() << "," << "VIP" << endl;
            out << temp->data->getRentalList2();
        }
        if (temp->data->typeCustomer() == 3) {
            out << temp->data->getId() << "," << temp->data->getName() << "," << temp->data->getAddress() << "," << temp->data->getPhoneNumber() << "," << temp->data->getNumberOfRental() << "," << "Guest" << endl;
            out << temp->data->getRentalList2();
        }
        
        temp = temp->next;
    }

}
