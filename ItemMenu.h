#pragma once
#include "Item.h"
#include "Game.h"
#include "Record.h"
#include "DVD.h"

void itemMenu(Item **itemList);
Item* itemCreateMenu();
Item* itemDeleteMenu(Item *item);
Item* itemUpdateMenu(Item *item);