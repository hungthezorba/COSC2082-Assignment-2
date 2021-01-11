#include<iostream>
#include<fstream>
#include <string>
#include "CustomerData.h"
#include "Customer.h"
#include "GuestAccount.h"
#include "RegularAccount.h"
#include "VipAccount.h"

void CustomerData(LinkedCustomer &customerList){
    string s;
    int temp3 = 0;
    ifstream myfile("customers.txt");
    if (myfile)
    {
        while (getline(myfile, s))  // same as: while (getline( myfile, line ).good())
        {
			string listtemp[10];

			// Initialize pointer to a customer
			Customer *c; 
            if (s[0] == 'C') {
                temp3 = 0;
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
					customerList.addCustomer(c);
				}
				else if (listtemp[5] == "Regular") {
					c = new RegularAccount(listtemp[0], listtemp[1], listtemp[2], listtemp[3], stoi(listtemp[4]));
					customerList.addCustomer(c);
				}
				else {
					c = new VipAccount(listtemp[0], listtemp[1], listtemp[2], listtemp[3], stoi(listtemp[4]));
					customerList.addCustomer(c);
				}
				// Get the number of rental in order to use for 'for-loop' to add correctly number of item.
				int numberOfRentals = stoi(listtemp[4]);
				LinkedRentalList *list = c->getRentalList();
				// Looping to add item to rental list of the customer.
				for (int j = 0; j < numberOfRentals; j++) {
					// Add item id to customer rental list
					getline(myfile, s);
					list->addItem(s);

				}

            }
			else {
				cout << "ERROR: Number of rental in a customer not matching with the list of rentals" << endl;
				exit(0);
			}
        }
        myfile.close();
	}
}
