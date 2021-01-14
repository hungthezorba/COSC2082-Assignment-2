//
// Created by Enterprise on 12/27/2020.
//

#include "LinkedCustomer.h"
#include "CustomerNode.h"
#include "Customer.h"
#include<iostream>
#include<fstream>
#include "globalUtilities.h"


LinkedCustomer :: LinkedCustomer(){
    Head = NULL;
    temp = NULL;
    last = NULL;
    track = NULL;
    current = NULL;
}

//Copy Constructor
// References: https://stackoverflow.com/questions/7811893/creating-a-copy-constructor-for-a-linked-list
LinkedCustomer::LinkedCustomer(const LinkedCustomer & ll)
{
	if (ll.Head == NULL) {
		Head = NULL;
		return;
	}
	// Create a temp variable since ll.current doesn't move/change.
	CustomerNode* tmp = ll.Head;

	// Allocate a new node in memory.
	Head = new CustomerNode;
	// Copy over the value.
	Head->data = tmp->data;
	// Set the 'next' value to null (the loop will fill this in). 
	Head->next = NULL;
	// Point 'current' to 'head'.
	current = Head;

	// Move to next item in ll's list.
	tmp = tmp->next;

	while (tmp != NULL)
	{
		// Allocate new memory for a new 'node'.
		current->next = new CustomerNode;
		// Point to this new 'node'.
		current = current->next;
		// Copy over the data.
		current->data = tmp->data;
		// By default set the 'next' to null.
		current->next = NULL;
		// Move along ll's list.
		tmp = tmp->next;
	}
}

CustomerNode *LinkedCustomer::getHead() const {
    return Head;
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
        cout << "-----------------------------------" << endl;
        temp = temp->next;
    }
};
//
//// Search customer by ID
CustomerNode *LinkedCustomer::searchCustomerByID(string id){
    temp = Head;
    track = Head;

    while(temp!=NULL && toLowerCase(temp->data->getId()) != toLowerCase(id)){
        track = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        // No need to print message in this function. Message will be carried out by menu.
        return NULL;
    }
    return temp;
};

LinkedCustomer LinkedCustomer::searchCustomerByName(string name) {
	temp = Head;
	track = Head;

	// Initial customer list
	LinkedCustomer tempList;

	while (temp != NULL) {
		// If match name.
		// We converted name to lowercase to increase roburstness and flexibility.
		if (toLowerCase(temp->data->getName()) == toLowerCase(name)) {
			tempList.addCustomer(temp->data); // Add to list
		}
		track = temp;
		temp = temp->next;
	}
	return tempList;
}
// Delete item by ID
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
            delete temp->data; // free memory
            delete temp; // free memory
            return;
        }
        track = temp; // track will keep the behind item of the current item in case found item to delete.
        temp = temp->next;
    }

}

// Sorted by id. Directly affect on linked list so need to create a deep copy linked list.
void LinkedCustomer::sortedByID() {
    // The function enhance on this program
    // References: https://www.javatpoint.com/program-to-sort-the-elements-of-the-singly-linked-list
    current = Head;
    track = NULL;

    if (Head == NULL)
        return;
    else {
        while (current != NULL) {
            track = current-> next;
            while (track != NULL) {
                if (stoi(current->data->getId().substr(1, 3)) > stoi(track->data->getId().substr(1, 3))) {
                    Customer *temp = current->data;
                    current->data = track->data;
                    track->data = temp;
                }

                track = track->next;
            }

            current = current->next;
        }

    }

}

// Sorted by title. Directly affect on linked list so need to create a deep copy linked list.
void LinkedCustomer::sortedByName() {
    current = Head;
    track = NULL;

    if (Head == NULL)
        return;
    else {
        while (current != NULL) {
            track = current->next;
            while (track != NULL) {
                if (toLowerCase(current->data->getName()) > toLowerCase(track->data->getName())) {
                    Customer *temp = current->data;
                    current->data = track->data;
                    track->data = temp;
                }

                track = track->next;
            }

            current = current->next;
        }

    }

}




CustomerNode* LinkedCustomer::getHead() {
	return Head;
}

void LinkedCustomer::Output(LinkedCustomer* list) {
	ofstream out;
	out.open("customers.txt");
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
