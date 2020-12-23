//
// Created by Enterprise on 12/23/2020.
//

#include "ItemElement.h"
#include "Item.h"
#include "iostream"
using namespace std;



void AddElement(ItemElement *&last,ItemElement*&temp,Item newItem){
    cout<<"next Item "<<newItem.getTitle()<<" "<<temp <<endl;
    last = new ItemElement;
    last->data = newItem;
    temp->next = last;
    temp= temp->next;
    cout<<last<< " "<<temp<<endl;
}

void CreateLinkedList(ItemElement *&first,ItemElement *&temp,ItemElement*&last,Item firstItem){
    last->data = firstItem;
    temp = last;
    first = temp;
    cout <<"first: "<<first<<" temp: "<<temp<<" last: "<<last;
//    cout<<"the first node "<<firstItem.getTitle()<<endl;

}
