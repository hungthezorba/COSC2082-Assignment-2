//
// Created by Enterprise on 12/23/2020.
//

#include "Item.h"
#include "ItemElement.h"
#ifndef LINKEDITEM_H
#define LINKEDITEM_H

class LinkedItem{
private:
    ItemElement *Head;
    ItemElement *temp;
    ItemElement *last;
    ItemElement *track;
public:
    LinkedItem();
    void addItem(Item *newItem);
    void deleteItem(string id);
    ItemElement*searchItemByID(string id);
	ItemElement*searchItemByTitle(string title);
    void printItem();
	void printOutOfStockItem();


};


#endif //ASSIGNMENT2_LINKEDITEM_H
