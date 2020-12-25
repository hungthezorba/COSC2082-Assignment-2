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

using namespace std;


int main()
{

	//BELOW IS QUICK TEST. DO NOT DELETE OR UNCOMMENT
	LinkedItem itemList;
	Game *i1 = new Game("I202-2012", "Halos", "Game", "2-days", 5, 5.5);
	DVD *i2 = new DVD("I202-2015", "Halos", "Game", "2-days", 5, 5.5,"action");
	DVD *i3 = new DVD("I202-2016", "dadq", "DVD", "2-days", 5, 5.5, "action");


	itemList.addItem(i1);
	itemList.addItem(i2);
	itemList.addItem(i3);

	itemList.printItem();

	mainMenu(itemList);

    return 0;
}
