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
        int temp2 = 0;
        while (getline(myfile, s))  // same as: while (getline( myfile, line ).good())
        {
			string listtemp[10];
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

                temp2++;
            }
			int numberOfRentals = stoi(listtemp[4]);
			string *rentalList = new string[numberOfRentals];

			if (numberOfRentals != 0) {
				for (int j = 0; j < numberOfRentals; j++) {
					getline(myfile, s);
					rentalList[j] = s;
					cout << rentalList[j] << endl;
				}
			}

			if (listtemp[5] == "Guest") {
				GuestAccount *c = new GuestAccount(listtemp[0], listtemp[1], listtemp[2], listtemp[3]);
				customerList.addCustomer(c);
			}
			else if (listtemp[5] == "Regular") {
				RegularAccount *c = new RegularAccount(listtemp[0], listtemp[1], listtemp[2], listtemp[3]);
				customerList.addCustomer(c);
			}
			else {
				VipAccount *c = new VipAccount(listtemp[0], listtemp[1], listtemp[2], listtemp[3]);
				customerList.addCustomer(c);
			}

			delete[] rentalList;

        }
        myfile.close();
	}
}
