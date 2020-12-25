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
	Game *i1 = new Game("I001-2001", "Medal of Honour", "Game", "1-week", 3, 3.99);
	Record *i2 = new Record("I002-1998", "White Castle", "Record", "1-week", 3, 0.99, "Comedy");
	Record *i3 = new Record("I003-1992", "Alpha Dog", "Record", "1-week", 3, 1.99, "Action");
	DVD *i4 = new DVD("I004-1999", "Rat Race", "DVD", "1-week", 3, 1.99, "Horror");
	Game *i5 = new Game("I005-2015", "Halo", "Game", "2-day", 2, 4.99);
	DVD *i6 = new DVD("I006-2013", "Halloween", "DVD", "2-day", 1, 0.99, "Horror");



	itemList.addItem(i1);
	itemList.addItem(i2);
	itemList.addItem(i5);
	itemList.addItem(i4);
	itemList.addItem(i3);
	itemList.addItem(i6);

	mainMenu(itemList);


    return 0;
}

