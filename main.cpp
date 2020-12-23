// main.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include "Game.h"
#include "Item.h"
#include "Record.h"
#include "DVD.h"
#include "Menu.h"
#include "ItemElement.h"

using namespace std;


int main()
{
    Item i1("I101-2001","something","record","2-day",1,1.45);
    Item i2("I102-2002","somethingelse","recordlabel","2-day",1,2.45);
    Item i3("I103-2003","anything","record","2-day",2,1.55);
    Item i4("I104-2005","something","record","2-day",1,1.45);
    Item i5("I105-2007","manything","record","3-day",1,3.45);

    ItemElement *last;
    ItemElement *temp;
    ItemElement *head;
    last = new ItemElement;
    temp = new ItemElement;
    head = new ItemElement;

    CreateLinkedList(head,temp,last,i1);

//    cout <<head->data.getTitle();
    AddElement(last,temp,i2);
    AddElement(last,temp,i3);
    AddElement(last,temp,i4);
    AddElement(last,temp,i5);

//    cout<<last->data.getId();
    ItemElement*getInfo;
    getInfo = head;
//    cout <<getInfo->data.getTitle()<<endl;
//    cout <<&i2<<endl;
//    cout <<&head->next->data<<endl;
//    cout<<temp<<endl;
//    cout<<last<<endl;
    for (int i =0;i<5;i++){
        cout<<i<<endl;
        cout <<getInfo->data.getTitle()<<endl;
        getInfo = getInfo->next;

    }

    return 0;
}

