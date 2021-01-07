//
// Created by Enterprise on 12/27/2020.
//

#include "LinkedCustomer.h"
#include "CustomerNode.h"
#include "Customer.h"

LinkedCustomer :: LinkedCustomer(){
    Head = NULL;
    temp = NULL;
    last = NULL;
    track = NULL;
    current = NULL;
}

//Copy Constructor
// References: https://stackoverflow.com/questions/7811893/creating-a-copy-constructor-for-a-linked-list
LinkedCustomer::LinkedCustomer(const LinkedCustomer &itemList)
{
    CustomerNode * p1 = 0;//current
    CustomerNode * p2 = 0;//next

    if (itemList.Head == 0)
        Head = 0;

    else
    {
        Head = new CustomerNode;
        Head->next = itemList.Head->next;
        Head->data = itemList.Head->data;

        p1 = Head;
        p2 = itemList.Head->next;
    }

    while (p2)
    {
        p1->next = new CustomerNode;
        p1 = p1->next;
        p1->data = p2->data;

        p2 = p2->next;
    }
    p1->next = 0;
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

LinkedCustomer LinkedCustomer::searchCustomerByName(string name) {
	temp = Head;
	track = Head;

	// Initial customer list
	LinkedCustomer tempList;

	while (temp != NULL) {
		// If match name
		if (temp->data->getName() == name) {
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
                if (current->data->getName() > track->data->getName()) {
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
