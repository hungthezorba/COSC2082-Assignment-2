#include "Menu.h"
#include <iostream>
#include <string>
#include "ValidateItemInput.h"
#include "ItemMenu.h"
#include "LinkedItem.h"

using namespace std;

void mainMenu(LinkedItem &itemList) {
	string input;
	cout << "-----------------* Welcome to Genie's video store *-----------------" << endl;
	cout << "| 1. Add a new item, update or delete an existing item             |" << endl;
	cout << "| 2. Add new customer or update an existing customer               |" << endl;
	cout << "| 3. Promote an existing customer                                  |" << endl;
	cout << "| 4. Rent an item                                                  |" << endl;
	cout << "| 5. Return an item                                                |" << endl;
	cout << "| 6. Display all items                                             |" << endl;
	cout << "| 7. Display out-of-stock items                                    |" << endl;
	cout << "| 8. Display all customers                                         |" << endl;
	cout << "| 9. Display group of customers                                    |" << endl;
	cout << "| Exit.                                                            |" << endl;
	cout << "--------------------------------------------------------------------" << endl;
	cout << "Select an option: ";
	cin >> input;

	if (input == "1") {
		itemMenu(itemList);
	}
	else if (input == "2") {
		cout << "Option 2" << endl;
	}
	else if (input == "3") {
		cout << "Option 3" << endl;
	}
	else if (input == "4") {
		cout << "Option 4" << endl;
	}
	else if (input == "5") {
		cout << "Option 5" << endl;
	}
	else if (input == "6") {
		cout << "---------------* Display all items *---------------" << endl;
		cout << "| 1. sorted by ID                                 |" << endl;
		cout << "| 2. sorted by Title                              |" << endl;
		cout << "---------------------------------------------------" << endl;
		cout << "PROMPT: Choose an option: ";
		cin >> input;
		if (input == "1") {
			LinkedItem tempItemList(itemList);
			tempItemList.sortedByID();
			tempItemList.printItem();
		}
		else if (input == "2") {
			LinkedItem tempItemList(itemList);
			tempItemList.sortedByTitle();
			tempItemList.printItem();
		}
		else if (input == "exit") {
			exit(0);
		}
		else {
			cout << "ERROR: Invalid input." << endl;
		}
		mainMenu(itemList);
	}
	else if (input == "7") {
		cout << "Option 7" << endl;
		// Display out of stock
		itemList.printOutOfStockItem();
		mainMenu(itemList);
	}
	else if (input == "8") {
		cout << "Option 8" << endl;
	}
	else if (input == "9") {
		cout << "Option 9" << endl;
	}
	else if (input == "exit") {
		exit(0);
	}
	else {
		cout << "Prompt: Invalid input" << endl;
		mainMenu(itemList);
	}
}

void closeProgram() {
	// Display group information
	cout << "- - - - - - - - Group Information - - - - - - - -" << endl;
	cout << "ASSIGNMENT 2 GROUP 18" << endl;
	cout << "s3804690, s3804690@rmit.edu.vn, Hung, Nguyen" << endl;
	cout << "s3804687, s3804687@rmit.edu.vn, Dat, Ngo" << endl;
	cout << "s3536647, s3536647@rmit.edu.vn, Quan, Bui" << endl;
	cout << "s3777230, s3777230@rmit.edu.vn, Huy, Bui" << endl;

	// Stop the program
	cout << "Closing the program..." << endl;
	exit(0);
}
