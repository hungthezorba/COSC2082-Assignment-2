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
    ItemElement *last;
    ItemElement *track;
	ItemElement *current;
public:
    LinkedItem();
	// Copy constructor
    void addItem(Item *newItem);
    void deleteItem(string id);
    ItemElement*searchItemByID(string id);
	LinkedItem searchItemByTitle(string title);
    void printItem();
	void printOutOfStockItem();
	void sortedByID();
	void sortedByTitle();
	ItemElement *getHead() const;


};


#endif //ASSIGNMENT2_LINKEDITEM_H
