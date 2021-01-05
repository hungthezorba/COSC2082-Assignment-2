#include "Menu.h"
#include <iostream>
#include <string>
#include "ValidateItemInput.h"
#include "ItemMenu.h"
#include "LinkedItem.h"
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
		//        cout<< "come here"<<endl;
		if (thisTemp->data->getTypeCustomer() == "Guest") {
			guestList.addCustomer(thisTemp->data);
		}
		else if (thisTemp->data->getTypeCustomer() == "Regular") {
			regularList.addCustomer(thisTemp->data);
		}
		else if (thisTemp->data->getTypeCustomer() == "Vip") {
			vipList.addCustomer(thisTemp->data);
		}
		thisTemp = thisTemp->next;
	}

	cout << "-------------------* Guest Customer *-------------------" << endl;
	guestList.printAllCustomer();
	cout << "--------------------------------------------------------" << endl;
	cout << "------------------* Regular Customer *------------------" << endl;
	regularList.printAllCustomer();
	cout << "--------------------------------------------------------" << endl;
	cout << "-------------------* V.I.P Customer *-------------------" << endl;
	vipList.printAllCustomer();
	cout << "--------------------------------------------------------" << endl;

}

void mainMenu(LinkedItem &itemList, LinkedCustomer &customerList) {
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
		else {
			cout << "ERROR: Invalid input." << endl;
		}
		mainMenu(itemList, customerList);
	}
	else if (input == "7") {
		cout << "Option 7" << endl;
		// Display out of stock
		itemList.printOutOfStockItem();
		mainMenu(itemList, customerList);
	}
	else if (input == "8") {
		cout << "Option 8" << endl;
	}
	else if (input == "9") {
		printByType(customerList);
	}
	else if (input == "Exit") {
		closeProgram(itemList);
	}
	else {
		cout << "Prompt: Invalid input" << endl;
		mainMenu(itemList, customerList);
	}
}

void closeProgram(LinkedItem &itemList) {
	// Save file 
	ofstream itemFile;
	fstream customerFile;

	itemFile.open("items.txt");
	if (itemFile.fail()) {
		cout << "Could not open file" << endl;
		return;
	}

	ItemElement *itemElement = itemList.getHead();
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