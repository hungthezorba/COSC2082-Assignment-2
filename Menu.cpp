#include "Menu.h"
#include <iostream>
#include <string>
#include "ValidateItemInput.h"

using namespace std;

void mainMenu(Item *item) {
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
// Considering move Item Menu to separated file since there will be lots of menu

void itemMenu(Item *item) {

	// Dear reader: At the moment, only Menu 1 can exit by typing 'exit'. 
	cout << "----------------------------* Item Menu *---------------------------" << endl;
	cout << "| 1. Add a new item                                                |" << endl;
	cout << "| 2. Delete an item                                                |" << endl;
	cout << "| 3. Update an item                                                |" << endl;
	cout << "| 4. Add more item to stock                                        |" << endl;
	cout << "| 5. Back                                                          |" << endl;
	cout << "| Exit.                                                            |" << endl;
	cout << "--------------------------------------------------------------------" << endl;
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
			// Implemented validation. Still need further testing
			cin >> inputArray[0];
			if (inputArray[0] == "exit")
				exit(0);
			if (validateItemInput(inputArray[0],1))
				break;
		}
		while (true) {
			cout << "2. Enter item's title: ";
			// Implemented validation. Still need further testing
			// Reference: https://www.xspdf.com/resolution/50767455.html
			cin.ignore();
			// Title can contains spaces so need to use getline in this case
			getline(cin,inputArray[1]);
			if (inputArray[1] == "exit")
				exit(0);
			if (validateItemInput(inputArray[1],2))
				break;
		}

		while (true) {
			cout << "3. Enter item's type: ";
			// Implemented validation. Still need further testing
			cin >> inputArray[2];
			if (inputArray[2] == "exit")
				exit(0);
			if (validateItemInput(inputArray[2],3))
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
				Game g(inputArray[0], inputArray[1], inputArray[2], inputArray[3], stod(inputArray[4]), stod(inputArray[5]));
				g.printDetail();
				delete[] inputArray; // free the heap after used
				break;
			}
			else if (inputArray[2] == "DVD") {
				cout << "7. Enter item's genre: ";
				// Implemented validation. Still need further testing
				cin >> inputArray[6];
				if (inputArray[6] == "exit")
					exit(0);
				if (validateItemInput(inputArray[6], 7)) {
					DVD d(inputArray[0], inputArray[1], inputArray[2], inputArray[3], stod(inputArray[4]), stod(inputArray[5]), inputArray[6]);
					d.printDetail();
					delete[] inputArray; // free the heap after used
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
					Record r(inputArray[0], inputArray[1], inputArray[2], inputArray[3], stod(inputArray[4]), stod(inputArray[5]), inputArray[6]);
					r.printDetail();
					delete[] inputArray; // free the heap after used
					break;
				}
					
			}
		}
		// Insert item into linked list here

		// Back to item menu
		itemMenu(item);
	}
	// Implemented flow. Later will implement action.
	else if (input == "2") {
		cout << "---------------------* Delete Item *---------------------" << endl;
		// Consider show all item in the stock here
		
		// Check ID format
		while (true) {
			cout << "PROMPT: Enter item's ID want to delete: ";
			cin >> input;
			if (input == "back") {
				itemMenu(item);
				break;
			}
			else
				if (validateItemInput(input,1))
					break;
		}
		// Find item through the list here
		//
		// If-else case: If item found, show item's detail. If item not found, print error message then back to item menu.
		//
		// Delete is a dangerous action. So the program make it harder to delete an item. Just like Github.
		cout << "PROMPT: Do you really want to delete the item ? Type 'yes' to confirm action: "; 
		cin >> input;
		if (input == "yes")
			cout << "SUCCESS: Item has been deleted." << endl;
		else
			cout << "SUCCESS: No deletion has taken place. Return to item menu." << endl;
		
		itemMenu(item);
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
				itemMenu(item);
				break;
			}
			else
				if (validateItemInput(input, 1))
					break;
		}
		// Find item through the list here
		//
		// If-else case: If item found, show item's detail. If item not found, print error message then back to item menu.
		//
		while (true) {
			cout << "----------------------* Update Item *----------------------" << endl;
			cout << "original: " << &item << endl;
			cout << "Item ID: " << item -> getId() << endl;
			cout << "1. Item title: " << item->getTitle() << endl;
			cout << "2. Item type: " << item->getRentalType() << endl;
			cout << "3. Item loan's type: " << item->getLoanType() << endl;
			cout << "4. Item number of copies: " << item->getNumberOfCopies() << endl;
			cout << "5. Item rental fee: " << item->getRentalFee() << endl;
			if (item->getRentalType() != "Game") {
				cout << "6. Item genre: " << item->getGenre() << endl;
			}
			cout << "Select an option: ";
			cin >> input;

			if (input == "back") {
				itemMenu(item);
				break;
			}

			if (input == "1") {
				while (true) {
					cout << "Enter item's title: ";
					cin.ignore();
					// Title can contains spaces so need to use getline in this case
					getline(cin, input);
					if (input == "exit")
						exit(0);
					if (validateItemInput(input, 2)) {
						item->setTitle(input);
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
						item->setRentalType(input);
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
						item->setLoanType(input);
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
						item->setNumberOfCopies(stoi(input));
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
						item->setRentalFee(stod(input));
						break;
					}
				}
			}
			else if (input == "6" && (item->getRentalType() == "DVD" || item->getRentalType() == "Record")) {
				while (true) {
					cout << "Enter item's genre: ";
					cin >> input;
					if (input == "exit")
						exit(0);
					if (validateItemInput(input, 7)) {
						item->setGenre(input);
						item->printDetail();
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
		item->printDetail();
		itemMenu(item);
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
