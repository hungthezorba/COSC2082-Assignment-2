//
// Created by Enterprise on 12/23/2020.
//
#include "Item.h"

#ifndef ITEMELEMENT_H
#define ITEMELEMENT_H

struct ItemElement{
public:
    Item data;
    ItemElement * next;
};
void AddElement(ItemElement *&last,ItemElement*&temp,Item newItem);
void CreateLinkedList(ItemElement *&first,ItemElement *&temp,ItemElement*&last,Item firstItem);
#endif //ASSIGNMENT2_ITEMELEMENT_H
