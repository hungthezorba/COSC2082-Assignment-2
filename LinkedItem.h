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
	LinkedItem(const LinkedItem &v);
    void addItem(Item *newItem);
    void deleteItem(string id);
    ItemElement*searchItemByID(string id);
	ItemElement*searchItemByTitle(string title);
    void printItem();
	void printOutOfStockItem();
	void sortedByID();
	void sortedByTitle();
	ItemElement *getHead();
	void IncreaseNumberOfCopies(string id);
	void DecreaseNumberOfCopies(string id);
	void Output(LinkedItem* list);
};


#endif //ASSIGNMENT2_LINKEDITEM_H
