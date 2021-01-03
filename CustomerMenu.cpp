#include "CustomerMenu.h"
#include "GuestAccount.h"
#include "RegularAccount.h"
#include "VipAccount.h"
#include "ValidateCustomerInput.h"


void customerMenu(LinkedItem &itemList, LinkedCustomer &customerList) {
	cout << "---------------------* Customer Menu *--------------------" << endl;
	cout << "| 1. Add a new customer                                  |" << endl;
	cout << "| 2. Delete a customer                                   |" << endl;
	cout << "| 3. Update a customer                                   |" << endl;
	cout << "| 4. Search a customer                                   |" << endl;
	cout << "| 5. Back                                                |" << endl;
	cout << "| Exit.                                                  |" << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << "Choose an option: ";
	string input;
	cin >> input;

	// Option 1
	if (input == "1") {
		cout << "------------------* Add a new customer *------------------" << endl;
		Customer *c = customerCreateMenu();
		cout << "----------------------------------------------------------" << endl;
		cout << "-----------------* Add a new customer *-------------------" << endl;
		c->details();
		cout << "----------------------------------------------------------" << endl;
		cout << "PROPMP: Customer will be added to database. Type 'yes' to confirm: ";
		cin >> input;
		if (input == "yes") {
			customerList.addCustomer(c);
			cout << "SUCCESS: Customer added." << endl;
		}
		else {
			cout << "FAIL: No customer added." << endl;
		}
	}
	// Option 2
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
		mainMenu(itemList, customerList);
	}
	else if (input == "Exit") {
		closeProgram(itemList);
	}
	else {
		cout << "ERROR: Invalid input. Please enter again." << endl;
	}
	
	// Show customer menu again after complete any option
	customerMenu(itemList, customerList);
}

Customer *customerCreateMenu() {
	string *inputArray = new string[5];

	// While loop is implemented to validate user's input before moving to next field.
	while (true) {
		cout << "1. Enter customer ID(Cxxx): ";
		cin >> inputArray[0];
		if (validateCustomerID(inputArray[0]))
			break;
	}

	cin.ignore();
	// While loop is implemented to validate user's input before moving to next field.
	while (true) {
		cout << "2. Enter customer name: ";
		// ignore the newline character
		getline(cin, inputArray[1]);
		if (validateCustomerName(inputArray[1]))
			break;
	}
	// While loop is implemented to validate user's input before moving to next field.
	while (true) {
		cout << "3. Enter customer address: ";
		// ignore the newline character
		getline(cin, inputArray[2]);
		if (validateCustomerAddress(inputArray[2]))
			break;
	}

	// While loop is implemented to validate user's input before moving to next field.
	while (true) {
		cout << "4. Enter customer phone number(10 digits): ";
		// Implemented validation. Still need further testing
		cin >> inputArray[3];
		if (validateCustomerPhoneNumber(inputArray[3]))
			break;
	}

	// While loop is implemented to validate user's input before moving to next field.
	while (true) {
		cout << "5. Enter customer type(Guest, Regular, VIP): ";
		cin >> inputArray[4];
		if (validateCustomerType(inputArray[4]))
			break;
	}
	
	Customer *c;

	// With each case of customer type will create each correctly object class.
	if (inputArray[4] == "Guest") {
		c = new GuestAccount(inputArray[0], inputArray[1], inputArray[2], inputArray[3], 0);
	}
	else if (inputArray[4] == "Regular") {
		c = new RegularAccount(inputArray[0], inputArray[1], inputArray[2], inputArray[3], 0);
	}
	else {
		c = new VipAccount(inputArray[0], inputArray[1], inputArray[2], inputArray[3], 0);
	}
	// Free up space in heap
	delete[] inputArray;
	return c;
}
