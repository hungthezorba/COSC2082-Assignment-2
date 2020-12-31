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

using namespace std;


int main()
{

//	//BELOW IS QUICK TEST. DO NOT DELETE OR UNCOMMENT
	LinkedItem itemList;

	ItemData(itemList);
	mainMenu(itemList);
//    Customer customer1("123", "Quan", "Vietnam", "0123456789");
//    Customer customer2("124", "Tuan", "Vietnam", "0123456789");
//    Customer customer3("125", "Huan", "Vietnam", "0123456789");
//    Customer customer4("126", "Nhuan", "Vietnam", "0123456789");
//    LinkedCustomer thisList;
//    thisList.addCustomer(&customer1);
//    thisList.addCustomer(&customer2);
//    thisList.addCustomer(&customer3);
//    thisList.addCustomer(&customer4);
//
//    CustomerNode *ThisNode;
//    ThisNode = thisList.searchCustomer("126");
//    cout<<ThisNode->data->getName();

    return 0;
}
