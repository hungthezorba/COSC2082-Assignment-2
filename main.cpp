// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "Game.h"
#include "Item.h"
#include "Record.h"
#include "DVD.h"
#include "Menu.h"

using namespace std;


int main()
{	
	Item i("i101 - 2012", "halo", "Game", "2 - days", 2, 2.225);
	mainMenu(i);

    return 0;
}

