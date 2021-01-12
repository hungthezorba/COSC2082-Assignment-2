#include<iostream>
#include<fstream>
#include <string>
#include "ItemData.h"
#include "Game.h"
#include "DVD.h"
#include "Record.h"
#include "ValidateItemInput.h"


using namespace std;

void ItemData(LinkedItem &itemList) {
    string sitem;
    int linePos = 0;
    int temp3item = 0;
	ifstream itemfile;
	itemfile.open("items.txt");
    if (itemfile)
    {
        while (getline(itemfile, sitem))  // same as: while (getline( myfile, line ).good())
        {
            linePos++;
			string listtemp[10];
            if (sitem[0] == 'I') {

				string listtemp[7] = { "NA", "NA", "NA", "NA", "NA", "NA", "NA" };
				string delimiter = ",";
                int pos = 0;
                string token;
                int temp = 0;
                while ((pos = sitem.find(delimiter)) != string::npos) {
                    token = sitem.substr(0, pos);
                    listtemp[temp] = token;
                    sitem.erase(0, pos + delimiter.length());
                    temp++;
                }
                Item *i;
                listtemp[temp] = sitem;
				// begin the validate for the this case
				// validate the id first
                if (!validateItemID(listtemp[0],"readFile")) {
                    cout<< "WARNING: Item may not have appropriate ID at line "<< linePos << endl;
					cout << "The item will not be recorded. Please check the database again." << endl;
                }
                else if (!validateTitle(listtemp[1],"readFile")){
                    cout<< "WARNING: Item may not have appropriate title at line "<< linePos << endl;
					cout << "The item will not be recorded. Please check the database again." << endl;
                }
                else if (!validateRentalType(listtemp[2],"readFile")){
                    cout<< "WARNING: Item may not have appropriate type at line "<< linePos << endl;
					cout << "The item will not be recorded. Please check the database again." << endl;
				}
                else if(!validateLoanType(listtemp[3],"readFile")){
                    cout<< "WARNING: Item may not have appropriate loan period at line "<< linePos << endl;
					cout << "The item will not be recorded. Please check the database again." << endl;
				}
                else if (!validateNumberOfCopies(listtemp[4],"readFile")){
                    cout<< "WARNING: Item may not have appropriate number of copies at line "<< linePos << endl;
					cout << "The item will not be recorded. Please check the database again." << endl;
				}
                else if (!validateRentalFee(listtemp[5],"readFile")){
                    cout<< "WARNING: Item may not have appropriate rental fee at line "<< linePos << endl;
					cout << "The item will not be recorded. Please check the database again." << endl;
				}
                else{

                    if (listtemp[2] == "Game") {
						i = new Game(listtemp[0], listtemp[1], listtemp[2], listtemp[3], stoi(listtemp[4]), stod(listtemp[5]));
						itemList.addItem(i);
                    }
                    else if (listtemp[2] == "DVD") { 
                        if (!validateGenre(listtemp[6],"readFile")){
                            cout << "WARNING: The item may not have appropriate genres at line "<< linePos << endl;
							cout << "The item will not be recorded. Please check the database again." << endl;
						}
                        else {
                            i = new DVD(listtemp[0], listtemp[1], listtemp[2], listtemp[3], stoi(listtemp[4]), stod(listtemp[5]), listtemp[6]);
                            itemList.addItem(i);
                        }

                    }
                    else {
                        if (!validateGenre(listtemp[6],"readFile")){
                            cout << "WARNING: The item may not have appropriate genres at line "<< linePos << endl;
							cout << "The item will not be recorded. Please check the database again." << endl;
						}
                        else {
                            i = new Record(listtemp[0], listtemp[1], listtemp[2], listtemp[3], stoi(listtemp[4]), stod(listtemp[5]), listtemp[6]);
                            itemList.addItem(i);
                        }

                    }
                }




            } else {
                cout<< "WARNING: The item may not have appropriate ID at line "<< linePos << endl;
				cout << "The item will not be recorded. Please check the database again." << endl;
			}
        }
        itemfile.close();
    }
}
