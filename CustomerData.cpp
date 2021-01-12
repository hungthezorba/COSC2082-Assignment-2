#include<iostream>
#include<fstream>
#include <string>
#include "CustomerData.h"
#include "Customer.h"
#include "GuestAccount.h"
#include "RegularAccount.h"
#include "VipAccount.h"
#include "ValidateItemInput.h"
#include "ValidateCustomerInput.h"

void CustomerData(LinkedCustomer &customerList, string fileName){
    string s;
    int temp3 = 0;
    ifstream myfile(fileName);
    if (myfile)
    {
		// Initialize pointer to a customer
		Customer *c = NULL;
		LinkedRentalList *list;
		int linePos = 0; // Track the line number
		int checkRentalNumber; // Check if the number of rental is matching with list of rentals
        while (getline(myfile, s))  // same as: while (getline( myfile, line ).good())
        {
			linePos++;
            if (s[0] == 'C') {
				checkRentalNumber = 0;
				// Customer infomation in txt file will be store in the string array
				string listDataTemp[6];
				// Delimeter to find the comma
                string delimiter = ",";
                size_t pos = 0;
                string token;
                int temp = 0;
				// If comma still exist, continue looping
                while ((pos = s.find(delimiter)) != string::npos) {
                    token = s.substr(0, pos);
					if (token == "") // Check if there is any missing information
						listDataTemp[temp] = "N/A";
					else
						listDataTemp[temp] = token;
                    s.erase(0, pos + delimiter.length());
                    temp++;
                }
				listDataTemp[temp] = s;

				// Validate cusomer information format in each column

				while (true) {
					if (!validateCustomerID(listDataTemp[0], "readFile")) {
						cout << "WARNING: Customer with ID " << listDataTemp[0] <<" does not contain correct value in 'ID' at line "<< linePos << endl;
						cout << "The customer will not be recorded. Please check the database file again." << endl;
						break;
					}

					if (!validateCustomerName(listDataTemp[1], "readFile")) {
						cout << "WARNING: Customer with ID " << listDataTemp[0] <<" does not contain correct value in 'name' at line " << linePos << endl;
						cout << "The customer will not be recorded. Please check the database file again." << endl;
						break;

					}

					if (!validateCustomerAddress(listDataTemp[2], "readFile")) {
						cout << "WARNING: Customer with ID " << listDataTemp[0] << " does not contain correct value in 'address' at line " << linePos << endl;
						cout << "The customer will not be recorded. Please check the database file again." << endl;
						break;
					}

					if (!validateCustomerPhoneNumber(listDataTemp[3], "readFile")) {
						cout << "WARNING: Customer with ID " << listDataTemp[0] << " does not contain correct value in 'phone number' at line " << linePos << endl;
						cout << "The customer will not be recorded. Please check the database file again." << endl;
						break;
					}
					// Using validateNumberOfCopies function because both format for the field is the same(only contains digit)
					if (!validateCustomerNumberOfRental(listDataTemp[4], "readFile")) {
						cout << "WARNING: Customer with ID " << listDataTemp[0] << " does not contain correct value in 'number of rental' at line " << linePos << endl;
						cout << "The customer will not be recorded. Please check the database file again." << endl;
						break;
					}

					if (!validateCustomerType(listDataTemp[5], "readFile")) {
						cout << "WARNING: Customer with ID " << listDataTemp[0] << " does not contain correct value in 'type' at line " << linePos << endl;
						cout << "The customer will not be recorded. Please check the database file again." << endl;
						break;
					}
					// Finish validating customer information format

					// If passing all the validation, a customer object will be created and add to the customer list in the program
					if (listDataTemp[5] == "Guest") {
						c = new GuestAccount(listDataTemp[0], listDataTemp[1], listDataTemp[2], listDataTemp[3], stoi(listDataTemp[4]));
					}
					else if (listDataTemp[5] == "Regular") {
						c = new RegularAccount(listDataTemp[0], listDataTemp[1], listDataTemp[2], listDataTemp[3], stoi(listDataTemp[4]));
					}
					else {
						c = new VipAccount(listDataTemp[0], listDataTemp[1], listDataTemp[2], listDataTemp[3], stoi(listDataTemp[4]));
					}
					list = c->getRentalList();
					customerList.addCustomer(c);
					break;
				}
			}

			else if (s[0] == 'I') {
				if (c != NULL) {
					if (checkRentalNumber != c->getNumberOfRental()) {
						list->addItem(s);
						checkRentalNumber++;
					}
					// If rental number not match (number of rental is lower than the list of rentals)
					else {
						cout << "ERROR: Customer with ID " << c->getId() << " does not have matching number of rental with list of rentals." << endl;
						cout << "PROMPT: Only " << c->getNumberOfRental() << " items recorded in the running program " << "for customer with ID " << c->getId() << "." << endl;
						cout << "PROMPT: Please check the database files." << endl;
					}
				}
				// Only add the item to customer'rental list up to his/her number of rental.

			}
			
        }
        myfile.close();
	}
}
