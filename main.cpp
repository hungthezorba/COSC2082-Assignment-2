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



void closeWithFileError() {

	cout << "ERROR: Input database files are not correctly." << endl;
	cout << endl;

	// Display group information
	cout << "- - - - - - - - - - Group Information - - - - - - - - - -" << endl;
	cout << "|                 ASSIGNMENT 2 GROUP 18                 |" << endl;
	cout << "|                                                       |" << endl;
	cout << "|       s3804690, s3804690@rmit.edu.vn, Hung, Nguyen    |" << endl;
	cout << "|       s3804687, s3804687@rmit.edu.vn, Dat, Ngo        |" << endl;
	cout << "|       s3536647, s3536647@rmit.edu.vn, Quan, Bui       |" << endl;
	cout << "|       s3777230, s3777230@rmit.edu.vn, Huy, Bui        |" << endl;
	cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
	// Stop the program
	cout << "Closing the program..." << endl;
	exit(0);
}

int main(int argc, char *argv[])
{

	LinkedItem itemList; // Initialize item list
	LinkedCustomer customerList; // Initialize customer list

	// Check input file's names
	if (strcmp(argv[1], "items.txt") || strcmp(argv[2], "customers.txt")) {
		closeWithFileError();
		return -1;
	}

	ItemData(itemList, argv[1]); // Read item file
	CustomerData(customerList, argv[2]); // Read customer file

	mainMenu(itemList, customerList, argv[1], argv[2]); // Call main menu function


    return 0;
}