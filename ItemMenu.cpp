#include "ItemMenu.h"
#include "Item.h"
#include <iostream>
#include "ValidateItemInput.h"
#include "Menu.h"
#include <string>
#include "LinkedItem.h"
using namespace std;


void itemMenu(LinkedItem &itemList, LinkedCustomer &customerList) {

	while (true) {

		// Dear reader: At the moment, only Menu 1 can Exit by typing 'Exit'. 
		cout << "-----------------------* Item Menu *----------------------" << endl;
		cout << "| 1. Add a new item                                      |" << endl;
		cout << "| 2. Delete an item                                      |" << endl;
		cout << "| 3. Update an item                                      |" << endl;
		cout << "| 4. Increase item's stock                               |" << endl;
		cout << "| 5. Show all item in stock                              |" << endl;
		cout << "| 6. Search an item                                      |" << endl;
		cout << "| 7. Back                                                |" << endl;
		cout << "| Exit.                                                  |" << endl;
		cout << "----------------------------------------------------------" << endl;
		cout << "Choose an option: ";
		string input;
		cin >> input;

		// Menu 1, Item 1
		if (input == "1") {
			// Create a new item
			cout << "--------------------* Add a new item *--------------------" << endl;
			Item *newItem = itemCreateMenu(itemList);
			cout << "----------------------------------------------------------" << endl;
			// Insert item into linked list here
			cout << "--------------------* Add a new item *--------------------" << endl;
			cout << "| Item " << newItem->getId() << endl;
			cout << "| 1. Title: " << newItem->getTitle() << endl;
			cout << "| 2. Type: " << newItem->getRentalType() << endl;
			cout << "| 3. Loan's type: " << newItem->getLoanType() << endl;
			cout << "| 4. Number of copies: " << newItem->getNumberOfCopies() << endl;
			cout << "| 5. Rental fee: " << newItem->getRentalFee() << endl;
			if (newItem->getGenre() != "") {
				cout << "| 6. Genre: " << newItem->getGenre() << endl;
			}
			cout << "----------------------------------------------------------" << endl;

			cout << "PROPMP: Item will be added to database. Type 'yes' to confirm: ";
			cin >> input;
			if (input == "yes") {
				itemList.addItem(newItem);
				cout << "SUCCESS: Item added." << endl;
			}
			else {
				cout << "FAIL: No item added." << endl;
			}
			cout << "----------------------------------------------------------" << endl;
			cout << endl; // space
		}
		else if (input == "2") {

			while (true) {
				cout << "---------------------* Delete Item *---------------------" << endl;
				cout << "|1. By ID                                                |" << endl;
				cout << "|2. By title                                             |" << endl;
				cout << "|3. Back                                                 |" << endl;
				cout << "----------------------------------------------------------" << endl;
				cout << "PROMPT: Enter an option: ";
				cin >> input;

				if (input == "1") {
					while (true) {
						cout << "PROMPT: Enter item's ID want to delete: ";
						cin >> input;
						// Check ID format
						if (validateItemID(input,"input"))
							break;
					}
					// Find item through the list here
					ItemElement *foundItem = itemList.searchItemByID(input);

					CustomerNode *rentingCustomer = customerList.getHead();


					// If-else case: If item found, show item's detail. If item not found, print error message then back to item menu.
					if (foundItem != NULL) {
						foundItem->data->printDetail();

						int count = 0; // Count variable to track how many items are being rent

						while (rentingCustomer != NULL) {

							LinkedRentalList *tempRentalList = rentingCustomer->data->getRentalList();
							RentalListNode *tempRentItem = tempRentalList->getHead();
							while (tempRentItem != NULL) {

								if (tempRentItem->getItem() == foundItem->data->getId()) {
									// To make all the customer's name who are renting in the same line. Improving the readability.
									if (count == 0) {
										cout << "FAIL: Item is currently rent by: " << rentingCustomer->data->getName();
									}
									else {
										cout << ", " << rentingCustomer->data->getName();
									}
									count++;
									break;
								}
								tempRentItem = tempRentItem->getNext();
							}

							rentingCustomer = rentingCustomer->next;
						}
						cout << endl; // breakline after print currently rent list
						// If the item not found in customer rental list -> proceed to delete
						if (count == 0) {
							cout << "PROMPT: Do you really want to delete the item ? Type 'yes' to confirm action: ";
							cin >> input;
							if (input == "yes") {
								itemList.deleteItem(foundItem->data->getId());
								cout << "SUCCESS: Item has been deleted." << endl;
							}
							else
								cout << "FAIL: No deletion has taken place. Return to item menu." << endl;
						}
						// If the item still being rent by customers -> print out error message.
						else {
							cout << "PROMPT: The item is still being rent by customers. Please return the item before proceed to delete." << endl;
						}

						// Delete is a dangerous action. So the program make it harder to delete an item. Just like Github.

					}
					else {
						cout << "ERROR: Item not found." << endl;
					}
				}
				else if (input == "2") {
					while (true) {
						cout << "PROMPT: Enter item's title want to delete: ";
						cin >> input;
						// Check title format
						if (validateTitle(input,"input"))
							break;
					}
					// Find item through the list here
					LinkedItem foundList = itemList.searchItemByTitle(input);
					// If-else case: If item found, show item's detail. If item not found, print error message then back to item menu.
					if (foundList.getHead() != NULL) {
					    if (foundList.getHead()->next != NULL) {
					        foundList.printItem();
					        while (true) {
                                cout << "PROMPT: Found more than 1 item with matching name.\nPROMPT: Enter item ID to proceed: ";
                                cin >> input; // Get the customer ID
                                if (validateTitle(input,"input")) {
                                    break;
                                }
					        }
					    }

					    else {
					        input = foundList.getHead()->data->getId();
					    }

					    ItemElement *foundItem = foundList.searchItemByID(input);
					    CustomerNode *rentingCustomer = customerList.getHead();

                        if (foundItem != NULL) {
                            foundItem->data->printDetail();

                            int count = 0; // Count variable to track how many items are being rent

                            while (rentingCustomer != NULL) {

                                LinkedRentalList *tempRentalList = rentingCustomer->data->getRentalList();
                                RentalListNode *tempRentItem = tempRentalList->getHead();
                                while (tempRentItem != NULL) {

                                    if (tempRentItem->getItem() == foundItem->data->getId()) {
                                        cout << "FAIL: Item is currently rent by: " << rentingCustomer->data->getName() << endl;
                                        count++;
                                    }
                                    tempRentItem = tempRentItem->getNext();
                                }

                                rentingCustomer = rentingCustomer->next;
                            }
                            // If the item not found in customer rental list -> proceed to delete
                            if (count == 0) {
                                cout << "PROMPT: Do you really want to delete the item ? Type 'yes' to confirm action: ";
                                cin >> input;
                                if (input == "yes") {
                                    itemList.deleteItem(foundItem->data->getId());
                                    cout << "SUCCESS: Item has been deleted." << endl;
                                }
                                else
                                    cout << "FAIL: No deletion has taken place. Return to item menu." << endl;
                            }
                                // If the item still being rent by customers -> print out error message.
                            else {
                                cout << "PROMPT: The item is still being rent by customers. Please return the item before proceed to delete." << endl;
                            }

                            // Delete is a dangerous action. So the program make it harder to delete an item. Just like Github.

                        }
                        else {
                            cout << "ERROR: Item not found." << endl;
                        }
					}
					else {
						cout << "ERROR: Item not found." << endl;
					}
				}
				else if (input == "3") {
					break;
				}
				else {
					cout << "ERROR: Invalid Input. Please enter again." << endl;
				}
			}
		}
		else if (input == "3") {

			while (true) {
				cout << "---------------------* Update Item *---------------------" << endl;
				cout << "|1. By ID                                                |" << endl;
				cout << "|2. By title                                             |" << endl;
				cout << "|3. Back                                                 |" << endl;
				cout << "----------------------------------------------------------" << endl;
				cout << "PROMPT: Enter an option: ";
				cin >> input;

				if (input == "1") {
					while (true) {
						cout << "PROMPT: Enter item's ID want to update: ";
						cin >> input;
						if (validateItemID(input,"input"))
							break;
					}
					// Find item through the list here
					ItemElement *item = itemList.searchItemByID(input);
					// If-else case: If item found, show item's detail. If item not found, print error message then back to item menu.
					//
					if (item != NULL) {
						while (true) {
							// Call update function
							itemUpdateMenu(item);
							item->data->printDetail();
							cout << "PROMPT: Continue to update ? (y/n): ";
							cin >> input;
						}
					}
					else {
						// Will implement input id again
						cout << "ERROR: Item not found." << endl;
					}
				}
				else if (input == "2") {
                    cin.ignore();
                    while (true) {
                        cout << "PROMPT: Enter item's title want to update: ";
                        getline(cin, input);
                        if (validateTitle(input,"input"))
                            break;
                    }
                    // Find item through the list here
					LinkedItem foundList = itemList.searchItemByTitle(input);
                    // If-else case: If customer found, show customer's detail. If customer not found, print error message then back to customer menu.
                    if (foundList.getHead() != NULL) {
                        // Case 1: Found more than 1 customer with matching name
                        if (foundList.getHead()->next != NULL) {
                            foundList.printItem();
                            while (true) {
                                cout << "PROMPT: Found more than 1 item with matching title.\nEnter item ID to proceed: ";
                                cin >> input; // Get the customer ID
                                if (validateItemID(input,"input")) {
                                    break;
                                }
                            }

                        }
                        else {
                            // Case 2: Found only 1 customer with matching name. The input will be customer ID in the Head of the list.
                            input = foundList.getHead()->data->getId(); // Get the customer ID
                        }

                        ItemElement *item = foundList.searchItemByID(input);

                        if (item != NULL) {
                            // Call update function
                            itemUpdateMenu(item);

                        }
                        else {
                            cout << "ERROR: Item not found." << endl;
                        }

                    }
                    else {
                        cout << "ERROR: Item not found." << endl;
                    }
				}
				else if (input == "3") {
					break;
				}
				else {
					cout << "ERROR: Invalid Input. Please enter again." << endl;
				}
			}
		}
		// Dummy option. Implement later
		else if (input == "4") {
			cout << "Option 4" << endl;
			cout << "---------------------* Add more stock *---------------------" << endl;
			// Consider show all item in the stock here

			// Check ID format
			while (true) {
				cout << "PROMPT: Enter item's ID want to update: ";
				cin >> input;
				if (validateItemID(input,"input"))
					break;
			}
			// Find item through the list here

			ItemElement *item = itemList.searchItemByID(input);
			if (item != NULL) {
				while (true) {
					cout << "PROMPT: Enter number of stock arrived:  ";
					cin >> input;
					if (validateNumberOfCopies(input,"input")) {
						item->data->increaseStock(stoi(input));
						break;
					}

				}
			}
		}
		else if (input == "5") {
			cout << "------------------* List of items *----------------" << endl;
			itemList.printItem();
		}
		else if (input == "6") {

			while (true) {
				cout << "--------------------* Search an item *--------------------" << endl;
				cout << "|1. By ID                                                |" << endl;
				cout << "|2. By title                                             |" << endl;
				cout << "|3. Back                                                 |" << endl;
				cout << "----------------------------------------------------------" << endl;
				cout << "PROMPT: Enter an option: ";
				cin >> input;
				if (input == "1") {
					while (true) {
						cout << "PROMPT: Enter item's ID want to search: ";
						cin >> input;
						if (validateItemID(input,"input"))
							break;
					}
					// Find item through the list here
					ItemElement *item = itemList.searchItemByID(input);
					if (item != NULL) {
						item->data->printDetail();
					}
					else {
						cout << "PROMPT: Cannot found the item with specified ID." << endl;
					}
				}
				else if (input == "2") {
					while (true) {
						cout << "PROMPT: Enter item's title want to search: ";
						cin.ignore();
						getline(cin, input);
						if (validateTitle(input,"input"))
							break;
					}
					// Find item through the list here

					LinkedItem foundList = itemList.searchItemByTitle(input);
					if (foundList.getHead() != NULL)
						foundList.printItem();
					else
						cout << "PROMPT: Cannot found the item with specified title." << endl;
				}
				else if (input == "3") {
					break;
				}
				else {
					cout << "ERROR: Invalid input." << endl;
					itemMenu(itemList, customerList);
				}
				cout << "PROMPT: Continue to search ? (y/n): ";
				cin >> input;
				if (input == "y") {
					cout << endl; // Add space
					// Continue to update
				}
				else {
					cout << "----------------------------------------------------------" << endl;
					cout << endl; // Add space
					// Break out the update loop
					break;
				}
			}
		}
		else if (input == "7") {
			break;
		}
		// Close program.
		else if (input == "Exit") {
			closeProgram(itemList, customerList);
		}
		else {
			cout << "ERROR: Invalid input" << endl;
		}
	}
}

// Create item
Item* itemCreateMenu(LinkedItem &itemList) {
	string *inputArray = new string[7];

	// While loop is implemented to validate user's input before moving to next field.
	while (true) {
		cout << "1. Enter item ID(Ixxx-yyyy): ";
		// Implemented validation. Still need further testing
		cin >> inputArray[0];
		if (validateItemID(inputArray[0], "input")) {
			// Check if ID is existed in database
			ItemElement *duplicateID = itemList.searchItemByID(inputArray[0]);
			if (duplicateID != NULL) {
				cout << "ERROR: Item ID is already existed. Please enter again." << endl;
			}
			else {
				break;
			}
		}
	}
	while (true) {
		cout << "2. Enter item's title: ";
		// Implemented validation. Still need further testing
		// Reference: https://www.xspdf.com/resolution/50767455.html
		cin.ignore();
		// Title can contains spaces so need to use getline in this case
		getline(cin, inputArray[1]);
		if (validateTitle(inputArray[1], "input"))
			break;
	}

	while (true) {
		cout << "3. Enter item's type(Game, DVD or Record): ";
		// Implemented validation. Still need further testing
		cin >> inputArray[2];
		if (validateRentalType(inputArray[2],"input"))
			break;
	}

	while (true) {
		cout << "4. Enter item's loan type(2-day or 1-week): ";
		// Implemented validation. Still need further testing
		cin >> inputArray[3];
		if (validateLoanType(inputArray[3],"input"))
			break;
	}

	while (true) {
		cout << "5. Enter item's number of copies: ";
		// Implemented validation. Still need further testing
		cin >> inputArray[4];
		if (validateNumberOfCopies(inputArray[4],"input"))
			break;
	}

	while (true) {
		cout << "6. Enter item's rental fee: ";
		// Implemented validation. Still need further testing
		cin >> inputArray[5];
		if (validateRentalFee(inputArray[5],"input"))
			break;
	}

	while (true) {
		if (inputArray[2] == "Game") {
			Game *newItem = new Game(inputArray[0], inputArray[1], inputArray[2], inputArray[3], stod(inputArray[4]), stod(inputArray[5]));
			delete[] inputArray; // free the heap after used
			return newItem;
			break;
		}
		else if (inputArray[2] == "DVD") {
			cout << "7. Enter item's genre(Action, Horror, Comedy or Drama): ";
			// Implemented validation. Still need further testing
			cin >> inputArray[6];
			if (validateGenre(inputArray[6],"input")) {
				DVD *newItem = new DVD(inputArray[0], inputArray[1], inputArray[2], inputArray[3], stod(inputArray[4]), stod(inputArray[5]), inputArray[6]);
				delete[] inputArray; // free the heap after used
				return newItem;
				break;
			}
		}
		else {
			cout << "7. Enter item's genre(Action, Horror, Comedy or Drama): ";
			cin >> inputArray[6];
			// Implemented validation. Still need further testing
			if (validateGenre(inputArray[6],"input")) {
				Record *newItem = new Record(inputArray[0], inputArray[1], inputArray[2], inputArray[3], stod(inputArray[4]), stod(inputArray[5]), inputArray[6]);
				delete[] inputArray; // free the heap after used
				return newItem;
				break;
			}

		}
	}
}

// Update item
void itemUpdateMenu(ItemElement *item) {
	string input;

	while (true) {
        cout << "----------------------* Update Item *----------------------" << endl;
        cout << "Item ID: " << item->data->getId() << endl;
        cout << "Type: " << item->data->getRentalType() << endl;
        cout << "1. Item title: " << item->data->getTitle() << endl;
        cout << "2. Item loan's type: " << item->data->getLoanType() << endl;
        cout << "3. Item number of copies: " << item->data->getNumberOfCopies() << endl;
        cout << "4. Item rental fee: " << item->data->getRentalFee() << endl;
        if (item->data->getRentalType() != "Game") {
            cout << "5. Item genre: " << item->data->getGenre() << endl;
        }
        cout << "Select an option: ";
        cin >> input;

        if (input == "1") {
            while (true) {
                cout << "Enter item's title: ";
                cin.ignore();
                // Title can contains spaces so need to use getline in this case
                getline(cin, input);
                if (validateTitle(input,"input")) {
                    item->data->setTitle(input);
                    break;
                }
            }
        }

        else if (input == "2") {
            while (true) {
                cout << "Enter item's loan type(2-day or 1-week): ";
                cin >> input;
                if (validateLoanType(input,"input")) {
                    item->data->setLoanType(input);
                    break;
                }
            }
        }
        else if (input == "3") {
            while (true) {
                cout << "Enter item's number of copies: ";
                cin >> input;
                if (validateNumberOfCopies(input,"input")) {
                    item->data->setNumberOfCopies(stoi(input));
                    break;
                }
            }
        }
        else if (input == "4") {
            while (true) {
                cout << "Enter item's rental fee: ";
                cin >> input;
                if (validateRentalFee(input,"input")) {
                    item->data->setRentalFee(stod(input));
                    break;
                }
            }
        }
        else if (input == "5" && (item->data->getRentalType() == "DVD" || item->data->getRentalType() == "Record")) {
            while (true) {
                cout << "Enter item's genre(Action, Horror, Comedy or Drama): ";
                cin >> input;
                if (validateGenre(input,"input")) {
                    item->data->setGenre(input);
                    break;
                }
            }
        }
        else {
            cout << "ERROR: Invalid input. Please enter again." << endl;
        }
        cout << "PROMPT: Continue to update ? (y/n): ";
        cin >> input;
        if (input == "y") {
            // Continue to update
        }
        else {
            // Break out the update loop
            break;
        }
	}


	return;
}