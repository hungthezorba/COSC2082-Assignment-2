#pragma once
#include "Item.h"
#include "Game.h"
#include "Record.h"
#include "DVD.h"
#include "LinkedItem.h"
#include "LinkedCustomer.h"

void mainMenu(LinkedItem &itemList, LinkedCustomer &customerList, string itemFileName, string customerFileName);
void closeProgram(LinkedItem &itemList, LinkedCustomer &customerList, string itemFileName, string customerFileName);