#include "Menu.h"
#include <iostream>
#include <string>
#include "ValidateItemInput.h"
#include "ValidateCustomerInput.h"
#include "ItemMenu.h"
#include "LinkedItem.h"
#include "CustomerMenu.h"
#include "LinkedCustomer.h"
#include <fstream>

using namespace std;

void printByType(LinkedCustomer customerList) {
	LinkedCustomer guestList;
	LinkedCustomer vipList;
	LinkedCustomer regularList;

	CustomerNode *thisTemp;
	thisTemp = customerList.getHead();
	while (thisTemp != NULL) {
		if (thisTemp->data->getType() == "Guest") {
			guestList.addCustomer(thisTemp->data);
		}
		else if (thisTemp->data->getType() == "Regular") {
			regularList.addCustomer(thisTemp->data);
		}
		else if (thisTemp->data->getType() == "VIP") {
			vipList.addCustomer(thisTemp->data);
		}
		thisTemp = thisTemp->next;
	}
	cout << "-------------------* Guest Customer *-------------------" << endl;
	guestList.printAllCustomer();
	cout << "------------------* Regular Customer *------------------" << endl;
	regularList.printAllCustomer();
	cout << "-------------------* V.I.P Customer *-------------------" << endl;
	vipList.printAllCustomer();

}

void mainMenu(LinkedItem &itemList, LinkedCustomer &customerList) {


	while (true) {

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
			itemMenu(itemList, customerList);
		}
		else if (input == "2") {
			customerMenu(itemList, customerList);
		}
		else if (input == "3") {
			cout << "Option 3" << endl;
		}
		else if (input == "4") {
			cout << "------------------* Rent Item *-------------------" << endl;
			cout << "| 1. By ID                                       |" << endl;
			cout << "| 2. By name                                     |" << endl;
			cout << "| 3. Back                                        |" << endl;
			cout << "--------------------------------------------------" << endl;
			cout << "PROMPT: Choose an option to search the customer want to rent: ";

			cin >> input;
			cout << endl;
			cout << "--------------------------------------------------" << endl;
			string key;
			string idCustomer;
			// Search customer by ID
			if (input == "1") {
				cout << "PROMPT: Please enter the customer's ID: ";
				cin.ignore();
				getline(cin, idCustomer);
				CustomerNode* cus = customerList.searchCustomerByID(idCustomer);
				if (cus != NULL) {
					cus->data->details(); // Show customer details
					// Find item
					cout << "------------------* Rent Item *-------------------" << endl;
					cout << "| Rent an item                                   |" << endl;
					cout << "| 1. By ID                                       |" << endl;
					cout << "| 2. By title                                    |" << endl;
					cout << "--------------------------------------------------" << endl;
					cout << "PROMPT: Choose an option: ";

					cin >> input;
					// Find item by ID
					if (input == "1") {
						cout << "PROMPT: Enter item's ID: ";
						cin.ignore();
						getline(cin, key);
						bool isValidateItem = validateItemID(key);
						if (isValidateItem) {
							ItemElement* item = itemList.searchItemByID(key);
							if (item != NULL) {
								int isAvailable = item->data->getNumberOfCopies();
								if (isAvailable != 0) {
									item->data->renting();
									cus->data->rentItem(item->data->getId());
								}
								else {
									cout << "ERROR: Rental status is not available" << endl;
								}
							}
							else {
								cout << "ERROR: Couldn't find this ID in Item's list" << endl;
							}
						}

					}
					// Find item by name
					else if (input == "2") {
						cout << "PROMPT: Please enter item's title: ";
						cin.ignore();
						getline(cin, key);
						bool isValidateItem = validateTitle(key);
						if (isValidateItem) {
							LinkedItem foundList = itemList.searchItemByTitle(key);

							if (foundList.getHead() != NULL) {
								// Case 1: Found more than 1 customer with matching name
								if (foundList.getHead()->next != NULL) {
									foundList.printItem();
									while (true) {
										cout << "PROMPT: Found more than 1 item with matching title.\nEnter item ID to proceed: ";
										cin >> input; // Get the customer ID
										if (validateItemID(input)) {
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
									int isAvailable = item->data->getNumberOfCopies();
									if (isAvailable != 0) {
										item->data->renting();
										cus->data->rentItem(item->data->getId());
									}
									else {
										cout << "FAIL: " << item->data->getTitle() << " is not available." << endl;
									}
								}
								else {
									cout << "ERROR: Item not found." << endl;
								}

							}
							else {
								cout << "ERROR: Item not found." << endl;
							}
						}

					}
					else {
						cout << "ERROR: Invalid input." << endl;
					}
				}
				else {
					cout << "ERROR: Customer not found." << endl;
				}
			}
			// Search customer by name
			else if (input == "2") {
				cin.ignore();
				while (true) {
					cout << "PROMPT: Please enter the customer's ID: ";
					getline(cin, input);
					// Check title format
					if (validateCustomerName(input))
						break;
				}
				// Find item through the list here
				LinkedCustomer foundList = customerList.searchCustomerByName(input);
				// If-else case: If item found, show item's detail. If item not found, print error message then back to item menu.
				if (foundList.getHead() != NULL) {
					// Case 1: Found more than 1 customer with matching name
					if (foundList.getHead()->next != NULL) {
						foundList.printAllCustomer();
						while (true) {
							cout << "PROMPT: Found more than 1 customer with matching name.\nPROMPT: Enter customer ID to proceed: ";
							cin >> input; // Get the customer ID
							if (validateCustomerID(input)) {
								break;
							}
						}

					}
					else {
						// Case 2: Found only 1 customer with matching name. The input will be customer ID in the Head of the list.
						input = foundList.getHead()->data->getId(); // Get the customer ID
					}

					CustomerNode *foundCustomer = customerList.searchCustomerByID(input);

					if (foundCustomer != NULL) {
						foundCustomer->data->details();

						cout << "------------------* Rent Item *-------------------" << endl;
						cout << "| Rent an item                                   |" << endl;
						cout << "| 1. By ID                                       |" << endl;
						cout << "| 2. By title                                    |" << endl;
						cout << "--------------------------------------------------" << endl;
						cout << "PROMPT: Choose an option: ";

						cin >> input;
						if (input == "1") {
							cout << "PROMPT: Enter item's ID: ";
							cin.ignore();
							getline(cin, key);
							bool isValidateItem = validateItemID(key);
							if (isValidateItem) {
								ItemElement* item = itemList.searchItemByID(key);
								if (item != NULL) {
									int isAvailable = item->data->getNumberOfCopies();
									if (isAvailable != 0) {
										item->data->renting();
										foundCustomer->data->rentItem(item->data->getId());
									}
									else {
										cout << "ERROR: Rental status is not available" << endl;
									}
								}
								else {
									cout << "ERROR: Couldn't find this ID in Item's list" << endl;
								}
							}

						}
						else if (input == "2") {
							cout << "PROMPT: Please enter item's title: ";
							cin.ignore();
							getline(cin, key);
							bool isValidateItem = validateTitle(key);
							if (isValidateItem) {
								LinkedItem foundList = itemList.searchItemByTitle(key);

								if (foundList.getHead() != NULL) {
									// Case 1: Found more than 1 customer with matching name
									if (foundList.getHead()->next != NULL) {
										foundList.printItem();
										while (true) {
											cout << "PROMPT: Found more than 1 item with matching title.\nEnter item ID to proceed: ";
											cin >> input; // Get the customer ID
											if (validateItemID(input)) {
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
										int isAvailable = item->data->getNumberOfCopies();
										if (isAvailable != 0) {
											item->data->renting();
											foundCustomer->data->rentItem(item->data->getId());
										}
										else {
											cout << "FAIL: " << item->data->getTitle() << " is not available." << endl;
										}
									}
									else {
										cout << "ERROR: Item not found." << endl;
									}

								}
								else {
									cout << "ERROR: Item not found." << endl;
								}
							}

						}
						else {
							cout << "ERROR: Invalid input." << endl;
						}
					}
					else {
						cout << "ERROR: Customer not found." << endl;
					}

				}
			}
			else if (input == "3") {

			}

			//itemList.Output(&itemList);
			//customerList.Output(&customerList);
		}
		else if (input == "5") {
			cout << "-----------------* Return items *------------------" << endl;
			cout << "| Please enter ID Customer then choose the option |" << endl;
			cout << "| 1. Return by ID                                 |" << endl;
			cout << "| 2. Return by Title                              |" << endl;
			cout << "---------------------------------------------------" << endl;
			string key;
			string idCustomer;
			cout << "| Please enter ID Customer : " << endl;
			cin.ignore();
			getline(cin, idCustomer);
			CustomerNode* cus = customerList.searchCustomerByID(idCustomer);
			if (cus != NULL) {
				cout << "List of Rentals :  " << endl;
				cus->data->showRentalList();
				cout << "PROMPT: Choose an option: ";
				cin >> input;
				if (input == "1") {
					cout << "| Please enter ID : " << endl;
					cin.ignore();
					getline(cin, key);
					bool isValidateItem = validateItemID(key);
					if (isValidateItem) {
						bool isHaveThisId = cus->data->getRentalList()->isListHaveId(key);
						if (isHaveThisId) {
							itemList.IncreaseNumberOfCopies(key);
							cus->data->returnItem(key);
						}
						else {
							cout << "Couldn't find this Item's Id in Rentals list" << endl;
						}
					}
				}
				//else if (input == "2") {
				//	cout << "| Please enter Title : " << endl;
				//	cin.ignore();
				//	getline(cin, key);
				//	bool isValidateItem = validateTitle(key);
				//	if (isValidateItem) {
				//		ItemElement* temp = itemList.searchItemByTitle(key);
				//		if (temp != NULL) {
				//			bool isHaveThisId = cus->data->getRentalList()->isListHaveId(temp->data->getId());
				//			if (isHaveThisId) {
				//				itemList.IncreaseNumberOfCopies(temp->data->getId());
				//				cus->data->returnItem(temp->data->getId());
				//			}
				//			else {
				//				cout << "Couldn't find this Item's Id in Rentals list" << endl;
				//			}
				//		}
				//		else {
				//			cout << "Couldn't find this Item's Id in Rentals list" << endl;
				//		}
				//	}

				//}
				else {
					cout << "ERROR: Invalid input." << endl;
				}
			}
			else {
				cout << "ERROR: Couldn't find this ID in customer's list" << endl;
			}
			//itemList.Output(&itemList);
			//customerList.Output(&customerList);
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
			else {
				cout << "ERROR: Invalid input." << endl;
			}
		}
		else if (input == "7") {
			cout << "Option 7" << endl;
			// Display out of stock
			itemList.printOutOfStockItem();
		}
		else if (input == "8") {
            cout << "---------------* Display all customers *---------------" << endl;
            cout << "| 1. sorted by ID                                     |" << endl;
            cout << "| 2. sorted by Name                                   |" << endl;
            cout << "-------------------------------------------------------" << endl;
            cout << "PROMPT: Choose an option: ";
            cin >> input;
            if (input == "1") {
                LinkedCustomer tempCustomerList(customerList);
                tempCustomerList.sortedByID();
                tempCustomerList.printAllCustomer();
            }
            else if (input == "2") {
                LinkedCustomer tempCustomerList(customerList);
                tempCustomerList.sortedByName();
                tempCustomerList.printAllCustomer();
            }
            else {
                cout << "ERROR: Invalid input." << endl;
            }
		}
		else if (input == "9") {
			printByType(customerList);
		}
		else if (input == "Exit") {
			closeProgram(itemList, customerList);
		}
		else {
			cout << "Prompt: Invalid input" << endl;
		}
	}
}

void closeProgram(LinkedItem &itemList, LinkedCustomer &customerList) {
	// Save file 
	ofstream itemFile;
	ofstream customerFile;

	itemFile.open("items.txt");
	customerFile.open("customers.txt");


	if (itemFile.fail() || customerFile.fail()) {
		cout << "Could not open file" << endl;
		return;
	}

	ItemElement *itemElement = itemList.getHead();
	CustomerNode *customerNode = customerList.getHead();
	while (itemElement != NULL) {
		itemFile << itemElement->data->getId() << ",";
		itemFile << itemElement->data->getTitle() << ",";
		itemFile << itemElement->data->getRentalType() << ",";
		itemFile << itemElement->data->getLoanType() << ",";
		itemFile << itemElement->data->getNumberOfCopies() << ",";
		itemFile << itemElement->data->getRentalFee();
		if (itemElement->data->getRentalType() != "Game") {
			itemFile <<  "," << itemElement->data->getGenre();
		}
		itemFile << endl;
		itemElement = itemElement->next;
	}

	while (customerNode != NULL) {
	    customerFile << customerNode->data->getId() << ",";
	    customerFile << customerNode->data->getName() << ",";
	    customerFile << customerNode->data->getAddress() << ",";
	    customerFile << customerNode->data->getPhoneNumber() << ",";
	    customerFile << customerNode->data->getNumberOfRental() << ",";
	    customerFile << customerNode->data->getType();
	    LinkedRentalList *rentalList = customerNode->data->getRentalList();
	    RentalListNode *item = rentalList->getHead();

	    while (item != NULL) {
	        customerFile << endl;
	        customerFile << item->getItem();
	        item = item->getNext();
	    }

	    // If not a last element then add new line so if it is a last element, we will not at new empty line to the file
	    if (customerNode->next != NULL) {
	        customerFile << endl;
	    }

	    customerNode = customerNode->next;
	}
	customerFile.close();

	itemFile.close();


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