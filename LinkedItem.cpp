//
// Created by Enterprise on 12/23/2020.
//
#include "Item.h"
#include <iostream>
#include "LinkedItem.h"
#include "ItemElement.h"


LinkedItem :: LinkedItem(){
    Head = NULL;
    last = NULL;
    track = NULL;
	current = NULL;
}

//Copy Constructor
// References: https://stackoverflow.com/questions/7811893/creating-a-copy-constructor-for-a-linked-list
LinkedItem::LinkedItem(const LinkedItem &itemList)
{
    ItemElement * p1 = 0;//current
    ItemElement * p2 = 0;//next

    if (itemList.Head == 0)
        Head = 0;

    else
    {
        Head = new ItemElement;
        Head->next = itemList.Head->next;
        Head->data = itemList.Head->data;

        p1 = Head;
        p2 = itemList.Head->next;
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

LinkedItem LinkedItem::searchItemByTitle(string title) {
	current = Head;

	// Initial customer list
	LinkedItem tempListItem;

	while (current != NULL) {
		// If match name
		if (current->data->getTitle() == title) {
			tempListItem.addItem(current->data); // Add to list
		}
		current = current->next;
	}
	return tempListItem;

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
            delete current->data; // Free memory
            delete current; // Free memory
			return;
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


ItemElement *LinkedItem::getHead() const {
	return Head;
}


