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

// Item Menu Implementation

void itemMenu(Item item) {

	// Dear reader: At the moment, only Menu 1 can exit by typing 'exit'. 
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

	// Menu 1, Item 1
	// Cautions: This menu cannot exit by typing 'exit' yet.
	if (input == "1") {
		// Create a new item
		string *inputArray = new string[7];

		// While loop is implemented to validate user's input before moving to next field.
		while (true) {
			cout << "1. Enter item ID: ";
			// Not implement validate yet.
			cin >> inputArray[0];
			break;
		}
		while (true) {
			cout << "2. Enter item's title: ";
			// Not implement validate yet.
			cin >> inputArray[1];
			break;
		}

		while (true) {
			cout << "3. Enter item's type: ";
			// Not implement validate yet.
			cin >> inputArray[2];
			break;
		}

		while (true) {
			cout << "4. Enter item's loan type: ";
			// Not implement validate yet.
			cin >> inputArray[3];
			break;
		}

		while (true) {
			cout << "5. Enter item's number of copies: ";
			// Not implement validate yet.
			cin >> inputArray[4];
			break;
		}

		while (true) {
			cout << "6. Enter item's rental fee: ";
			// Not implement validate yet.
			cin >> inputArray[5];
			break;
		}

		while (true) {
			if (inputArray[2] == "Game") {
				Game g(inputArray[0], inputArray[1], inputArray[2], inputArray[3], stod(inputArray[4]), stod(inputArray[5]));
				g.printDetail();
				break;
			}
			else if (inputArray[2] == "DVD") {
				cout << "7. Enter item's genre: ";
				// Not implement validate yet.
				cin >> inputArray[6];
				DVD d(inputArray[0], inputArray[1], inputArray[2], inputArray[3], stod(inputArray[4]), stod(inputArray[5]), inputArray[6]);
				break;
			}
			else {
				cout << "7. Enter item's genre: ";
				cin >> inputArray[6];
				// Not implement validate yet.
				Record r(inputArray[0], inputArray[1], inputArray[2], inputArray[3], stod(inputArray[4]), stod(inputArray[5]), inputArray[6]);
				break;
			}
		}
		itemMenu(item);
	}
	// Dummy option. Implement later
	else if (input == "2") {
		cout << "Option 2" << endl;
	}
	// Dummy option. Implement later
	else if (input == "3") {
		cout << "Option 3" << endl;
	}
	// Dummy option. Implement later
	else if (input == "4") {
		cout << "Option 4" << endl;
	}
	// Dummy option. Implement later
	else if (input == "5") {
		mainMenu(item);
	}
	// Close program.
	else if (input == "exit") {
		exit(0);
	}
	else {
		cout << "Prompt: Invalid input" << endl;
		itemMenu(item);
	}
}
