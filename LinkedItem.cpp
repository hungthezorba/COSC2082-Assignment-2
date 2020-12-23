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

void LinkedItem :: PrintItem(){
    temp = Head;
    while(temp!=NULL){
        track = temp;
        temp = temp->next;
        cout<<temp->data.getTitle();
    }
};

ItemElement *LinkedItem :: search(string id){
    temp = Head;
    track = Head;
    while(temp!=NULL && temp->data.getId()!=id){
        track = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        cout<<"the item not found"<<endl;
        return NULL;
    }
    return temp;
};

void LinkedItem::DeleteItem(string id) {
    ItemElement *delPtr = NULL;
    temp = Head;
    track = Head;
    string thisId = id;
    while(temp!=NULL && temp->data.getId()!=thisId){
        track = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        cout<<"the item not found"<<endl;
        delete delPtr;
    }
    else {
        delPtr = temp;
        temp=temp->next;
        track->next=temp;
        delete delPtr;
        cout<< "Item deleted"<<endl;
    }

}

