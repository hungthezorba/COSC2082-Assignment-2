#pragma once
#include "Menu.h"
#include "ItemMenu.h"
#include "LinkedItem.h"
#include "LinkedCustomer.h"
#include "CustomerNode.h"
#include "Customer.h"

void customerMenu(LinkedItem &itemList, LinkedCustomer &customerList, string itemFileName, string customerFileName);

Customer* customerCreateMenu(LinkedCustomer &customerList);
void customerUpdateMenu(CustomerNode *customer);