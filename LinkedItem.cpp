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
void LinkedItem::AddItem(Item newItem) {
    ItemElement* newPtr = new ItemElement;
    newPtr->next = NULL;
    newPtr->data = newItem;

    if(Head == NULL){
        Head = newPtr;
        temp = Head;
        last = Head;
    }else{
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next=newPtr;
        last= newPtr;
    }
}


// Print all item
void LinkedItem :: PrintItem(){
    temp = Head;
    while(temp!=NULL){
		// Print first then move to jnext
		cout << temp->data.getTitle() << endl;
		temp = temp->next;
    }
};

// Search item by ID
ItemElement *LinkedItem :: search(string id){
	
    temp = Head;
    track = Head;
    while(temp!=NULL && temp->data.getId()!=id){
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
void LinkedItem::DeleteItem(string id) {
	// Considering to refactor this function because there is a repeat part in find by id.
    ItemElement *delPtr = NULL;
    temp = Head;
    track = Head;
    string thisId = id;
    while(temp!=NULL && temp->data.getId()!=thisId){
        track = temp;
        temp = temp->next;
    }
    if(temp == NULL){
		// No need to print message in this function. Message will be carried out by menu.
        delete delPtr;
    }
    else {
        delPtr = temp;
        temp=temp->next;
        track->next=temp;
        delete delPtr;
		// No need to print message in this function. Message will be carried out by menu.
	}

}

