#include "stdafx.h"
#include "Menu.h"
#include <iostream>
#include "string"


void mainMenu(Item item) {
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
	cout << "| 10. Search items or customers                                    |" << endl;
	cout << "| Exit.                                                            |" << endl;
	cout << "--------------------------------------------------------------------" << endl;
	cout << "Select an option: ";
	cin >> input;

	if (input == "1") {
		itemMenu(item);
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
		cout << "Option 6" << endl;
	}
	else if (input == "7") {
		cout << "Option 7" << endl;
	}
	else if (input == "8") {
		cout << "Option 8" << endl;
	}
	else if (input == "9") {
		cout << "Option 9" << endl;
	}
	else if (input == "10") {
		cout << "Option 10" << endl;
	}
	else if (input == "exit") {
		exit(0);
	}
	else {
		cout << "Prompt: Invalid input" << endl;
		mainMenu(item);
	}
}

void itemMenu(Item item) {
	cout << "---------------------------* Item Menu *---------------------------" << endl;
	cout << "| 1. Add a new item                                               |" << endl;
	cout << "| 2. Delete an item                                               |" << endl;
	cout << "| 3. Update an item                                               |" << endl;
	cout << "| 4. Add more item to stock                                       |" << endl;
	cout << "| 5. Back                                                         |" << endl;
	cout << "| Exit.                                                           |" << endl;
	cout << "-------------------------------------------------------------------" << endl;
	cout << "Choose an option: ";
	string input;
	cin >> input;

	if (input == "1") {
		cout << item.getRentalType() << endl;

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
		mainMenu(item);
	}
	else if (input == "exit") {
		exit(0);
	}
	else {
		cout << "Prompt: Invalid input" << endl;
		itemMenu(item);
	}
}
