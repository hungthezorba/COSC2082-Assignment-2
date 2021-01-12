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

int main(int argc, char *argv[])
{

	LinkedItem itemList; // Initialize item list
	LinkedCustomer customerList; // Initialize customer list

	ItemData(itemList, argv[1]); // Read item file
	CustomerData(customerList, argv[2]); // Read customer file

	mainMenu(itemList, customerList); // Call main menu function


    return 0;
}
