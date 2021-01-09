//
// Created by Enterprise on 12/23/2020.
//
#include "Item.h"
#include <iostream>
#include "LinkedItem.h"
#include "ItemElement.h"
#include<iostream>
#include<fstream>

LinkedItem :: LinkedItem(){
    Head = NULL;
    last = NULL;
    track = NULL;
	current = NULL;
}

//Copy Constructor
// References: https://stackoverflow.com/questions/7811893/creating-a-copy-constructor-for-a-linked-list
LinkedItem::LinkedItem(const LinkedItem &l)
{
	ItemElement * p1 = 0;//current
	ItemElement * p2 = 0;//next

	if (l.Head == 0)
		Head = 0;

	else
	{
		Head = new ItemElement;
		Head->next = l.Head->next;
		Head->data = l.Head->data;

		p1 = Head;
		p2 = l.Head->next;
	}

	while (p2)
	{
		p1->next = new ItemElement;
		p1 = p1->next;
		p1->data = p2->data;

		p2 = p2->next;
	}
	p1->next = 0;
}


// Add item to linked list
void LinkedItem::addItem(Item *newItem) {
    ItemElement* newPtr = new ItemElement;
    newPtr->data = newItem;
	newPtr->next = NULL;
    if(Head == NULL){
        Head = newPtr;
    }
	else{
		current = Head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newPtr;
    }
}


// Print all items
void LinkedItem::printItem(){
    current = Head;
    while(current!=NULL){
		// Print first then move to jnext
		current->data->printDetail();
		current = current->next;
    }
};

// Print all out of stock items
void LinkedItem::printOutOfStockItem() {
	current = Head;
	while (current != NULL) {
		// Print first then move to jnext
		if (current->data->getNumberOfCopies() == 0) {
			current->data->printDetail();
		}
		current = current->next;
	}
}
// Increase Number Of Copies
void LinkedItem::IncreaseNumberOfCopies(string id) {
	current = Head;
	track = Head;
	while (current != NULL && current->data->getId() != id) {
		track = current;
		current = current->next;
	}
	int numOfCopies = current->data->getNumberOfCopies();
	current->data->setNumberOfCopies(numOfCopies + 1);
};
// Decrease Number Of Copies
void LinkedItem::DecreaseNumberOfCopies(string id) {
	current = Head;
	track = Head;
	while (current != NULL && current->data->getId() != id) {
		track = current;
		current = current->next;
	}
	int numOfCopies = current->data->getNumberOfCopies();
	current->data->setNumberOfCopies(numOfCopies - 1);
};
// Get object in list
void LinkedItem::Output(LinkedItem* list) {
	ofstream out("items.txt");
	ItemElement* temp = list->Head;
	while (temp != NULL) {
		if (temp->data->getGenre() != "") {
			out << temp->data->getId() << "," << temp->data->getTitle() << "," << temp->data->getRentalType() << "," << temp->data->getLoanType() << "," << temp->data->getNumberOfCopies() << "," << temp->data->getRentalFee() << "," << temp->data->getGenre() << endl;
		}
		else {
			out << temp->data->getId() << "," << temp->data->getTitle() << "," << temp->data->getRentalType() << "," << temp->data->getLoanType() << "," << temp->data->getNumberOfCopies() << "," << temp->data->getRentalFee()<< endl;
		}
		temp = temp->next;
	}
	
}
// Search item by ID
ItemElement *LinkedItem::searchItemByID(string id){
	
    current = Head;
    track = Head;
    while(current!=NULL && current->data->getId()!=id){
        track = current;
        current = current->next;
    }
    if(current == NULL){
        // No need to print message in this function. Message will be carried out by menu.
        return NULL;
    }
    return current;
};

ItemElement *LinkedItem::searchItemByTitle(string title) {
	current = Head;
	track = Head;
	while (current != NULL && current->data->getTitle() != title) {
		track = current;
		current = current->next;
	}
	if (current == NULL) {
		// No need to print message in this function. Message will be carried out by menu.
		return NULL;
	}
	return current;

};


// Delete item by ID
void LinkedItem::deleteItem(string id) {
	// Considering to refactor this function because there is a repeat part in find by id.
    current = Head;
    track = current;
    while(current!=NULL){
		// Rewrite
		if (current->data->getId() == id) {
			// Found match id
			if (current != Head) {
				track->next = current->next; // behind item now will point to front item of the deleted item
				current->next = NULL; // deleted item will be remove the next
			}
			else {
				Head = current->next;
			}
		}
        track = current; // track will keep the behind item of the current item in case found item to delete.
        current = current->next;
    }

}

// Sorted by id. Directly affect on linked list so need to create a deep copy linked list.
void LinkedItem::sortedByID() {
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
					Item *temp = current->data;
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
void LinkedItem::sortedByTitle() {
	current = Head;
	track = NULL;

	if (Head == NULL)
		return;
	else {
		while (current != NULL) {
			track = current->next;
			while (track != NULL) {
				if (current->data->getTitle() > track->data->getTitle()) {
					Item *temp = current->data;
					current->data = track->data;
					track->data = temp;
				}

				track = track->next;
			}

			current = current->next;
		}

	}

}


ItemElement *LinkedItem::getHead() {
	return Head;
}


