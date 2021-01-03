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
		cout << "-----------------* Add a new customer *-----------------" << endl;
		Customer *c = customerCreateMenu();
		c->details();
		customerList.addCustomer(c);
		customerList.printAllCustomer();
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
		// Implemented validation. Still need further testing
		cin >> inputArray[0];
		if (validateCustomerID(inputArray[0]))
			break;
	}

	// While loop is implemented to validate user's input before moving to next field.
	while (true) {
		cout << "2. Enter customer name: ";
		// Implemented validation. Still need further testing
		cin >> inputArray[1];
		if (validateCustomerName(inputArray[1]))
			break;
	}

	// While loop is implemented to validate user's input before moving to next field.
	while (true) {
		cout << "3. Enter customer address: ";
		// Implemented validation. Still need further testing
		cin >> inputArray[2];
		if (true)
			break;
	}

	// While loop is implemented to validate user's input before moving to next field.
	while (true) {
		cout << "4. Enter customer phone number: ";
		// Implemented validation. Still need further testing
		cin >> inputArray[3];
		if (true)
			break;
	}

	// While loop is implemented to validate user's input before moving to next field.
	while (true) {
		cout << "5. Enter customer type: ";
		cin >> inputArray[4];
		if (true)
			break;
	}
	
	Customer *c;

	if (inputArray[4] == "Guest") {
		c = new GuestAccount(inputArray[0], inputArray[1], inputArray[2], inputArray[3], 0);
	}
	else if (inputArray[4] == "Regular") {
		c = new RegularAccount(inputArray[0], inputArray[1], inputArray[2], inputArray[3], 0);
	}
	else {
		c = new VipAccount(inputArray[0], inputArray[1], inputArray[2], inputArray[3], 0);
	}
	delete[] inputArray;
	return c;
}
