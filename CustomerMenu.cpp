#include "CustomerMenu.h"
#include "GuestAccount.h"
#include "RegularAccount.h"
#include "VipAccount.h"
#include "ValidateCustomerInput.h"


void customerMenu(LinkedItem &itemList, LinkedCustomer &customerList) {

	while (true) {


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

		// Add a new customer menu
		if (input == "1") {
			cout << "------------------* Add a new customer *------------------" << endl;
			Customer *c = customerCreateMenu();
			cout << "----------------------------------------------------------" << endl;
			cout << "------------------* Add a new customer *------------------" << endl;
			c->details();
			cout << "----------------------------------------------------------" << endl;
			cout << "PROMPT: Customer will be added to database. Type 'yes' to confirm: ";
			cin >> input;
			if (input == "yes") {
				customerList.addCustomer(c);
				cout << "SUCCESS: Customer added." << endl;
			}
			else {
				cout << "FAIL: No customer added." << endl;
			}
		}

		// Delete customer menu 
		else if (input == "2") {
			while (true) {
				cout << "-------------------* Delete Customer *-------------------" << endl;
				cout << "|1. By ID                                               |" << endl;
				cout << "|2. By name                                             |" << endl;
				cout << "|3. Back                                                |" << endl;
				cout << "---------------------------------------------------------" << endl;
				cout << "PROMPT: Enter an option: ";
				cin >> input;

				if (input == "1") {
					while (true) {
						cout << "PROMPT: Enter customer's ID want to delete: ";
						cin >> input;
						// Check ID format
						if (validateCustomerID(input))
							break;
					}
					// Find item through the list here
					CustomerNode *foundCustomer = customerList.searchCustomerByID(input);
					// If-else case: If item found, show item's detail. If item not found, print error message then back to item menu.
					if (foundCustomer != NULL) {
                        cout << "--------------------------------------" << endl;
					    foundCustomer->data->details();
                        cout << "Currently renting: " << endl;
                        foundCustomer->data->showRentalList();
                        cout << "--------------------------------------" << endl;

                        // Not allow to delete if customer still have rent item
                        if (foundCustomer->data->getNumberOfRental() != 0) {
                            cout << "ERROR: Customer must return all the items" << endl;
                        }

                        else {
                            // Delete is a dangerous action. So the program make it harder to delete an item. Just like Github.
                            cout
                                    << "PROMPT: Do you really want to delete the customer ? Type 'yes' to confirm action: ";
                            cin >> input;
                            if (input == "yes") {
                                customerList.deleteCustomer(foundCustomer->data->getId());
                                cout << "SUCCESS: Customer has been deleted." << endl;
                            } else
                                cout << "FAIL: No deletion has taken place. Return to item menu." << endl;
                        }
					}
					else {
						cout << "ERROR: Customer not found." << endl;
					}
				}
				else if (input == "2") {
				    cin.ignore();
					while (true) {
						cout << "PROMPT: Enter customer's name want to delete: ";
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
                            foundCustomer->data->showRentalList();

                            if (foundCustomer->data->getNumberOfRental() != 0) {
                                cout << "ERROR: Customer must return all the items" << endl;
                            }
                            else {
                                // Delete is a dangerous action. So the program make it harder to delete an item. Just like Github.
                                cout << "PROMPT: Do you really want to delete the customer ? Type 'yes' to confirm action: ";
                                cin >> input;
                                if (input == "yes") {
                                    customerList.deleteCustomer(foundCustomer->data->getId());
                                    cout << "SUCCESS: Customer has been deleted." << endl;
                                }
                                else
                                    cout << "FAIL: No deletion has taken place. Return to item menu." << endl;
                            }
                        }
                        else {
                            cout << "ERROR: Customer not found." << endl;
                        }

                    }
					else {
                        cout << "ERROR: Customer not found." << endl;
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

		// Update customer menu
		else if (input == "3") {

			while (true) {
				cout << "--------------------* Update Customer *--------------------" << endl;
				cout << "|1. By ID                                                 |" << endl;
				cout << "|2. By name                                               |" << endl;
				cout << "|3. Back                                                  |" << endl;
				cout << "-----------------------------------------------------------" << endl;
				cout << "PROMPT: Enter an option: ";
				cin >> input;

				if (input == "1") {
					cin.ignore();
					while (true) {
						cout << "PROMPT: Enter customer's ID want to update: ";
						getline(cin, input);
						if (validateCustomerID(input))
							break;
					}
					// Find item through the list here
					CustomerNode *customer = customerList.searchCustomerByID(input);
					// If-else case: If item found, show item's detail. If item not found, print error message then back to item menu.
					//
					if (customer != NULL) {
							// Call update function
							customerUpdateMenu(customer);
					}
					else {
						// Will implement input id again
						cout << "ERROR: Cusotmer not found." << endl;
					}
				}
				else if (input == "2") {
					cin.ignore();
					while (true) {
						cout << "PROMPT: Enter customer's name want to update: ";
						getline(cin, input);
						if (validateCustomerName(input))
							break;
					}
					// Find item through the list here
					LinkedCustomer foundList = customerList.searchCustomerByName(input);
					// If-else case: If customer found, show customer's detail. If customer not found, print error message then back to customer menu.
					//
					if (foundList.getHead() != NULL) {
						// Case 1: Found more than 1 customer with matching name
						if (foundList.getHead()->next != NULL) {
							foundList.printAllCustomer();
							while (true) {
								cout << "PROMPT: Found more than 1 customer with matching name.\nEnter customer ID to proceed: ";
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
						
						CustomerNode *customer = customerList.searchCustomerByID(input);
						
						if (customer != NULL) {
								// Call update function
								customerUpdateMenu(customer);
							
						}
						else {
							cout << "ERROR: Customer not found." << endl;
						}

					}
					else {
						cout << "ERROR: Customer not found." << endl;
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

		// Search customer menu
		else if (input == "4") {
			// Use while loop to let the user exit the option by their choice
			while (true) {
				cout << "-------------------* Search a customer *-------------------" << endl;
				cout << "|1. By ID                                                 |" << endl;
				cout << "|2. By name                                               |" << endl;
				cout << "|3. Back                                                  |" << endl;
				cout << "-----------------------------------------------------------" << endl;
				cout << "PROMPT: Enter an option: ";
				cin >> input;
				if (input == "1") {
					while (true) {
						cout << "PROMPT: Enter customer's ID want to search: ";
						cin >> input;
						if (validateCustomerID(input))
							break;
					}
					// Find item through the list here

					CustomerNode *c = customerList.searchCustomerByID(input);
					if (c != NULL) {
						c->data->details();
						cout << "Currently renting: " << endl;
						LinkedRentalList *list = c->data->getRentalList();
						list->showItem();
					}
					else {
						cout << "PROMPT: Cannot found the customer with specified ID." << endl;
					}
				}
				else if (input == "2") {
					cin.ignore();
					while (true) {
						cout << "PROMPT: Enter customer's name want to search: ";
						getline(cin, input);
						if (validateCustomerName(input))
							break;
					}

					// Find item through the list here
					LinkedCustomer foundList = customerList.searchCustomerByName(input);
					if (foundList.getHead() != NULL)
						foundList.printAllCustomer();
					else
						cout << "PROMPT: Cannot found the customer with specified name." << endl;
				}
				else if (input == "3") {
					break;
				}
				else {
					cout << "ERROR: Invalid input." << endl;
				}
				cout << "PROMPT: Continue to search ? (y/n): ";
				cin >> input;
				if (input == "y") {
					cout << endl; // Add space
					// Continue to update
				}
				else {
					cout << "-----------------------------------------------------------" << endl;
					cout << endl; // Add space
					// Break out the update loop
					break;
				}
			}

		}


		// Back to main menu
		else if (input == "5") {
			break;
		}

		// Close the program
		else if (input == "Exit") {
			closeProgram(itemList);
		}
		else {
			cout << "ERROR: Invalid input. Please enter again." << endl;
		}
		// Show customer menu again after complete any option
	}

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

void customerUpdateMenu(CustomerNode *customer) {
	string input;

	while (true) {
		cout << "----------------------* Update Customer *----------------------" << endl;
		customer->data->details();
		cout << "Select an option: ";
		cin >> input;

		if (input == "1") {
			cin.ignore();
			while (true) {
				cout << "Enter customer's name: ";
				// Name can contains spaces so need to use getline in this case
				getline(cin, input);
				if (validateCustomerName(input)) {
					customer->data->setName(input);
					break;
				}
			}
		}
		else if (input == "2") {
			cin.ignore();
			while (true) {
				cout << "Enter customer's address: ";
				// Address can contains spaces so need to use getline in this case
				getline(cin, input);
				if (validateCustomerAddress(input)) {
					customer->data->setAddress(input);
					break;
				}
			}
		}
		else if (input == "3") {
			while (true) {
				cout << "Enter customer's phone number(10 digits): ";
				cin >> input;
				if (validateCustomerPhoneNumber(input)) {
					customer->data->setPhoneNumber(input);
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
