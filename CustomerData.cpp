#include<iostream>
#include<fstream>
#include <string>
#include "CustomerData.h"
#include "Customer.h"
#include "GuestAccount.h"
#include "RegularAccount.h"
#include "VipAccount.h"
#include "ValidateItemInput.h"

void CustomerData(LinkedCustomer &customerList){
    string s;
    int temp3 = 0;
    ifstream myfile("customers.txt");
    if (myfile)
    {
		// Initialize pointer to a customer
		Customer *c;
		LinkedRentalList *list;
		int checkRentalNumber; // Check if the number of rental is matching with list of rentals
        while (getline(myfile, s))  // same as: while (getline( myfile, line ).good())
        {

            if (s[0] == 'C') {
				checkRentalNumber = 0;
				string listtemp[5];
                string delimiter = ",";
                size_t pos = 0;
                string token;
                int temp = 0;
                while ((pos = s.find(delimiter)) != string::npos) {
                    token = s.substr(0, pos);
                    listtemp[temp] = token;
                    s.erase(0, pos + delimiter.length());
                    temp++;
                }
                listtemp[temp] = s;
				
				if (listtemp[5] == "Guest") {
					c = new GuestAccount(listtemp[0], listtemp[1], listtemp[2], listtemp[3], stoi(listtemp[4]));
				}
				else if (listtemp[5] == "Regular") {
					c = new RegularAccount(listtemp[0], listtemp[1], listtemp[2], listtemp[3], stoi(listtemp[4]));
				}
				else {
					c = new VipAccount(listtemp[0], listtemp[1], listtemp[2], listtemp[3], stoi(listtemp[4]));
				}
				// Get the number of rental in order to use for 'for-loop' to add correctly number of item.
				list = c->getRentalList();
				customerList.addCustomer(c);

			}

			else if (s[0] == 'I') {
				// 
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
			
        }
        myfile.close();
	}
}
