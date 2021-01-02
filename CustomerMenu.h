#pragma once
#include "Menu.h"
#include "ItemMenu.h"
#include "LinkedItem.h"
#include "LinkedCustomer.h"
#include "Customer.h"

void customerMenu(LinkedItem &itemList, LinkedCustomer &customerList);

Customer* customerCreateMenu();
Customer* customerUpdateMenu();