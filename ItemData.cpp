#include<iostream>
#include<fstream>
#include <string>
#include "ItemData.h"
#include "Game.h"
#include "DVD.h"
#include "Record.h"

using namespace std;

void ItemData(LinkedItem &itemList) {
    string sitem;
    int temp3item = 0;
    ifstream itemfile("items.txt");
    if (itemfile)
    {
        int temp2 = 0;
        while (getline(itemfile, sitem))  // same as: while (getline( myfile, line ).good())
        {
            if (sitem[0] == 'I') {
                temp3item = 0;
                string listtemp[10];
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
                listtemp[temp] = sitem;
				if (listtemp[2] == "Game") {
					Game *i = new Game(listtemp[0], listtemp[1], listtemp[2], listtemp[3], stoi(listtemp[4]), stod(listtemp[5]));
					itemList.addItem(i);
				}
				else if (listtemp[2] == "DVD") {
					DVD *i = new DVD(listtemp[0], listtemp[1], listtemp[2], listtemp[3], stoi(listtemp[4]), stod(listtemp[5]), listtemp[6]);
					itemList.addItem(i);
				}
				else {
					Record *i = new Record(listtemp[0], listtemp[1], listtemp[2], listtemp[3], stoi(listtemp[4]), stod(listtemp[5]), listtemp[6]);
					itemList.addItem(i);
				}
                temp2++;
            }
        }
        itemfile.close();
    }
}
