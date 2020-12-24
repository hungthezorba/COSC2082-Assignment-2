#pragma once
#include "Item.h"
#include "Game.h"
#include "Record.h"
#include "DVD.h"
#include "LinkedItem.h"
#include "ItemElement.h"


void itemMenu(LinkedItem itemList);
Item* itemCreateMenu();
Item* itemDeleteMenu(Item *item);
void itemUpdateMenu(ItemElement *item);