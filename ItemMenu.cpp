#include "ItemMenu.h"
#include "Item.h"
#include <iostream>
#include "ValidateItemInput.h"
#include "Menu.h"
#include <string>
#include "LinkedItem.h"
using namespace std;

void itemMenu(LinkedItem &itemList) {

	// Dear reader: At the moment, only Menu 1 can exit by typing 'exit'. 
	cout << "----------------------------* Item Menu *---------------------------" << endl;
	cout << "| 1. Add a new item                                                |" << endl;
	cout << "| 2. Delete an item                                                |" << endl;
	cout << "| 3. Update an item                                                |" << endl;
	cout << "| 4. Increase item's stock                                         |" << endl;
	cout << "| 5. Show all item in stock                                        |" << endl;
	cout << "| 6. Back                                                          |" << endl;
	cout << "| Exit.                                                            |" << endl;
	cout << "--------------------------------------------------------------------" << endl;
	cout << "Choose an option: ";
	string input;
	cin >> input;

	// Menu 1, Item 1
	// Cautions: This menu cannot exit by typing 'exit' yet.
	if (input == "1") {
		// Create a new item
		Item *newItem = itemCreateMenu();
		// Insert item into linked list here
		itemList.addItem(newItem);
		// Back to item menu
		itemMenu(itemList);
	}
	// Implemented flow. Later will implement action.
	else if (input == "2") {
		cout << "---------------------* Delete Item *---------------------" << endl;
		// Consider show all item in the stock here

		// Check ID format
		while (true) {
			cout << "PROMPT: Enter item's ID want to delete: ";
			cin >> input;
			if (validateItemInput(input, 1))
				break;
		}
		// Find item through the list here
		ItemElement *foundItem = itemList.searchItem(input);
		if ( foundItem != NULL) {
			foundItem->data->printDetail();
			cout << "PROMPT: Do you really want to delete the item ? Type 'yes' to confirm action: ";
			cin >> input;
			if (input == "yes") {
				itemList.deleteItem(foundItem->data->getId());
				cout << "SUCCESS: Item has been deleted." << endl;
				itemList.printItem();
			}
			else
				cout << "SUCCESS: No deletion has taken place. Return to item menu." << endl;
		}
		else {
			cout << "ERROR: Item not found. Return to item menu." << endl;
		}
		// If-else case: If item found, show item's detail. If item not found, print error message then back to item menu.
		//
		// Delete is a dangerous action. So the program make it harder to delete an item. Just like Github.
		itemMenu(itemList);
	}
	else if (input == "3") {
		cout << "Option 3" << endl;
		cout << "---------------------* Update Item *---------------------" << endl;
		// Consider show all item in the stock here

		// Check ID format
		while (true) {
			cout << "PROMPT: Enter item's ID want to update: ";
			cin >> input;
			if (input == "back") {
				itemMenu(itemList);
				break;
			}
			else
				if (validateItemInput(input, 1))
					break;
		}
		// Find item through the list here

		ItemElement *item = itemList.searchItem(input);
		
		// If-else case: If item found, show item's detail. If item not found, print error message then back to item menu.
		//
		while (true) {
			itemUpdateMenu(item);
			cout << "PROMPT: Continue to update ? (y/n): ";
			cin >> input;
			if (input == "exit") {
				exit(0);
			}
			else if (input == "y") {
				cout << "------------------------------------------------" << endl;
				// Continue to update
			}
			else {
				cout << "------------------------------------------------" << endl;
				// Break out the update loop
				break;
			}
		}
		
		itemMenu(itemList);
	}
	// Dummy option. Implement later
	else if (input == "4") {
		cout << "Option 4" << endl;
	}
	// Dummy option. Implement later
	else if (input == "5") {
		cout << "------------------List of items----------------" << endl;
		itemList.printItem();
		itemMenu(itemList);
	}
	else if (input == "6") {
		//mainMenu(itemList);
	}
	// Close program.
	else if (input == "exit") {
		exit(0);
	}
	else {
		cout << "Prompt: Invalid input" << endl;
		itemMenu(itemList);
	}
}

// Create item
Item* itemCreateMenu() {
	string *inputArray = new string[7];

	// While loop is implemented to validate user's input before moving to next field.
	while (true) {
		cout << "1. Enter item ID: ";
		// Implemented validation. Still need further testing
		cin >> inputArray[0];
		if (inputArray[0] == "exit")
			exit(0);
		if (validateItemInput(inputArray[0], 1))
			break;
	}
	while (true) {
		cout << "2. Enter item's title: ";
		// Implemented validation. Still need further testing
		// Reference: https://www.xspdf.com/resolution/50767455.html
		cin.ignore();
		// Title can contains spaces so need to use getline in this case
		getline(cin, inputArray[1]);
		if (inputArray[1] == "exit")
			exit(0);
		if (validateItemInput(inputArray[1], 2))
			break;
	}

	while (true) {
		cout << "3. Enter item's type: ";
		// Implemented validation. Still need further testing
		cin >> inputArray[2];
		if (inputArray[2] == "exit")
			exit(0);
		if (validateItemInput(inputArray[2], 3))
			break;
	}

	while (true) {
		cout << "4. Enter item's loan type: ";
		// Implemented validation. Still need further testing
		cin >> inputArray[3];
		if (inputArray[3] == "exit")
			exit(0);
		if (validateItemInput(inputArray[3], 4))
			break;
	}

	while (true) {
		cout << "5. Enter item's number of copies: ";
		// Implemented validation. Still need further testing
		cin >> inputArray[4];
		if (inputArray[4] == "exit")
			exit(0);
		if (validateItemInput(inputArray[4], 5))
			break;
	}

	while (true) {
		cout << "6. Enter item's rental fee: ";
		// Implemented validation. Still need further testing
		cin >> inputArray[5];
		if (inputArray[5] == "exit")
			exit(0);
		if (validateItemInput(inputArray[5], 6))
			break;
	}

	while (true) {
		if (inputArray[2] == "Game") {
			Game *newItem = new Game(inputArray[0], inputArray[1], inputArray[2], inputArray[3], stod(inputArray[4]), stod(inputArray[5]));
			newItem->printDetail();
			delete[] inputArray; // free the heap after used
			return newItem;
			break;
		}
		else if (inputArray[2] == "DVD") {
			cout << "7. Enter item's genre: ";
			// Implemented validation. Still need further testing
			cin >> inputArray[6];
			if (inputArray[6] == "exit")
				exit(0);
			if (validateItemInput(inputArray[6], 7)) {
				DVD *newItem = new DVD(inputArray[0], inputArray[1], inputArray[2], inputArray[3], stod(inputArray[4]), stod(inputArray[5]), inputArray[6]);
				newItem->printDetail();
				delete[] inputArray; // free the heap after used
				return newItem;
				break;
			}
		}
		else {
			cout << "7. Enter item's genre: ";
			cin >> inputArray[6];
			// Implemented validation. Still need further testing
			if (inputArray[6] == "exit")
				exit(0);
			if (validateItemInput(inputArray[6], 7)) {
				Record *newItem = new Record(inputArray[0], inputArray[1], inputArray[2], inputArray[3], stod(inputArray[4]), stod(inputArray[5]), inputArray[6]);
				newItem->printDetail();
				delete[] inputArray; // free the heap after used
				return newItem;
				break;
			}

		}
	}
}


void itemUpdateMenu(ItemElement *item) {
	string input;
	cout << "----------------------* Update Item *----------------------" << endl;
	cout << "original: " << &item << endl;
	cout << "Item ID: " << item->data->getId() << endl;
	cout << "1. Item title: " << item->data->getTitle() << endl;
	cout << "2. Item type: " << item->data->getRentalType() << endl;
	cout << "3. Item loan's type: " << item->data->getLoanType() << endl;
	cout << "4. Item number of copies: " << item->data->getNumberOfCopies() << endl;
	cout << "5. Item rental fee: " << item->data->getRentalFee() << endl;
	if (item->data->getRentalType() != "Game") {
		cout << "6. Item genre: " << item->data->getGenre() << endl;
	}
	cout << "Select an option: ";
	cin >> input;

	if (input == "1") {
		while (true) {
			cout << "Enter item's title: ";
			cin.ignore();
			// Title can contains spaces so need to use getline in this case
			getline(cin, input);
			if (input == "exit")
				exit(0);
			if (validateItemInput(input, 2)) {
				item->data->setTitle(input);
				break;
			}
		}
	}
	else if (input == "2") {
		while (true) {
			cout << "Enter item's type: ";
			cin >> input;
			if (input == "exit")
				exit(0);
			if (validateItemInput(input, 3)) {
				item->data->setRentalType(input);
				if (item->data->getRentalType() == "DVD") {
					item->data = new DVD(item->data->getId(), item->data->getTitle(), item->data->getRentalType(), item->data->getLoanType(), item->data->getNumberOfCopies(), item->data->getRentalFee(), "NaN");
					item->data->printDetail();
				}
				else if (item->data->getRentalType() == "Record") {
					item->data = new Record(item->data->getId(), item->data->getTitle(), item->data->getRentalType(), item->data->getLoanType(), item->data->getNumberOfCopies(), item->data->getRentalFee(), "NaN");
					item->data->printDetail();
				}
				else {
					item->data = new Game(item->data->getId(), item->data->getTitle(), item->data->getRentalType(), item->data->getLoanType(), item->data->getNumberOfCopies(), item->data->getRentalFee());
					item->data->printDetail();
				}
				break;
			}
		}
	}
	else if (input == "3") {
		while (true) {
			cout << "Enter item's loan type: ";
			cin >> input;
			if (input == "exit")
				exit(0);
			if (validateItemInput(input, 4)) {
				item->data->setLoanType(input);
				break;
			}
		}
	}
	else if (input == "4") {
		while (true) {
			cout << "Enter item's number of copies: ";
			cin >> input;
			if (input == "exit")
				exit(0);
			if (validateItemInput(input, 5)) {
				item->data->setNumberOfCopies(stoi(input));
				break;
			}
		}
	}
	else if (input == "5") {
		while (true) {
			cout << "Enter item's rental fee: ";
			cin >> input;
			if (input == "exit")
				exit(0);
			if (validateItemInput(input, 6)) {
				item->data->setRentalFee(stod(input));
				break;
			}
		}
	}
	else if (input == "6" && (item->data->getRentalType() == "DVD" || item->data->getRentalType() == "Record")) {
		while (true) {
			cout << "Enter item's genre: ";
			cin >> input;
			if (input == "exit")
				exit(0);
			if (validateItemInput(input, 7)) {
				item->data->setGenre(input);
				item->data->printDetail();
				break;
			}
		}
	}
	else if (input == "exit") {
		exit(0);
	}
	else {
		cout << "ERROR: Invalid input. Please enter again." << endl;
	}
	return;
}