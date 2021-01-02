// main.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include "Game.h"
#include "Item.h"
#include "Record.h"
#include "DVD.h"
#include "Menu.h"
#include "LinkedItem.h"
#include "ItemElement.h"
#include "ItemData.h"
#include "CustomerData.h"
#include "LinkedCustomer.h"

using namespace std;


int main()
{

//	//BELOW IS QUICK TEST. DO NOT DELETE OR UNCOMMENT
	LinkedItem itemList;
	LinkedCustomer customerList;

	ItemData(itemList);
	CustomerData(customerList);

	mainMenu(itemList, customerList);

    return 0;
}
