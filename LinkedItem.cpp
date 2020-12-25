//
// Created by Enterprise on 12/23/2020.
//
#include "Item.h"
#include <iostream>
#include "LinkedItem.h"
#include "ItemElement.h"


LinkedItem :: LinkedItem(){
    Head = NULL;
    temp = NULL;
    last = NULL;
    track = NULL;
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
		temp = Head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newPtr;
    }
}


// Print all items
void LinkedItem::printItem(){
    temp = Head;
    while(temp!=NULL){
		// Print first then move to jnext
		temp->data->printDetail();
		temp = temp->next;
    }
};

// Print all out of stock items
void LinkedItem::printOutOfStockItem() {
	temp = Head;
	while (temp != NULL) {
		// Print first then move to jnext
		if (temp->data->getNumberOfCopies() == 0) {
			temp->data->printDetail();
		}
		temp = temp->next;
	}
}

// Search item by ID
ItemElement *LinkedItem::searchItemByID(string id){
	
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

// Delete item by ID
void LinkedItem::deleteItem(string id) {
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

